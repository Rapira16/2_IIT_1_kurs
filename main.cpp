#include <iostream>

using namespace std;

void make_spinners(int amount_of_blades){
    int amount_of_4 = amount_of_blades/4;
    int amount_of_3 = amount_of_blades/3;
    for (int i = 0; i <= amount_of_4; ++i){
        for (int j = 0; j <= amount_of_3; ++j){
            if((i*4 + j*3) == amount_of_blades){
                cout << "amount of 4 = " << i << '\n' << "amount of 3 = " << j << endl;
                return;
            }
        }
    }
    cout << "impossible to make spinner with " << amount_of_blades << " blades";
}

int main() {
    int n = 0;
    cout << "enter amount of blades" << endl;
    while(!(cin >> n)){
        cout << "not a number" << endl;
    }
    if (n < 0){
        cout << "impossible to make spinners out of negative elements" << endl;
        return 0;
    }
    make_spinners(n);

}
