
// g++ Line.cpp -o Line.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && Line.exe

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include <iostream>


void DDAline(int x1,int x2,int y1,int y2);
void Brasenham_line(int x1,int y1,int x2,int y2);






int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    printf("%d %d", getmaxx(), getmaxy());

    // DDAline(-200,0,200,0);
    Brasenham_line(100,200,500,50);
    // while (!kbhit()) {
    //     if (GetAsyncKeyState(VK_LBUTTON)){  // Check if the left button is clicked
    //         int x =  mousex(), y =  mousey();
    //         putpixel(x,y,BLUE);
    //         putpixel(x+1,y,BLUE);
    //         putpixel(x-1,y,BLUE);
    //         putpixel(x,y+1,BLUE);
    //         putpixel(x,y-1,BLUE);
            
    //         putpixel(x+1,y+2,BLUE);
    //         delay(5);            
    //     }
    // }
    getch();
    closegraph();

    return 0;
}


void DDAline(int x1,int y1,int x2,int y2){

    x1 += getmaxx()/2;
    y1 = getmaxy()/2 - y1;
    x2 += getmaxx()/2;
    y2 = getmaxy()/2 - y2;

    int dx = x2-x1, dy = y2-y1;
    int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    
    float xinc = (float)dx / step;
    float yinc = (float)dy / step;

    for(int i = 0; i < step; i++){
        if (i % 10 < 5) { // Creates a dashed effect
            putpixel(round(x1), round(y1), RED);
        }
        x1 += xinc;
        y1 += yinc;
    }
    
}



void Brasenham_line(int x1,int y1,int x2,int y2){
    int dx = x2-x1, dy = y2-y1;
    int p = 2*dy - dx;

    
    while(x1 < x2){
        putpixel(x1,y1,RED);
        x1++;
        if(p <= 0) p = p +2*dy;
        else {
            y1++;
            p = p + 2*dy -2*dx;
        }
    }
}



void Brasenham_line_h(int x1,int y1,int x2,int y2){

    int dx = x2-x1, dy = y2-y1;
    int dir = dy < 0 ? -1 : 1;
    dy *= dir;

    int p = 2*dy - dx;

    
    while(x1 < x2){
        putpixel(x1,y1,RED);
        x1++;
        if(p <= 0) p = p +2*dy;
        else {
            y1+=dir;
            p = p + 2*dy -2*dx;
        }
    }
}

void Brasenham_line_v(int x1,int y1,int x2,int y2){

}
