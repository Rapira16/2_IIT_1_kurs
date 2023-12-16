#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void check_train(vector<int> free_spaces){
    sort(free_spaces.begin(), free_spaces.end());
    vector<int> big_room;
    vector<int> small_room;
    for (int i = 0; i < size(free_spaces); ++i){
        if(free_spaces[i] <= 36){
            big_room.push_back(free_spaces[i]);
        } else if(free_spaces[i] > 36) {
            small_room.push_back(free_spaces[i]);
        }
    }

    if(size(small_room) < 4){
        cout << "no space" << endl;
    }

    if(size(big_room) < 2){
        cout << "no space" << endl;
    }

    for (int j = 0; j < (size(big_room) - 3); ++j){
        if (((big_room[j] % 4) == 1) && ((big_room[j+1] % 4) == 2) && ((big_room[j+2] % 4) == 3) && ((big_room[j+3] % 4) == 0)){
            cout << big_room[j] << " " << big_room[j+1] << " " << big_room[j+2] << " " << big_room[j+3] << " ";
        }
    }

    for (int k = 0; k < (size(small_room) - 1); ++k){
        if (((small_room[k] % 2) == 1) && ((small_room[k+1] % 2) == 0)){
            cout << small_room[k] << " " << small_room[k+1] << " ";
        }
    }
}


void input_people(int all_people){
    vector<int> arr;
    int free_place = 0;
    cout << "enter free spaces" << endl;
    for (int i = 0; i < all_people; ++i){
        while(!(cin >> free_place)){
            cout << "not a number";
        }
        if(free_place > 54){
            cout << "no such place" << endl;
            return;
        }
        arr.push_back(free_place);
    }
    check_train(arr);
}



int main() {
    cout << "enter amount of free places - " << endl;
    unsigned int n = 0;
    while(!(cin >> n)){
        cout << "not a number" << endl;
    }
    if (n > 54){
        cout << "to much" << endl;
        return 0;
    }

    if (n < 0){
        cout << "impossible to have negative amount of places" << endl;
        return 0;
    }
    input_people(n);
    return 0;
}
