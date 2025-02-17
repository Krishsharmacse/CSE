
// g++ DDA.cpp -o DDA.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && DDA.exe

#include<stdio.h>
#include<graphics.h>
#include <conio.h>


void DDAline(int x1,int x2,int y1,int y2);
void Brasenham_line(int x1,int y1,int x2,int y2);
// void PutPixels(int x, int y, int i);
// void PutPixels(int xc, int yc,int x, int y, int color);
// void Bresenham_circle(int x1, int y1, int r);

// void PutPixelEllipse(int x, int y);
// void drawEllipse(int a, int b);

void PutPixelEllipse(int x, int y, int color) {
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    putpixel( x +  midx  ,  y + midy, WHITE); 
    putpixel(-x +  midx  ,  y + midy, WHITE);  
    putpixel( x +  midx  , -y + midy, WHITE); 
    putpixel(-x +  midx  , -y + midy, WHITE); 
}

void drawEllipse(int a, int b) {
    int x = 0, y = b;  // Start at (0, b)
    int a2 = a * a;
    int b2 = b * b;

    // **Region 1:**
    float P = b2 - (a2 * b) + (0.25 * a2);  // Initial decision parameter

    while ((2 * b2 * x) <= (2 * a2 * y)) {  // Until slope = -1
        PutPixelEllipse(x, y, WHITE);
        
        if (P <= 0) {
            P = P + b2 * (2 * x + 3);  // Move East
        } else {
            y--;
            P = P + b2 * (2 * x + 3) - a2 * (2 * y - 2);  // Move South-East
        }
        x++;
    }

    // **Region 2:**
    float Q = (b2 * (x + 0.5) * (x + 0.5)) + (a2 * (y - 1) * (y - 1)) - (a2 * b2);

    while (y >= 0) {  // Until ellipse completes
        PutPixelEllipse(x, y, WHITE);

        if (Q > 0) {
            Q = Q - a2 * (2 * y - 3);  // Move South
        } else {
            x++;
            Q = Q + b2 * (2 * x + 2) - a2 * (2 * y - 3);  // Move South-East
        }
        y--;
    }
}


int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    printf("%d %d", getmaxx(), getmaxy());

    // DDAline(0,0,200,200);
    // Brasenham_line(0,0,200,200);
    // Bresenham_circle(320,320,50);
    drawEllipse(100, 60);
    getch();
    closegraph();

    return 0;
}


void DDAline(int x1,int y1,int x2,int y2){

    x1 += getmaxx()/2;
    y1 = getmaxy()/2 + y1;
    x2 += getmaxx()/2;
    y2 = getmaxy()/2 + y2;

    int dx = x2-x1, dy = y2-y1;
    int step;
    if(dx > dy) step = dx;
    else step = dy;

    
    int xinc = dx/step;
    int yinc = dy/step;

    for(int i = 0; i < step; i++){
        x1 += xinc;
        y1 += yinc;
        putpixel(x1,x1, RED);
    }
    
}



void Brasenham_line(int x1,int y1,int x2,int y2){
    int dx = x2-x1, dy = y2-y1;
    int p = 2*dy - dx;

    
    putpixel(x1,y1,RED);
    while(x1 < x2){
        x1++;
        if(p <= 0) p = p +2*dy;
        else {
            y1++;
            p = p + 2*dy -2*dx;
        }
        putpixel(x1,y1,RED);
    }
}



// void PutPixels(int xc, int yc, int x, int y, int i) {

//     putpixel(xc+x, yc+y, i);
//     putpixel(yc+y, xc+x, i);

//     putpixel(xc+x, yc-y, i);
//     putpixel(yc-y, xc+x, i);

//     putpixel(xc-x, yc+y, i);
//     putpixel(yc+y, xc-x, i);

//     putpixel(xc-x, yc-y, i);
//     putpixel(yc-y, xc-x, i);
// }


// // Function to draw a circle using Bresenham's algorithm
// void Bresenham_circle(int xc, int yc, int r) {
//     int x = 0, y = r;
//     int d = 3 - 2 * r; 


    
//     while (x <= y) {
//         PutPixels(xc, yc, x , y, RED);  // Plot all symmetric points
//         x++;

//         if (d <= 0) {
//             d = d + 4 * x + 6;
//         } else {
//             y--;  // Fix: Decrease y instead of increasing
//             d = d + 4 * (x - y) + 10;
//         }

//         PutPixels(xc, yc, x , y, RED);  // Plot again after updating x, y
//     }   
// }





// void PutPixelEllipse(int x, int y){
    // putpixel( x +  getmaxx() / 2  ,  y + getmaxy() / 2, WHITE); 
    // putpixel(-x + getmaxx() / 2  ,  y + getmaxy() / 2, WHITE);  
    // putpixel( x +  getmaxx() / 2  , -y + getmaxy() / 2, WHITE); 
    // putpixel(-x + getmaxx() / 2  , -y + getmaxy() / 2, WHITE); 
// }

// void drawEllipse(int a, int b) {
//     int x = 0, y = b; // Start at (0, b)

//     // **Region 1:**
//     int a2 = a*a;
//     int b2 = b*b;
//     float P = b2 - (a2 * b) + (0.25 * a2); // Initial decision parameter P0

//     while ((2 * b2* x) <= (2 * a2 * y)) { // Until slope = -1
//         PutPixelEllipse(x, y);
        
//         if (P <= 0) {
//             P = P + b2 * (2*x + 3);  // Move East
//         } else {
//             P = P + b2 * (2*x + 3) - a2 * (2*y - 2);  // Move South-East
//             y--;
//         }
//         x++;
//     }

//     // **Region 2:**
//     float Q = (b2*(a+0.5)*(a+0.5)) + a2*(1-b2);

//     while (y >= 0) { // Until ellipse completes
//         PutPixelEllipse(x, y);

//         if (Q >= 0) {
//             Q = Q - a2*(2*y - 3);  // Move South-East
//         } else {
//             Q = Q + b2*(2*y+2) - a2*(2*y-3);  // Move South
//             x++;
//         }
//         y--;
//     }
// }