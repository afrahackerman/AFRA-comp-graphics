#include <graphics.h>
#include <conio.h>

/* $file="mobile"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; .\"$file.exe" */

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Mobile body
    rectangle(200, 100, 280, 300);

    // Top speaker
    rectangle(220, 115, 260, 125);

    // Screen
    rectangle(210, 140, 270, 220);

    // Screen details
    line(220, 155, 260, 155);
    line(220, 170, 250, 170);
    line(220, 185, 260, 185);
    line(220, 200, 245, 200);

    // Buttons
    circle(240, 250, 12);
    rectangle(225, 275, 255, 285);

    getch();
    closegraph();

    return 0;
}
