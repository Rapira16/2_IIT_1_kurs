#include <iostream>

using namespace std;

int main() {
    cout << "enter length of rectangle" << endl;
    int length = 0;
    while(!(cin >> length)){
        cout << "not a number" << endl;
    }
    cout << "enter width of rectangle" << endl;
    int width = 0;
    while(!(cin >> width)){
        cout << "not a number" << endl;
    }

    if ((length < 0) || (width < 0)){
        cout << "there is no rectangle with negative sides" << endl;
        return 0;
    }

    int summ = 0;

    for (int i = 1; i <= length; ++i){
        for (int j = 1; j <= width; ++j){
            summ += (length - i +1)*(width - j + 1);
        }
    }
    cout << "amount of rectangles: " << summ;
    return 0;
}
