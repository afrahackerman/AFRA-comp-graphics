#include <graphics.h>
#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;
//$file="C233456_trigcircle"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
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
void TrigonometricCircle(int r)
{
    int xc = 400;
    int yc = 300;
    float theta = 0;
    float step = 0.01;
    float theta_end = M_PI / 4;
    while (theta <= theta_end)
    {
        float x = r * cos(theta);
        float y = r * sin(theta);
        int px = round(x);
        int py = round(y);

        plotCirclePoints(xc, yc, px, py);
        cout << "theta = " << theta
            << ", x = " << px
            << ", y = " << py << endl;
        theta = theta + step;
    }
}
int main()
{
    initwindow(800, 600, (char*)"Trigonometric Circle Drawing");
    outtextxy(10, 10, (char*)"C233456");
    int r = 200;
    TrigonometricCircle(r);
    getch();
    closegraph();

    return 0;
}