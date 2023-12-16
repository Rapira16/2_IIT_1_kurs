#include <iostream>
#include <windows.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    while(true){
        HWND hWnd = GetConsoleWindow();
        HDC hDC = GetDC(hWnd);
        HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        SelectObject(hDC, Pen);
        MoveToEx(hDC, 0, 300, NULL);
        LineTo(hDC, 1200, 300);
        MoveToEx(hDC, 550, 0, NULL);
        LineTo(hDC, 550, 1000);
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
        SelectObject(hDC, pen);
    
        for (float x = -8.0f; x <= 8.0f; x += 0.01f) {
            MoveToEx(hDC, 90 * x + 550, -90 * sin(x) + 300, NULL);
            LineTo(hDC, 90 * x + 550, -90 * sin(x) + 300);
        }
        HPEN Pen_1 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        SelectObject(hDC, Pen_1);
        Ellipse(hDC, 125, 215, 135, 205);
        Ellipse(hDC, 405, 395, 415, 385);
        Ellipse(hDC, 685, 215, 695, 205);
        Ellipse(hDC, 965, 395, 975, 385);
        ReleaseDC(hWnd, hDC);
    }
}
