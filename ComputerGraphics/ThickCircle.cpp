// #include<stdio.h>
// #include<graphics.h>
// #include<conio.h>
 
// void PutPixels(int xc, int yc,int x, int y, int color);
// void Bresenham_circle(int x1, int y1, int r);
 
// int main(){
//     int gd = DETECT, gm;
//     initgraph(&gd,&gm,(char*)"");
 
//     Bresenham_circle(getmaxx()/2,getmaxy()/2,200);
 
//     getch();
//     closegraph();
 
//     return 0;
// }
  
// void PutPixels(int xc, int yc, int x, int y, int color) {
//     putpixel(xc + x, yc + y, color);
//     putpixel(xc + y, yc + x, color);
 
//     putpixel(xc + x, yc - y, color);
//     putpixel(xc - y, yc + x, color);
    
//     putpixel(xc - x, yc + y, color);
//     putpixel(xc + y, yc - x, color);
    
//     putpixel(xc - x, yc - y, color);
//     putpixel(xc - y, yc - x, color);
// }
 
// void Bresenham_circle(int xc, int yc, int r) {
//     int x = 0, y = r;
//     int d = 3 - 2 * r; 
//     while (x<=y){      
//         //dotted thick circle
//         if(x % 15 < 4){
//             PutPixels(xc, yc, x-1 , y, RED);  
//             PutPixels(xc, yc, x+1 , y, RED);  
//             PutPixels(xc, yc, x, y-1, RED); 
//             PutPixels(xc, yc, x, y+1, RED); 
//         }
 
//         if (d <= 0) {
//             d = d + 4 * x + 6;
//         } else {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         x++;
 
//     }   
// } 


#include<stdio.h>
#include<graphics.h>
#include<conio.h>
 
void PutPixelEllipse(int xc, int yc, int x, int y, int color);
void drawEllipse(int xc, int yc, int a, int b);
 
int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
 
    int xc = getmaxx()/2, yc = getmaxy()/2;
 
    drawEllipse(xc, yc, 100, 60);
    getch();
    closegraph();
 
    return 0;
}
 
void PutPixelEllipse(int xc, int yc, int x, int y, int color){
    putpixel(xc + x, yc + y, color); 
    putpixel(xc - x, yc + y, color);  
    putpixel(xc + x, yc - y, color); 
    putpixel(xc - x, yc - y, color); 
}
 
void drawEllipse(int xc, int yc, int a, int b){
    int x = 0, y = b; 
    int a2 = a * a;
    int b2 = b * b;
 
    //Region 1
    float P = b2 - (a2 * b) + (0.25 * a2); 
    while ((b2 * x) <= ( a2 * y)) {  
        PutPixelEllipse(xc, yc, x, y, 2);
        
        if (P <= 0) {
            P = P + b2 * (2 * x + 3); 
        } else {
            y--;
            P = P + b2 * (2 * x + 3) - a2 * (2 * y - 2);  
        }
        x++;
    }
    //Region 2:
    float Q = (b2 * (x + 0.5) * (x + 0.5)) + (a2 * (y - 1) * (y - 1)) - (a2 * b2);
    while (y >= 0) { 
        PutPixelEllipse(xc, yc, x, y, 2);
 
        if (Q > 0) {
            Q = Q - a2 * (2 * y - 3);  
        } else {
            x++;
            Q = Q + b2 * (2 * x + 2) - a2 * (2 * y - 3);  
        }
        y--;
    }
}
