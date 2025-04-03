// g++ CohenSutherland.cpp -o CohenSutherland.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && CohenSutherland.exe

#include<stdio.h>
#include<graphics.h>
#include<conio.h>

#define inside 0
#define top 8
#define bottom 1
#define left 2
#define right 4


const int x_min = 100, y_min = 100, x_max = 400, y_max = 300;

void clip(int x1, int y1, int x2,int y2);

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, (char*)"");

    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    int x1 = 450, y1 = 350; 
    int x2 = 50, y2 = 50;      
    
    setcolor(YELLOW);
    line(x1,y1,x2,y2);

    clip(x1, y1, x2,y2);
    // printf("%d", 3 & 1);

    getch();
    closegraph();
    
}

int RegionCode(int x, int y){
    int code = inside;
    if(x < x_min) code |= left;
    if(x > x_max) code |= right;
    if(y < y_min) code |= bottom;
    if(y > y_max) code |= top;

    return code;
}

void clip(int x1, int y1, int x2,int y2){
    int code1 = RegionCode(x1, y1);
    int code2 = RegionCode(x2, y2);
    bool accept = false;

    
    while(true){
        printf("%d %d %d\n", code1, code2, code1&code2);
        if(code1==0 && code2==0){
            printf("trivially accepted\n");
            accept = true;
            break;
        }
        if(code1 & code2){
            printf("trivially rejected\n");
            break;
        }

        int out;
        if(code1 == 0) out = code2;
        else out = code1;

        float m;
        if (x2 != x1) {
            m = (float)(y2 - y1) / (x2 - x1);
        } else {
            m = 999999;  
        }
        
        int newX, newY;
        if(out & top){
            newX = x1 + (y_max - y1)*1/m;
            newY = y_max;
        }else if(out & left){
            newX = x_min; 
            newY = y1 + m*(x_min - x1);
        }else if(out & bottom){
            newX = x1 + (y_min - y1)*1/m;
            newY = y_min;
        }else if(out & right){
            newX = x_max; 
            newY = y1 + m*(x_max - x1);
        }

        if(out == code1){
            x1 = newX;
            y1 = newY;
            code1 = RegionCode(x1,y1);
        }else{
            x2 = newX;
            y2 = newY;
            code2 = RegionCode(x2,y2);
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    } else {
        printf("Line rejected (no part inside viewport");
    }
}