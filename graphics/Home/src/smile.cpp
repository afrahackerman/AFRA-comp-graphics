#include <graphics.h>
#include <conio.h>
#include <iostream>
int main()
{
    initwindow(500, 500, (char*)"My Smiley Face"); 

    // Face - yellow filled circle
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(250, 200, 80);
    floodfill(250, 200, YELLOW);

    // Eyes - black
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    circle(220, 175, 6);
    floodfill(220, 175, BLACK);

    circle(280, 175, 6);
    floodfill(280, 175, BLACK);

    // Smile - red
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 3);
    arc(250, 195, 200, 340, 45);

    getch();
    closegraph();

    return 0;
}

