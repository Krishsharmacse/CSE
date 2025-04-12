// g++ Circle.cpp -o Circle.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && Circle.exe

#include<stdio.h>
#include<graphics.h>
#include<conio.h>


void Brasenham_line(int x1,int y1,int x2,int y2);
void PutPixels(int xc, int yc,int x, int y, int color);
void Bresenham_circle(int x1, int y1, int r);



int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    printf("%d %d", getmaxx(), getmaxy());

    Bresenham_circle(300,250,200);
    getch();
    closegraph();

    return 0;
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


void PutPixels(int xc, int yc, int x, int y, int color) {

    putpixel(xc + x, yc + y , color);
    putpixel(xc + y, yc + x , color);

    putpixel(xc + x, yc - y , color);
    putpixel(xc - y, yc + x , color);
    
    putpixel(xc - x, yc + y , color);
    putpixel(xc + y, yc - x , color);
    
    putpixel(xc - x, yc - y , color);
    putpixel(xc - y, yc - x , color);


    // filled circle
    // for (int i = xc - x; i <= xc + x; i++) {
    //     putpixel(i, yc - y, RGB(1, 92, 146)); //upper 
    //     putpixel(i, yc + y, RGB(188, 230, 255));
    // }

    // for (int i = xc - y; i <= xc + y; i++) {
    //     putpixel(i, yc + x, RGB(136, 205, 246));
    //     putpixel(i, yc - x, RGB(45, 130, 181));
    // }
}


// Function to draw a circle using Bresenham's algorithm
void Bresenham_circle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r; 


    
    while (x<=y){
        PutPixels(xc, yc, x , y, RED); 
        //thick circle 
        PutPixels(xc, yc, x, y-1, RED); 
        PutPixels(xc, yc, x, y-2, RED); 
        
        //dotted circle
        // if(x % 15 < 4) PutPixels(xc, yc, x , y, RED);
        
        // //dotted thick circle
        // if(x % 15 < 4){
        //     PutPixels(xc, yc, x , y, RED);  
        //     PutPixels(xc, yc, x, y-1, RED); 
        //     PutPixels(xc, yc, x, y-2, RED); 
        // }
        
        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        x++;
    }   
}
