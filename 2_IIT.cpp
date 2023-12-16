#include <iostream>
#include <math.h>
#include <locale>
#include <Windows.h>

using namespace std;


void ex_1() {
    double h, R, r, l;
    bool f1 = 0;
    cout << "Введите размерности усеченного конуса:" << endl;
    cout << "Высота, радиус нижний, радиус верхний, образующую" << endl;
    while (f1 != 1) {
        if (!(cin >> h >> R >> r)) {
            cout << "Введите число, а не что-то другое" << endl;
            cin.clear();
            cin.ignore();
        } else {
            f1 = 1;
        }
    }

    l = sqrt(h * h + (R - r) * (R - r));

    if ((h <= 0) or (R <= 0) or (r <= 0)) {
        cout << "Конус не существует" << endl;
    }
    else {
        cout << "Объем " << (3.14 * h * (R * R + R * r + r * r)) / 3 << endl;
        cout << "Площадь " << 3.14 * (R * R + (R + r) * l + r * r) << endl;
    }
}


void ex_2() {
    double a, x, w;
    bool f1 = 0;
    cout << "a x в таком же порядке" << endl;
    while (f1 != 1) {
        if (!(cin >> a >> x)) {
            cout << "Вы ввели не число. Повторите" << endl;
            cout << "a = " << endl;
            cout << "x = " << endl;
            cin.clear();
            cin.ignore();
        } else {
            f1 = 1;
        }
    }
    if ((fabs(x) < 1) and (x != 0)) {
        w = a * log(fabs(x));
        cout << "w = " << w << endl;
    }
    else if ((fabs(x) >= 1) and (a >= x * x)) {
        w = sqrt(a - x * x);
        cout << "w = " << w << endl;
    }
    else {
        cout << "Вне области определения" << endl;
    }

}


void ex_3() {
    double x, y, b;
    bool f1 = 0;
    cout << "x y b в таком же порядке" << endl;
    while (f1 != 1) {
        if (!(cin >> x >> y >> b)) {
            cout << "Вы ввели не число. Повторите" << endl;
            cout << "x y b в таком же порядке" << endl;
            cin.clear();
            cin.ignore();
        } else {
            f1 = 1;
        }
    }

    if ((b > y) and (b >= x)) {
        cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    }
    else {
        cout << "Вне области определения" << endl;
    }
}


void ex_4() {
    int n;
    bool f1 = 0;
    cout << "Введите 1 число ";
    while (f1 != 1) {
        if (!(cin >> n)) {
            cout << "Вы ввели не число. Повторите" << endl;
            cout << "Введите 1 число ";
            cin.clear();
            cin.ignore();
        } else {
            f1 = 1;
        }
    }
    if (n <= 0) {
        cout << "Вы введи неположительное число";
    }
    else {
        for (int i = n; i <= n + 9; i++) {
            cout << i << " ";
        }
    }
}


void ex_5() {
    double x = -4;
    double y;
    cout << "x\t | y\t" << endl;
    while (x <= 4) {
        if (x != 1) {
            y = (x * x - 2 * x + 2) / (x - 1);
        }
        else {
            cout << x << "\t | no" << endl;
        }
        cout << x << "\t | " << y << endl;
        x += 0.5;
    }
}

int main() {
    setlocale(0, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ex_1();
    ex_2();
    ex_3();
    ex_4();
    ex_5();
    return 0;
}
