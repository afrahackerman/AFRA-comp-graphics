#include <graphics.h>
#include <conio.h>

/* Run: 
$file="bicycle"; g++ "$file.cpp" -o "$file" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; .\"$file.exe" 
*/

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Wheels circles
    circle(150, 300, 45); 
    circle(300, 300, 45); 

    // wheels lines!!!!
    line(150, 300, 150, 255); line(150, 300, 150, 345);
    line(150, 300, 105, 300); line(150, 300, 195, 300);
    line(300, 300, 300, 255); line(300, 300, 300, 345);
    line(300, 300, 255, 300); line(300, 300, 345, 300);

    //connection korar jonno with seat, handle etc
    line(150, 300, 210, 240); 
    line(210, 240, 250, 300); 
    line(250, 300, 150, 300); 
    line(210, 240, 285, 225); 
    line(250, 300, 285, 225); 

    // seattttttttt
    line(210, 240, 197, 205); 
    line(185, 205, 215, 205); 

    // Handle 
    line(300, 300, 285, 225); 
    line(285, 225, 280, 205); 
    line(280, 205, 300, 205); 

    // Pedals
    circle(250, 300, 8); 
    line(250, 300, 260, 311); 
    line(250, 300, 240, 289); 

    getch();
    closegraph();
    return 0;
}
