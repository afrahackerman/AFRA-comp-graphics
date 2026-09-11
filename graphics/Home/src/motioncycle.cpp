#include <graphics.h>
#include <conio.h>
#include <cmath> // Required for sin() and cos()

/* $file="motioncycle"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 */

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x = 0;          // Dynamic horizontal position offset
    float angle = 0.0;  // Dynamic wheel rotation angle

    // Get the maximum screen width to loop the animation smoothly
    int maxWidth = getmaxx();

    // Loop until a keyboard key is pressed
    while (!kbhit()) 
    {
        // Clear the previous frame
        cleardevice();

        // 1. Draw Wheels (Shifted by x)
        circle(150 + x, 300, 45); // Left wheel
        circle(300 + x, 300, 45); // Right wheel

        // 2. Draw Moving Wheel Spokes (Rotating Effect)
        for (int i = 0; i < 4; i++) {
            // Calculate spoke endpoints using polar coordinates
            float rad = angle + (i * 3.14159 / 2); // 90 degrees apart
            
            // Left Wheel Spoke
            line(150 + x, 300, 150 + x + 45 * cos(rad), 300 + 45 * sin(rad));
            // Right Wheel Spoke
            line(300 + x, 300, 300 + x + 45 * cos(rad), 300 + 45 * sin(rad));
        }

        // 3. Draw Bicycle Frame (All components shifted by x)
        line(150 + x, 300, 210 + x, 240);
        line(210 + x, 240, 250 + x, 300);
        line(250 + x, 300, 150 + x, 300);
        line(210 + x, 240, 300 + x, 300);
        line(210 + x, 240, 195 + x, 210);

        // Seat
        line(185 + x, 205, 210 + x, 205);

        // Handle
        line(300 + x, 300, 285 + x, 225);
        line(285 + x, 225, 300 + x, 215);

        // Pedal
        circle(250 + x, 300, 8);
        line(250 + x, 300, 250 + x + 15 * cos(angle), 300 + 15 * sin(angle));
        line(250 + x, 300, 250 + x - 15 * cos(angle), 300 - 15 * sin(angle));

        // 4. Update coordinates for the next frame
        x += 3;          // Increase value to speed up forward movement
        angle += 0.1;    // Increase value to speed up wheel rotation

        // If the bicycle exits the right side, reset it to the left side
        if (150 + x - 45 > maxWidth) {
            x = -350; 
        }

        // Frame rate limiter (Pause for 20 milliseconds)
        delay(20); 
    }

    closegraph();
    return 0;
}
