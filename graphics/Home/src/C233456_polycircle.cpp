#include <graphics.h>
#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;
//$file="C233456_circle"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

void PolynomialCircle(int r)
{
    float x = 0;
    float i = 1;
    float x_end = r / sqrt(2.0);

    int centerX = 400;
    int centerY = 300;

    while (x <= x_end)
    {
        float y = sqrt((r * r) - (x * x));
        int px = round(x);
        int py = round(y);

        putpixel(centerX + px, centerY - py, WHITE);
        putpixel(centerX + py, centerY - px, WHITE);
        putpixel(centerX - py, centerY - px, WHITE);
        putpixel(centerX - px, centerY - py, WHITE);

        putpixel(centerX - px, centerY + py, WHITE);
        putpixel(centerX - py, centerY + px, WHITE);
        putpixel(centerX + py, centerY + px, WHITE);
        putpixel(centerX + px, centerY + py, WHITE);

        cout << "x = " << px << ", y = " << py << endl;
        x = x + i;
    }
}
int main()
{
    initwindow(800, 600, (char*)"Polynomial Circle Drawing");
    outtextxy(10, 10, (char*)"C233456");
    int r = 200;
    PolynomialCircle(r);
    getch();
    closegraph();
    return 0;
}