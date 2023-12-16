#include <iostream>

using namespace std;

void buy_spinner(int base, int blades, int max_sum){
    if (base > max_sum){
        cout << "to expensive" << '\n';
    }
    int N = 0;
    N = (max_sum-base)/blades;
    if (N <= 0){
        cout << "not enough money" << '\n';
        return;
    }
    cout << "maximum amount of blades: " << N;
}

int main() {
    int A = 0, B = 0, C = 0;
    while (!(cin >> A)){
        cout << "not a number";
    }
    while (!(cin >> B)){
        cout << "not a number";
    }
    while (!(cin >> C)){
        cout << "not a number";
    }
    buy_spinner(A, B, C);
}
