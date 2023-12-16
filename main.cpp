#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"
#include <math.h>
#include <vector>
#include<algorithm>

using namespace std;


// ex_1-----------------------------------------------------------------------------------------------------------------
void ex_1(){
    ofstream fout("ex_1.txt");
    float num;
    int b = 0;
    cout << "Enter 10 numbers" << endl;
    while(b < 10){
        if (!(cin >> num)){
            cout << "Not a number" << endl;
            break;
        } else {
            fout << num << endl;
            b++;
        }
    }
    string arr[10];
    fout.close();

    ifstream fin("ex_1.txt");
    string buff;
    int a = 0;
    while (a < 10){
        getline(fin, buff);
        cout << buff << "\n";
        arr[a] = buff;
        a++;
    }
    fin.close();

    float array[10];
    float summ;
    for (int i = 0; i < 10; i++){
        array[i] = stof(arr[i]);
        summ += array[i];
    }
    cout << "summ = " << summ;
}


//ex_2------------------------------------------------------------------------------------------------------------------
void ex_2_case_1(){
    cout << "-" << endl;
}
void ex_2_case_2(){
    cout << "0" << endl;
}
void ex_2_case_3(){
    cout << "+" << endl;
}
float ex_2(){
    float num;
    cout << "Enter number" << endl;
    while(!(cin >> num)){
        cout << "error. Not number. Try again" << endl;
    }
    if (num < 0){
        ex_2_case_1();
    } else if (num == 0){
        ex_2_case_2();
    } else {
        ex_2_case_3();
    }
}


//ex_3------------------------------------------------------------------------------------------------------------------
void rectangle(){
    float lenght, width, area;
    cout << "enter lenght " << endl;
    while (!(cin >> lenght)){
        cout << "try again";
    }
    cout << "enter width " << endl;
    while(!(cin >> width)){
        cout << "try again";
    }
    if ((lenght <= 0) || (width <= 0)){
        cout << "no such rectangle" << endl;
        return;
    }
    area = lenght * width;
    cout << "rectangle area = " << area;
}

void triangle(){
    float height, width, area;
    cout << "enter height " << endl;
    while(!(cin >> height)){
        cout << "try again";
    }
    cout << "enter width " << endl;
    while(!(cin >> width)){
        cout << "try again";
    }
    if ((width <= 0) || (height <= 0)){
        cout << "no such triangle" << endl;
        return;
    }
    area = height * width / 2;
    cout << "triangle area = " << area;
}

void circle(){
    float radius, area;
    cout << "enter radius " << endl;
    while(!(cin >> radius)){
        cout << "try again";
    }
    if (radius <= 0){
        cout << "no such circle" << endl;
    }
    area = 3.14 * radius * radius;
    cout << area;
}

void ex_3(){
    char name;
    cout << "triangle, rectangle, circle as: t, r, c " << endl;
    cin >> name;
    switch (name) {
        case 't':
            triangle();
            break;
        case 'r':
            rectangle();
            break;
        case 'c':
            circle();
            break;
        default:
            cout << "no such figure";
    }
}


//ex_4------------------------------------------------------------------------------------------------------------------
void ex_4(){
    int i = 0;
    while (i < 8){
        if (i < 4){
            int j = 0;
            int k = 0;
            while (j < 8){
                cout << '*';
                j++;
            }
            while (k < 22) {
                cout << "_";
                k++;
            }
        } else {
            int l = 0;
            while (l < 30){
                cout << "_";
                l++;
            }
        }
        cout << "\n";
        i++;
    }
}

//ex_6------------------------------------------------------------------------------------------------------------------
void ex_6(){
    string number;
    vector <int> numbers;
    bool b1 = true;
    cout << "enter number in rome form" << endl;
    cin >> number;
    for (int i = 0; i < size(number); i++) {
        switch (number[i]) {
            case 'I':
                if ((number[i+1] != 'V') && (number[i+1]) != 'X'){
                    numbers.push_back(1);
                } else {
                    numbers.push_back(0);
                }
                break;
            case 'V':
                if (number[i-1] == 'I'){
                    numbers.push_back(4);
                } else {
                    numbers.push_back(5);
                }
                break;
            case 'X':
                if ((number[i+1] != 'L') && (number[i+1]) != 'C') {
                    if (number[i - 1] == 'I') {
                        numbers.push_back(9);
                    } else {
                        numbers.push_back(10);
                    }
                } else {
                    numbers.push_back(0);
                }
                break;
            case 'L':
                if (number[i-1] == 'X'){
                    numbers.push_back(40);
                } else {
                    numbers.push_back(50);
                }
                break;
            case 'C':
                if ((number[i+1] != 'D') && (number[i+1]) != 'M') {
                    if (number[i - 1] == 'X') {
                        numbers.push_back(90);
                    } else {
                        numbers.push_back(100);
                    }
                } else {
                    numbers.push_back(0);
                }
                break;
            case 'D':
                if (number[i-1] == 'C'){
                    numbers.push_back(400);
                } else {
                    numbers.push_back(500);
                }
                break;
            case 'M':
                if (number[i-1] == 'C'){
                    numbers.push_back(900);
                } else {
                    numbers.push_back(1000);
                }
                break;
            default:
                cout << "you entered to much";
                break;
        }
        cout << numbers[i] << " ";
    }
    if ((count(numbers.begin(), numbers.end(), 1) > 3) ||
            (count(numbers.begin(), numbers.end(), 1) > 3) ||
            (count(numbers.begin(), numbers.end(), 5) > 1) ||
            (count(numbers.begin(), numbers.end(), 10) > 3) ||
            (count(numbers.begin(), numbers.end(), 50) > 1) ||
            (count(numbers.begin(), numbers.end(), 100) > 3) ||
            (count(numbers.begin(), numbers.end(), 500) > 1) ||
            (count(numbers.begin(), numbers.end(), 1000) > 3)){
        cout << "no such rome number" << endl;
    }
    if (size(numbers) > 2){
        for (int i = 0; i < size(numbers) - 2; i++){
            if (numbers[i] >= numbers[i-2]){
                cout << "no such rome number\n";
                return;
            }
            if (((numbers[i] - numbers[i+1]) == 4) || ((numbers[i] - numbers[i+1]) == 40) || ((numbers[i]) - numbers[i+1] == 400)){
                cout << "no such rome number\n";
                return;
            }
        }
    }
    for (int j = 0; j < size(numbers) - count(numbers.begin(), numbers.end(), 0); j++){
        if (numbers[j] == 0){
            numbers.erase(numbers.begin() + j);
        }
    }
    int summ = 0;
    for (int k = 0; k < size(numbers); k++){
        cout << "\nnumbers[" << k << "]" << numbers[k];
        summ += numbers[k];
    }
    cout << "\nsumm = " << summ;
}

//ex_7------------------------------------------------------------------------------------------------------------------
void ex_7(){
    // 1
    int m = 37, b = 3, c = 64;
    int count = 0;
    cout << "enter amount of numbers" << endl;
    while(!(cin >> count)){
        cout << "not number" << endl;
    }
    int const size = count;
    float arr[size];
    arr[0] = 0;
    for (int i = 0; i < size; i++){
        arr[i+1] = (int)(m * arr[i] + b) % c;
        cout << "\ns[" << i << "] = " << arr[i];
    }
    //2
    int m_2 = 25173, b_2 = 13849, c_2 = 65537;
    int k = 0;
    cout << "\nenter amount of numbers 2.0" << endl;
    while (!(cin >> k)){
        cout << "not number" << endl;
    }
    int const size_2 = k;
    float arr_2[size_2];
    arr_2[0] = 0;
    for(int j = 0; j < size_2; j++){
        arr_2[j+1] = (int)(m_2 * arr_2[j] + b_2) % c_2;
        cout << "\ns_2[" << j << "] = " << arr_2[j];
    }
}

//ex_8------------------------------------------------------------------------------------------------------------------
void ex_8() {
    int seller[3][4] = {{5,  2, 0, 10},
                        {3,  5, 2, 5},
                        {20, 0, 0, 0}
    };
    float product[4][2] = {{1.2, 0.5},
                           {2.8, 0.4},
                           {5,   1},
                           {2,   1.5}
    };
//1
    float seller_1_sold = 0, seller_2_sold = 0, seller_3_sold = 0;
    for (int i = 0; i < 4; i++) {
        seller_1_sold += seller[0][i] * product[i][0];
        seller_2_sold += seller[1][i] * product[i][0];
        seller_3_sold += seller[2][i] * product[i][0];
    }
    cout << "\nseller_1_sold = " << seller_1_sold;
    cout << "\nseller_2_sold = " << seller_2_sold;
    cout << "\nseller_3_sold = " << seller_3_sold;
    float max_1 = seller_1_sold;
    if (max_1 < seller_2_sold) {
        max_1 = seller_2_sold;
    }
    if (max_1 < seller_3_sold) {
        max_1 = seller_3_sold;
    }
    cout << "\nmax_1 = " << max_1;
// 2
    float commision_1 = 0, commision_2 = 0, commision_3 = 0;
    for (int j = 0; j <= 3; j++) {
        commision_1 += seller[0][j] * product[j][1];
        commision_2 += seller[1][j] * product[j][1];
        commision_3 += seller[2][j] * product[j][1];
    }
    cout << "\ncommision_1 = " << commision_1;
    cout << "\ncommision_2 = " << commision_2;
    cout << "\ncommision_3 = " << commision_3;
    float max_2 = commision_1;
    if (max_2 < commision_2) {
        max_2 = commision_2;
    }
    if (max_2 < commision_3) {
        max_2 = commision_3;
    }
    cout << "\nmax_2 = " << max_2;

// 3
    float result_1 = 0, result_2 = 0, result_3 = 0;
    result_1 += seller_1_sold - commision_1;
    result_2 += seller_2_sold - commision_2;
    result_3 += seller_3_sold - commision_3;
    cout << "\nresult_1 = " << result_1;
    cout << "\nresult_2 = " << result_2;
    cout << "\nresult_3 = " << result_3 << endl;

    cout << "commision_all = " << commision_1 + commision_2 + commision_3 << endl;
    cout << "sold_all = " << seller_1_sold + seller_2_sold + seller_3_sold << endl;
    cout << "result_all" << result_1 + result_2 + result_3 << endl;
}
//ex_9------------------------------------------------------------------------------------------------------------------
void ex_9(){
    string number;
    int base;
    cout << "enter base of number" << endl;
    while (!(cin >> base)){
        cout << "not int" << endl;
    }
    cout << "enter number " << endl;
    cin >> number;
    reverse(number.begin(), number.end());
    int base_out;
    cout << "enter base of out" << endl;
    while (!(cin >> base_out)){
        cout << "no" << endl;
    }
    // to 10
    int summ = 0;
    vector <int> num;
    for (int i = 0; i < size(number); i++){
        if ((47 < (int)number[i]) && ((int)number[i] < 58)){
            num.push_back(((int)number[i]) - 48);
         } else if ((65 <= (int)number[i]) && ((int)number[i] <= 90)){
            num.push_back((int)(number[i]) - 55);
        }
    }
    for(int j = 0; j < size(num); j++){
        if (num[j] > (base - 1)){
            cout << "wrong base input" << endl;
            return;
        } else {
            summ += pow(base, j) * num[j];
        }
    }
    cout << "in dec = " << summ << endl;

    vector <int> out;
    while(summ != 0){
        out.push_back(summ%base_out);
        summ /= base_out;
    }
    for(int k = size(out) - 1; k >= 0; k--){
        cout << out[k];
    }
}

int main() {
    //ex_1();
    //ex_2();
    //ex_3();
    //ex_4();
    //ex_6();
    //
    //ex_7();
    //ex_8();
    //ex_9();
    return 0;
}