#include <graphics.h>
#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;


void DDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int absDx = std::abs(dx);
    int absDy = std::abs(dy);
    int steps = (absDx > absDy) ? absDx : absDy;
    
    if (steps == 0) 
    {
        putpixel(x1, y1, WHITE);
        return;
    }

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    // --- ADAPTIVE SCALING MATRIX (Matches Bresenham exactly) ---
    int maxCoord = max(max(x1, x2), max(y1, y2));
    
    int SCALE, OFFSET_X, OFFSET_Y, blockSize;
    
    if (maxCoord > 50) {
        SCALE = 5;       // Safe for inputs up to 100
        OFFSET_X = 50;
        OFFSET_Y = 50;
        blockSize = 4;
    } else if (maxCoord > 20) {
        SCALE = 10;      // Perfect for coordinates in the 20-50 range (e.g., 32, 42)
        OFFSET_X = 80;
        OFFSET_Y = 80;
        blockSize = 6;
    } else {
        SCALE = 20;      // Perfect for tiny coordinates (e.g., 9, 14)
        OFFSET_X = 150;
        OFFSET_Y = 150;
        blockSize = 8;
    }

    for (int i = 0; i <= steps; i++)
    {
        int pixelX = std::round(x);
        int pixelY = std::round(y);

        cout << "(" << pixelX << ", " << pixelY << ")" << endl;
        
        int screenX = OFFSET_X + pixelX * SCALE;
        int screenY = OFFSET_Y + pixelY * SCALE;

        // Draws matching chunky blocks just like your Bresenham code
        bar(screenX, screenY, screenX + blockSize, screenY + blockSize);
        
        x += xIncrement; 
        y += yIncrement;
        delay(200); 
    }
}

int main()
{
    initwindow(800, 600, (char*)"Final DDA Line Drawing");
    setfillstyle(SOLID_FILL, WHITE);
    outtextxy(20, 20, (char*)"C233456");

    // Coordinates match your Bresenham test case exactly
    int x1 = 14, y1 = 22;
    int x2 = 9, y2 = 18;

    DDA(x1, y1, x2, y2);
    
    getch();
    closegraph();
    return 0;
}

//$file="dda2"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 