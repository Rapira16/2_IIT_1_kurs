#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
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

    cout << "a + b = " << a + b;
}

void ex_2(){
    int n;
    vector<int> a;
    int m = 2;
    cout << "enter last number" << endl;
    while(!(cin >> n)){
        cout << "not a number" << endl;
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
            i--;
        }
        cout << "\na = " << a[i];
    }
}

void ex_3_23(){
    ofstream fout("PW_5.txt");
    string input;
    cout << "enter some words" << endl;
    cin >> input;
    fout << input;
    fout.close();
    ifstream fin("PW_5.txt");
    string buff;
    fin >> buff;
    getline(fin, buff);
    fin.close();
    cout << buff << endl;

    vector <char> extra;
    for (int k = 0; k < size(buff); k++){
        extra.push_back(buff[k]);
    }

    set<char> ne;
    for (int i = 0; i < size(buff); i++){
        ne.insert(buff[i]);
    }

    vector <char> end;
    for (char j : ne){
        if (!(isdigit(j)) && (tolower(j) != 'a') && (tolower(j) != 'o') && (tolower(j) != 'i')
            && (tolower(j) != 'e') && (tolower(j) != 'u') && (tolower(j) != 'y')){
            cout << j << " " << count(extra.begin(), extra.end(), j) << "\n";
            end.push_back(count(extra.begin(), extra.end(), j));
        }
    }

    int max = 0;
    for (int i=0; i< size(end); i++)
    {
        if (end[i]>max)
            max=end[i];
    }
    cout << "max = " << max;
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



int main() {
    ex_1();
    ex_2();
    ex_3_23();
    ex_4_19();
}
