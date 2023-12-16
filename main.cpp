#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void Permutations (int items[], int itemsLength) {
    vector<int> v;
    int count = 0;
    int summ = 1;
    for (int i = 0; i != itemsLength; ++i) {
        v.push_back(items[i]);
    }

    while (next_permutation(v.begin(), v.end()))
    {
        for(int j = 0; j < itemsLength; ++j){
            if (v[j] == (j+1)){
                count = 1;
            }
        }
        summ += count;
        count = 0;
    }
    cout << "answer = " << summ << endl;
}


int main() {
    int input = 0;
    cout << "amount of balls" << endl;
    while(!(cin >> input)){
        cout << "not a number" << endl;
    }

    if (input < 0){
        cout << "impossible" << endl;
        return 0;
    }

    const int sizeArray = input;
    int Array[sizeArray];
    for (int i = 0; i < sizeArray; ++i){
        Array[i] = i+1;
    }

    Permutations(Array, sizeArray);
    return 0;
}