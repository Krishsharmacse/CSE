// g++ 2D_transformation.cpp -o 2D_transformation.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && 2D_transformation.exe

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void generate(int (*Matrix)[3], int (*coordinates)[3],int res[3][3]);
void createPolygon(int coordinates[][3], int rows);


int main(){
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode, (char*)"");

    int coordinates[3][3] = {
        {-50,0,1},
        {50,0,1},
        {0,-50,1},
    };
    
    int tx = 0, ty = 0;
    int Transformation[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };
    
    double angle = M_PI/2;
    double Rotation[3][3] = {
        {cos(angle), sin(angle), (double)tx},
        {sin(angle), cos(angle), (double)ty},
        {0, 0, 1}
    };

    int sx = 2, sy = 2;
    int Scale[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };
    
    int res[3][3];

    createPolygon(coordinates, 3);
    // generate(Transformation, coordinates, res);    
    // createPolygon(res, 3);
    
    // generate(Rotation, coordinates, res);
    // createPolygon(res, 3);

    generate(Scale, coordinates, res);
    createPolygon(res, 3);
    
    getch();
    closegraph();
    
}


void generate(int (*Matrix)[3], int (*coordinates)[3],int res[3][3]){
    for (int m = 0; m < 3; m++) {
        res[m][0] = Matrix[0][0]*coordinates[m][0] + Matrix[0][1]*coordinates[m][1] + Matrix[0][2]*coordinates[m][2];
        res[m][1] = Matrix[1][0]*coordinates[m][0] + Matrix[1][1]*coordinates[m][1] + Matrix[1][2]*coordinates[m][2];
        res[m][2] = 1; 
    } 
}


void createPolygon(int coordinates[][3], int rows){
    int xc = getmaxx()/2, yc = getmaxy()/2;
    for(int i = 0; i< rows; i++){
        int x1 = xc - coordinates[i%(rows)][0],     y1 = yc + coordinates[i%(rows)][1];
        int x2 = xc - coordinates[(i+1)%(rows)][0], y2 = yc + coordinates[(i+1)%(rows)][1];

        line(x1, y1, x2, y2);
    }
}