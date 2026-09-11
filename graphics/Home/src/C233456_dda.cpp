#include <graphics.h>
#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;
//$file="C233456_dda"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 
void dda(int x1, int y1, int x2, int y2)
{
    int Dx, Dy;
    float m, x, y, dx, dy;

    Dx = x2 - x1;
    Dy = y2 - y1;

    x = x1;
    y = y1;

    m = (float)Dy / Dx;
    putpixel(round(x), round(y), WHITE);
    cout << "(" << round(x) << ", " << round(y) << ")" << endl;
    
    if (abs(Dx) >= abs(Dy))
    {
        dx = 1;

        while (x < x2)
        {
            x = x + dx;
            y = y + m * dx;

            putpixel(round(x), round(y), WHITE);
            cout << "(" << round(x) << ", " << round(y) << ")" << endl;
        }
    }
    else
    {
        dy = 1;

        while (y < y2)
        {
            x = x + dy / m;
            y = y + dy;

            putpixel(round(x), round(y), WHITE);
            cout << "(" << round(x) << ", " << round(y) << ")" << endl;
        }
    }
}
int main()
{
    initwindow(800, 600, (char*)"Final DDA Line Drawing");
    setfillstyle(SOLID_FILL, WHITE);
    outtextxy(20, 20, (char*)"C233456");

    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 300;
    dda(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}