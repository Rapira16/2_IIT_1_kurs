#include <iostream>
#include <math.h>
using namespace std;


void ex_1(){
    cout << "Суханов Дмитрий Витальевич" << endl;
}


void ex_2() {
    double a, b;
    cout << "Enter 2 numbers" << endl;
    cout << "Enter a";
    cin >> a;
    cout << "Enter b";
    cin >> b;
    cout << "Sum " << (a + b) << endl;
    cout << "Subtraction " << (a - b) << endl;
    cout << "Multiplication " << (a * b) << endl;
    if (b == 0) {
        cout << "Division " << "Nope" << endl;
    }
    else {
        cout << "Division " << a / b << endl;
    }
}


void ex_3() {
    double b, c;
    cout << "enter b and c of equation" << endl;
    cout << "Enter b" << endl;
    cin >> b;
    cout << "Enter c" << endl;
    cin >> c;

    if (b == 0) {
        if (c == 0) {
            cout << "any x" << endl;
        }
        else {
            cout << "no rational roots" << endl;
        }
    }
    else {
        cout << "The equation root is " << -c / b << endl;
    }
}


void ex_4() {
    double a, b, c, D, x1, x2;
    cout << "enter a, b, c of quadratic equation" << endl;
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;
    cout << "Enter c" << endl;
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "any x" << endl;
            }
            else {
                cout << "no rational roots" << endl;
            }
        }
        else {
            cout << "The equation root is " << -c / b << endl;
        }
    }
    else {
        D = b * b - 4 * a * c;
        if (D > 0) {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout << "roots " << x1 << " " << x2 << endl;
        }
        else if (D == 0) {
            x1 = (-b) / (2 * a);
            cout << "root " << x1 << endl;
        }
        else {
            cout << "no roots" << endl;
        }
    }
}


void ex_5(){
    char ans1, ans2, ans3;
    cout << "Is lamp on?(y/n)" << endl;
    cin >> ans1;
    cout << "Are curtains open?(y/n)" << endl;
    cin >> ans2;
    cout << "Is it day?" << endl;
    cin >> ans3;
    if(((ans3 == 'y') && (ans2 == 'y')) || (ans1 == 'y')){
        cout << "It is bright in the room";
    } else {
        cout << "It is dark in the room";
    }
}


int main() {
    char input;
    cout << "choose ex(1, 2, 3, 4, 5) ";
    cin >> input;
    switch (input) {
        case '1':
            ex_1();
            break;
        case '2':
            ex_2();
            break;
        case '3':
            ex_3();
            break;
        case '4':
            ex_4();
            break;
        case '5':
            ex_5();
            break;
        default:
            cout << "no such ex";
    }
}
