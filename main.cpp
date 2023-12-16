#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

void game_procces(vector<int> guesse_it){
    int input = 0;

    cout << "enter numbers until you win" << endl;


    bool win_lose = false;
    while(!(win_lose)) {
        string out = "";

        while (!(cin >> input)){
            cout << "not a number" << endl;
        }

        if (((input / 10000) != 0) || ((input/1000) == 0)){
            cout << "you entered number bigger than 4 digits or smaller" << endl;
            return;
        }

        string input_string = to_string(input);

        for (int i = 0; i < 4; ++i) {
            int element = (int)input_string[i] - 48;
            bool in_vec = (find(guesse_it.begin(), guesse_it.end(), element) != guesse_it.end());
            if (guesse_it[i] == element) {
                cout << "+";
                out += "+";
            }
            else if (in_vec){
                cout << "-";
                out += "-";
            } else {
                cout << " ";
                out += " ";
            }
        }
        if (out == "++++"){
            cout << "\nyou won";
            win_lose = true;
        }
        cout << endl;
    }
}

void make_number(){
    vector<int> vector_numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> out_numbers;
    srand(time(0));
    for (int i = 0; i < 4; ++i){
        int itr = rand() % vector_numbers.size();
        out_numbers.push_back(vector_numbers[itr]);
        vector_numbers.erase(vector_numbers.begin() + itr);
    }
    game_procces(out_numbers);
}



int main() {
    make_number();
    return 0;
}
