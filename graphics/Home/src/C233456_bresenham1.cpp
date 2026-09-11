#include <graphics.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
using namespace std;
//$file="C233456_bresenham1"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;

    if (dx >= dy) 
    {
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);
        int d = 2 * dy - dx;

        int x = x1;
        int y = y1;
        putpixel(x, y, WHITE);
        cout << "(" << x << ", " << y << ")" << endl;

        while (x != x2) 
        {
            x += stepX;
            if (d < 0) 
            {
                d = d + ds;
            } 
            else 
            {
                y += stepY;
                d = d + dt;
            }
            putpixel(x, y, WHITE);
            cout << "(" << x << ", " << y << ")" << endl;
            delay(10);
        }
    } 
    else 
    {
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);
        int d = 2 * dx - dy;

        int x = x1;
        int y = y1;

        putpixel(x, y, WHITE);
        cout << "(" << x << ", " << y << ")" << endl;

        while (y != y2) 
        {
            y += stepY;
            if (d < 0) 
            {
                d = d + ds;
            } 
            else 
            {
                x += stepX;
                d = d + dt;
            }
            putpixel(x, y, WHITE);
            cout << "(" << x << ", " << y << ")" << endl;
            delay(10);
        }
    }
}

int main()
{
    initwindow(800, 600, (char*)"Final Bresenham Line Drawing");
    outtextxy(10, 10, (char*)"C233456");

    int x1 = 400, y1 = 300;
    int x2 = 100, y2 = 120;

    Bresenham(x1, y1, x2, y2);
    
    getch();
    closegraph();
    return 0;
}
