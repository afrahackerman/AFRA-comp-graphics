#include <graphics.h>
#include <conio.h>

int main()
{
    // 1. Open a standard window canvas
    initwindow(800, 600, (char*)"Diagnostic Test Window");
    
    // 2. Set the color to solid white explicitly
    setcolor(WHITE);
    
    // 3. Draw your student ID tag
    outtextxy(20, 20, (char*)"C233456");

    // 4. Force draw a massive, native line straight through the screen
    // It starts at X=100, Y=100 and ends at X=700, Y=500
    line(100, 100, 700, 500);

    getch();
    closegraph();
    return 0;
}
//$file="test"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32