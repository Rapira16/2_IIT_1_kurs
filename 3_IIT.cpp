#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void ex_1() {
	double S, p, r, m;
	int n;
	bool f1 = 0;
	cout << "Enter S, p, n in same order" << endl;
	while (f1 != 1) {
		if (!(cin >> S >> p >> n)) {
			cout << "Invalid input. Repeat" << endl;
			cout << "Enter S, p, n in same order" << endl;
		} else {
			f1 = 1;
		}
	}
	if ((S <= 0) or (p <= 0) or (n <= 0)) {
		cout << "Invalid input. No negative numbers or 0";
	} else {
		r = p / 100;
		m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
	}
	cout << "m = " << m << endl;
}

void ex_2() {
	double S, p, r, m, m0;
	int n;
	bool f1 = 0;
	cout << "Enter S, m, n in same order" << endl;
	while (f1 != 1) {
		if (!(cin >> S >> m >> n)) {
			cout << "Invalid input. Repeat" << endl;
			cout << "Enter S, m, n in same order" << endl;
		}
		else {
			f1 = 1;
		}
	}
	for (p = 1; p <= 100; p += 0.01) {
		r = p / 100;
		m0 = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
		if (abs(m0 - m) < 0.01) {
			cout << "p = " << p << endl;
			break;
		}
	}
}

void ex_3() {
	string x;
	cout << "Enter string";
	getline(cin, x);
	ofstream fout("IIT_3.docx");
	fout << x;
	fout.close();

	string y;
	ifstream fin("IIT_3.docx");
	getline(fin, y);
	fin.close();
	cout << "Inside file" << y << endl;
}



void ex_4() {
	ifstream fin("IIT_3.docx");
	char buff[20];
	fin >> buff;
	cout << buff << endl;
	for (int i = 0; i < size(buff); i++) {
		if (isdigit(buff[i])) {
			cout << buff[i];
		}
	}
	cout << "\n";
}

void ex_5() {
	string alphabet;

	cout << "Enter string len 30 ";
	if (size(alphabet) > 30) {
		cout << "Error";
	}
	cin >> alphabet;
	cout << alphabet;

	string sym;
	double arr[30];
	for (int i = 0; i < 30; i++) {
		double code;
		if ((int)alphabet[i] < 97) {
			code = (int)alphabet[i] + 0.1;
			arr[i] = code;
		} else {
			code = (int)alphabet[i];
			arr[i] = code;
		}
	}

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 29; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	
	for (int i = 0; i < 30; i++) {
		if (arr[i] - (int)arr[i])
	}
	cout << "\n" << alphabet;
}


int main() {
	ex_5();
	return 0;
}