#include <graphics.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
using namespace std;

//$file="C233456_bresenham2"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;

                                                                                                                                        // --- ADAPTIVE SCALING FOR VALUES LESS THAN 100 ---
                                                                                                                                        // Finds the largest coordinate value in your inputs
    int maxCoord = max(max(x1, x2), max(y1, y2));
    
    int SCALE, OFFSET_X, OFFSET_Y, blockSize;
    
    if (maxCoord > 50) {
        SCALE = 5;                                                                                                                                         // Keeps numbers up to 100 safely inside the screen
        OFFSET_X = 50;
        OFFSET_Y = 50;
        blockSize = 4;
    } else if (maxCoord > 20) {
        SCALE = 10;                                                                                                                                          // Perfect for coordinates in the 20-50 range (like 32, 42)
        OFFSET_X = 80;
        OFFSET_Y = 80;
        blockSize = 6;
    } else {
        SCALE = 20;                                                                                                                                          // Perfect for tiny single/double digit numbers (like 9, 14)
        OFFSET_X = 150;
        OFFSET_Y = 150;
        blockSize = 8;
    }

    if (dx >= dy) 
    {
                                                                                                                                            // Shallow slope setup matching your rules exactly
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);
        int d = 2 * dy - dx;

        int x = x1;
        int y = y1;

        while (true) 
        {
            cout << "(" << x << ", " << y << ")" << endl;
            
            int screenX = OFFSET_X + x * SCALE;
            int screenY = OFFSET_Y + y * SCALE;
            
            bar(screenX, screenY, screenX + blockSize, screenY + blockSize);

            if (x == x2) break;

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
            delay(50);                                                                                                                                     // Faster animation pace for longer tracking steps
        }
    } 
    else 
    {
                                                                                                                                            // Steep slope setup
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);
        int d = 2 * dx - dy;

        int x = x1;
        int y = y1;

        while (true) 
        {
            cout << "(" << x << ", " << y << ")" << endl;
            
            int screenX = OFFSET_X + x * SCALE;
            int screenY = OFFSET_Y + y * SCALE;
            
            bar(screenX, screenY, screenX + blockSize, screenY + blockSize);

            if (y == y2) break;

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
            delay(50);
        }
    }
}

int main()
{
    initwindow(800, 600, (char*)"Final Bresenham Line Drawing");
    setfillstyle(SOLID_FILL, WHITE);
    outtextxy(20, 20, (char*)"C233456");

                                                                                                                                        // Coordinates are less than 100 (Max value is 42)
    int x1 = 9, y1 = 18;
    int x2 = 14, y2 = 22;

    Bresenham(x1, y1, x2, y2);
    
    getch();
    closegraph();
    return 0;
}
