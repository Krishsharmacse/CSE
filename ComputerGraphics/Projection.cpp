#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

struct Point3D {
    float x, y, z;
};

void projectPoint(Point3D p, int &x2d, int &y2d, float d) {
    float x_proj = (p.x * d) / (p.z + d);
    float y_proj = (p.y * d) / (p.z + d);

    x2d = 320 + int(x_proj); 
    y2d = 240 - int(y_proj);
}

void drawEdge(Point3D p1, Point3D p2, float d) {
    int x1, y1, x2, y2;
    projectPoint(p1, x1, y1, d);
    projectPoint(p2, x2, y2, d);
    line(x1, y1, x2, y2);
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    cleardevice();
    setcolor(WHITE);
    line(0, 240, 640, 240); 
    line(320, 0, 320, 480); 

    float d = 100.0f; 

    Point3D cube[8] = {
        {-100, -100, 100}, {100, -100, 100}, {100, 100, 100},  {-100, 100, 100},
        {-100, -100, 200}, {100, -100, 200}, {100, 100, 200}, {-100, 100, 200}
    };

    drawEdge(cube[0], cube[1], d);
    drawEdge(cube[1], cube[2], d);
    drawEdge(cube[2], cube[3], d);
    drawEdge(cube[3], cube[0], d);

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
