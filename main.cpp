#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void count_seats(int all_seats, int people){
    vector<int> free_places;
    free_places.push_back(all_seats);
    int left = 0, right = 0;
    for(int i = 0; i < people; ++i){
        int maximum = *max_element(free_places.begin(), free_places.end());
        if ((maximum % 2) == 0){
            left = (maximum - 1)/2;
            right = ((maximum - 1)/2) + 1;
        } else {
            left = (maximum - 1)/2;
            right = (maximum - 1)/2;
        }
        vector<int>::iterator itr = std::find(free_places.begin(), free_places.end(), maximum);
        int buff = distance(free_places.begin(), itr);
        free_places.erase(free_places.begin() + buff);
        free_places.push_back(left);
        free_places.push_back(right);
    }
    cout << "on left " << left << '\n' << "on right " << right << endl;
}

int main() {
    int n = 0, k = 0;

    cout << "enter amount of seats" << endl;
    while(!(cin >> n)){
        cout << "not a number" << endl;
    }

    cout << "enter amount of people" << endl;
    while(!(cin >> k)){
        cout << "not a number" << endl;
    }

    if (k > n){
        cout << "not enough seats" << endl;
        return 0;
    }

    if ((k < 0) || (n < 0)){
        cout << "impossible to have negative numbers in this work" << endl;
    }

    count_seats(n, k);

    return 0;
}
