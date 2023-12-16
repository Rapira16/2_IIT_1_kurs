#include <iostream>
#include <fstream>
#include <random>
#include <vector>


using namespace std;

int ichek(string x = "") {
    bool b, t = false;
    if (x.length() == 0) {
        t = true;
    }
    while (true) {
        if (t) {
            cin >> x;
        }
        b = true;
        if ((x[0] == '-') || (x[0] >= '0' && x[0] <= '9')) {
            for (int i = 1; i < x.length(); ++i) {
                if (not((x[i] >= '0' && x[i] <= '9'))) {
                    b = false;
                    break;
                }
            }
            try {
                if (b) {
                    return stoi(x);
                }
            }
            catch (out_of_range const &e) {
                cout << endl << "too big for integer" << endl;
            }
        }
        cout << "Wrong Value. Try again: " << endl;
        cin.clear();
        cin.ignore();
    }
}

int neighbor(vector<vector<int>> home, int y, int x) {
    int height = home.size();
    int width = home[0].size();
    int count = 0;
    int y_up = y - 1, y_right = y + 1;
    int x_left = x - 1, x_right = x + 1;

    if (home[y][x] > 0) {
        --count;
    }

    if (y == 0) {
        y_up = y;
    }
    if (x == 0) {
        x_left = x;
    }
    if (y == --height) {
        y_right = y;
    }
    if (x == --width) {
        x_right = x;
    }

    for (int i = y_up; i <= y_right; ++i) {
        for (int j = x_left; j <= x_right; ++j) {
            if (home[i][j] > 0) {
                ++count;
            }
        }
    }
    return count;
}

string show(vector<vector<int>> vect) {
    string s = "";
    int msize = vect.size();
    for (int i = 0; i < msize; ++i) {
        for (int j = 0; j < msize; ++j) {
            if (vect[i][j] < 10) {
                s += ' ';
            }
            if (vect[i][j] == 0) {
                s += "  ";
            } else {
                s += ' ' + to_string(vect[i][j]);
            }
        }
        s += "\n";
    }
    return s;
}

std::tuple<int, int, int> life() {
    cout << "Enter size of the world: ";
    int world_size = ichek();
    cout << "Enter amount of letters: ";
    int letters = ichek();
    cout << "Enter generations: ";
    int generations = ichek();

    if (world_size <= 0 || generations <= 0 || letters <= 0) {
        cout << "Wrong inputs" << endl;
        abort();
    }
    return make_tuple(world_size, letters, generations);
}

std::tuple<int, int, int, vector<vector<int>>, vector<vector<int>>> work_dat() {
    random_device rd;
    mt19937 gen(rd());

    int world_size, letters, generations;

    tie(world_size, letters, generations) = life();
    vector<vector<char>> home(world_size, vector<char>(world_size, 'A'));

    vector<vector<int>> past(world_size, vector<int>(world_size, 0));
    vector<vector<int>> future = past;

    char isBact = (char) (gen() % letters + 'A');
    char cur;

    ofstream file("work.dat");

    string isBactCh(1, isBact);

    string cs = "";

    for (int i = 0; i < world_size; ++i) {
        for (int j = 0; j < world_size; ++j) {
            cur = (char) (gen() % letters + 'A');
            home[i][j] = cur;

            cs = cur + ' ';
            cout << cs;
            file << cs;

            if (cur == isBact) {
                past[i][j] = 1;
            }
        }
        cout << endl;
        file << '\n';
    }
    file.close();
    return make_tuple(world_size, letters, generations, past, future);
}

void work_out(){
    int world_size, letters, generations;
    vector<vector<int>> past;
    vector<vector<int>> future;
    tie(world_size, letters, generations, past, future) = work_dat();

    ofstream file("work.out");

    string current_generation = show(past);
    cout << current_generation;
    file << current_generation;

    int current_bacteria, current_neighbor;
    for (int generation = 1; generation <= generations; ++generation) {
        for (int i = 0; i < world_size; ++i) {
            for (int j = 0; j < world_size; ++j) {
                current_bacteria = past[i][j];
                current_neighbor = neighbor(past, i, j);
                if (current_bacteria > 0) {
                    if (current_bacteria == 11 || current_neighbor > 3 || current_neighbor < 2) {
                        current_bacteria = 0;
                    } else {
                        ++current_bacteria;
                    }
                } else {
                    if (current_neighbor == 3) {
                        current_bacteria = 1;
                    }
                }
                future[i][j] = current_bacteria;
            }
        }
        std::string stuff(world_size, '_');

        current_generation = stuff + to_string(generation) + "\n";
        cout << current_generation;
        file << current_generation;

        current_generation = show(future);
        cout << current_generation;
        file << current_generation;
        past = future;
    }
    file.close();
}


int main() {
    work_out();
    return 0;
}