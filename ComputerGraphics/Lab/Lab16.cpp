#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

typedef struct {
    int x, y;
} Point;

Point bezier(Point p0, Point p1, Point p2, Point p3, float u) {
    Point p;
    p.x = (int)( p0.x * pow((1-u),3) + 3*p1.x *u * pow(1-u, 2) + 3*p2.x * u*u * (1-u) + p3.x*u*u*u );
    p.y = (int)( p0.y * pow((1-u),3) + 3*p1.y *u * pow(1-u, 2) + 3*p2.y * u*u * (1-u) + p3.y*u*u*u );
    return p;
}

void PlotPoint(int x, int y, int COLOR){
    putpixel(x-1, y  , COLOR);
    putpixel(x+1, y  , COLOR);
    putpixel(x  , y  , COLOR);
    putpixel(x  , y+1, COLOR);
    putpixel(x  , y-1, COLOR);
}
 

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
    cleardevice();  

    // control points
    Point p0 = {100, 300};  
    Point p1 = {150, 100};  
    Point p2 = {200, 300};   
    Point p3 = {250, 200};  

    setcolor(BLACK);
    PlotPoint(p0.x, p0.y, BLACK);
    PlotPoint(p1.x, p1.y, BLACK);
    PlotPoint(p2.x, p2.y, BLACK);
    PlotPoint(p3.x, p3.y, BLACK);

    setcolor(RED);
    for (float u = 0; u <= 1; u += 0.001f) {
        Point p = bezier(p0, p1, p2, p3, u);
        putpixel(p.x, p.y, RED);
    }

    getch();
    closegraph();
    return 0;
}
