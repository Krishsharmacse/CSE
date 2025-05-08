#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>

typedef struct{
    int x,y;
} Point;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void PlotPoint(int x, int y, int COLOR){
    putpixel(x-1, y  , COLOR);
    putpixel(x+1, y  , COLOR);
    putpixel(x  , y  , COLOR);
    putpixel(x  , y+1, COLOR);
    putpixel(x  , y-1, COLOR);
}
 
int main(){
    srand(time(0));
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    int maxX = getmaxx(), maxY = getmaxy();
    int midX = getmaxx()/2, midY = getmaxy()/2;

    Point points[50];
    points[0] = {midX +10, midY - 10}; points[1] = {midX - 10, midY - 10}; points[2] = {midX +20, midY - 20}; points[3] = {midX -20, midY - 20}; points[4] = {midX +30, midY - 30};

    for(int i = 5; i < 50; i++){
        points[i] = {random(0, maxX), random(0, maxY)};
    }

    setbkcolor(WHITE);
    cleardevice();    

    for(int i =0; i<5; i++){
        PlotPoint(points[i].x, points[i].y, BLACK);
    }

    setcolor(BLACK);
    const int x_min = midX - 50, y_min = midY - 50;
    const int x_max = midX + 50, y_max = midY + 50;
    rectangle(x_min, y_min, x_max, y_max);

    for(int i = 0; i < 50; i++) {
        int color;
    
        if (points[i].x >= x_min && points[i].x <= x_max && points[i].y >= y_min && points[i].y <= y_max) color = BLUE;
        else color = COLOR(150, 150, 150);
    
        PlotPoint(points[i].x, points[i].y, color);
    }

 
    getch();
    closegraph();
 
    return 0;

}