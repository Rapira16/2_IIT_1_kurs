#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void ex_1(){
    int a, b;
    cout << "enter a" << endl;
    while(!(cin >> a)){
        cout << "not number" << endl;
    }
    cout << "enter b" << endl;
    while(!(cin >> b)){
        cout << "not number" << endl;
    }

    while((a != 0) && (b != 0)){
        if (a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }

    cout << "a + b = " << abs(a + b);
}

void ex_2(){
    int n;
    vector<int> a;
    int m = 2;
    cout << "enter last number" << endl;
    while(!(cin >> n)){
        cout << "not a number" << endl;
    }
    if (n < 0){
        cout << "only positive" << endl;
        return;
    }
    for (int i = 0; i < n; i++){
        a.push_back(i);
    }
    a[1] = 0;
    int j = 0;
    while(m < n){
        if(a[m] != 0){
            j = m * 2;
            while(j < n){
                a[j] = 0;
                j += m;
            }
        }
        m++;
    }

    for (int i = 0; i < size(a); i++){
        if (a[i] == 0){
            a.erase(a.begin() + i);
        }
    }
    for (int j = 0; j < size(a); j++){
        if (a[j] == 0){
            a.erase(a.begin() + j);
        }
        cout << "\na_1 = " << a[j];
    }
}


void ex_3_4(){
    ofstream fout("PW_5.txt");
    string input;
    cout << "enter some words" << endl;
    getline(cin, input);
    fout << input;
    fout.close();
    ifstream fin("PW_5.txt");
    string buff;
    getline(fin, buff);
    fin.close();
    cout << "buff: ";
    cout << buff << endl;

    vector <char> arr;
    vector <string> end;
    for (int i = 0; i < size(buff); i++){
        if(!(isalpha(buff[i]))){
            string buffer(arr.begin(), arr.end());
            end.push_back(buffer);
            arr.clear();
        } else {
            arr.push_back(buff[i]);
        }
    }
    if (size(arr) != 0){
        string buffer_1(arr.begin(), arr.end());
        end.push_back(buffer_1);
        arr.clear();
    }
    int max = 0;
    string longest_word;

    for (int j = 0; j < size(end); j++){
        if (size(end[j]) > max){
            longest_word = end[j];
            max = size(longest_word);
        }
        cout << longest_word << " " << size(end[j]) << endl;
    }
    cout << "longest word: " << longest_word;
}


void ex_3_23(){
    ofstream fout("PW_5.txt");
    string input;
    cout << "enter some words" << endl;
    getline(cin, input);
    fout << input;
    fout.close();
    ifstream fin("PW_5.txt");
    string buff;
    getline(fin, buff);
    fin.close();

    vector <char> all_symbols;
    for(int i = 0; i < size(buff); i++){
        all_symbols.push_back(buff[i]);
    }
    set <char> symbols(all_symbols.begin(), all_symbols.end());
    vector <char> extra;
    for (char k : symbols){
        if((isalpha(k)) && !((k == 'a') || (k == 'e') || (k == 'y') || (k == 'u') || (k == 'i') || (k == 'o'))){
            extra.push_back(k);
        }
    }
    int sym = 0;
    int max = 0;
    char max_sym;
    for (char n : extra){
        sym = count(all_symbols.begin(), all_symbols.end(), n);
        cout << n << ": " << sym << endl;
        if (sym > max){
            max = sym;
            max_sym = n;
        }
    }
    cout << "max: " << max_sym << " - " << max;
}


void ex_4_19(){
    float height = 1;
    cout << "Enter height and press enter";
    vector <float> heights;
    int summ = 0;
    while (height > 0){
        cout << "\n->";
        while(!(cin >> height)){
            cout << "not number" << endl;
        }
        summ += height;
        heights.push_back(height);
    }
    int count = 0;
    float average = summ/(size(heights) - 1);
    for (int i = 0; i < size(heights) - 1; i++){
        if (heights[i] > average){
            count++;
        }
    }
    cout << count << " got higher than average";
}


void ex_4_35(){
    string S;
    cout << "enter some string" << endl;
    getline(cin, S);
    cout << S << endl;
    int count = 0;
    int max = 0;
    for(int i = 0; i <= size(S); i++){
        if (S[i] == ' '){
            count++;
        } else {
            if (max < count){
                max = count;
            }
            count = 0;
        }
    }
    cout << "amount of whitespaces = " << max;
}


void ex_5_57(){
    cout << "enter 1_1 element of matrix" << endl;
    float element_1_1 = 0;
    cin >> element_1_1;
    cout << "enter 1_2 element of matrix" << endl;
    float element_1_2 = 0;
    cin >> element_1_2;
    cout << "enter 2_1 element of matrix" << endl;
    float element_2_1 = 0;
    cin >> element_2_1;
    cout << "enter 2_2 element of matrix" << endl;
    float element_2_2 = 0;
    cin >> element_2_2;
    cout << element_1_1 << "\t" << element_1_2 << endl;
    cout << element_2_1 << "\t" << element_2_2 << endl;

    float exit = element_1_1*element_2_2 - element_2_1*element_1_2;
    cout << "exit: " << exit;

}


void ex_5_36(){
    float n = 0;
    cout << "enter number" << endl;
    while (!(cin >> n)){
        cout << "not a number" << endl;
    }
    n = n*n;
    string n_string = to_string(n);
    for (int i = 0; i < size(n_string); i++){
        if (n_string[i] == '3'){
            cout << "number 3 is in number n^2";
            return;
        } else {
            cout << "number n^2 doesn't have 3 in it" << endl;
            return;
        }
    }
}

int main() {
    string input;
    cout << "enter ex(1, 2, 3_4, 3_23, 4_19, 4_35, 5_57, 5_36) ";
    cin >> input;
    if (input == "1") ex_1();
    else if (input == "2") ex_2();
    else if (input == "3_4") ex_3_4();
    else if (input == "3_23") ex_3_23();
    else if (input == "4_19") ex_4_19();
    else if (input == "4_35") ex_4_35();
    else if (input == "5_57") ex_5_57();
    else if (input == "5_26") ex_5_36();
    else cout << "no such ex";
}
