// g++ 2D_transformation.cpp -o 2D_transformation.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && 2D_transformation.exe

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define V 3


void createPolygon(int (*coordinates)[3], int color);
template <typename T>
void generate(T (*Matrix)[3], int (*coordinates)[3],int (*res)[3]);


int main(){
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode, (char*)"");

    int coordinates[V][3] = {
        {-50,  0, 1},
        {50  ,0, 1},
        {0 ,  50, 1},
    };   
    
    int res[V][3] = {0};
    int sx = 3, sy = 2;
    int Scale[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };   
    
    createPolygon(coordinates, 3);
    generate(Scale, coordinates, res);    
    createPolygon(res, 15);
    
    getch();
    closegraph();
    
}


template <typename T>
void generate(T (*Matrix)[3], int (*coordinates)[3],int (*res)[3]){
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < 3; j++) {
            res[i][j] = 0;
           for(int k = 0; k < 3; k++){
                res[i][j] += Matrix[j][k] * coordinates[i][k];    
           }
        }
    } 
}




void createPolygon(int (*coordinates)[3], int color){
    int xc = getmaxx()/2, yc = getmaxy()/2;
    setcolor(color);
    for(int i = 0; i < V; i++){
        int x1 = xc + coordinates[i%(V)][0],     y1 = yc - coordinates[i%(V)][1];
        int x2 = xc + coordinates[(i+1)%(V)][0], y2 = yc - coordinates[(i+1)%(V)][1];
        line(x1, y1, x2, y2);
    }
}