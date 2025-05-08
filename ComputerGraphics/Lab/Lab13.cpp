#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    float x, y, z;
};

void projectPoint(Point p, int &x2d, int &y2d, float d) {
    float x_proj = (p.x * d) / (p.z);
    float y_proj = (p.y * d) / (p.z);
    x2d = getmaxx()/2 + (int)(x_proj); 
    y2d = getmaxy()/2 - (int)(y_proj);
}

void drawEdge(Point p1, Point p2, float d) {
    int x1, y1, x2, y2;
    projectPoint(p1, x1, y1, d);
    projectPoint(p2, x2, y2, d);
    line(x1, y1, x2, y2);
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
    cleardevice();
    setcolor(COLOR(100,100,100));
    setlinestyle(DOTTED_LINE, 0, 1);
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2); 
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy()); 
    setlinestyle(SOLID_LINE, 0, 1);
    
    float d = 100.0f; 
    Point cube[8] = {
        {-100, -100, 100}, {100, -100, 100}, {100, 100, 100},  {-100, 100, 100},
        {-100, -100, 200}, {100, -100, 200}, {100, 100, 200}, {-100, 100, 200}
    };

    setcolor(COLOR(0,0,0));
    drawEdge(cube[0], cube[1], d);
    drawEdge(cube[1], cube[2], d);
    drawEdge(cube[2], cube[3], d);
    drawEdge(cube[3], cube[0], d);
    
    setcolor(COLOR(100,100,100));
    drawEdge(cube[4], cube[5], d);
    drawEdge(cube[5], cube[6], d);
    drawEdge(cube[6], cube[7], d);
    drawEdge(cube[7], cube[4], d);
    
    drawEdge(cube[0], cube[4], d);
    drawEdge(cube[1], cube[5], d);
    drawEdge(cube[2], cube[6], d);
    drawEdge(cube[3], cube[7], d);


    getch();
    closegraph();
    return 0;
}
