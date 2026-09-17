#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;
//$file="C233456_brescircle"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
void plotCirclePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc + x, yc + y, WHITE);
}
void BresenhamCircle(int r)
{
    int xc = 400;
    int yc = 300;
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        plotCirclePoints(xc, yc, x, y);
        cout << "(" << x << ", " << y << ")" << endl;
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
int main()
{
    initwindow(800, 600, (char*)"Bresenham Circle Drawing");
    outtextxy(10, 10, (char*)"C233456");
    int r = 200;
    BresenhamCircle(r);
    getch();
    closegraph();
    return 0;
}