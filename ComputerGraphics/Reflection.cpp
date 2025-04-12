// g++ Reflection.cpp -o Reflection.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && Reflection.exe

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define V 5

void createPolygon(int (*coordinates)[3], int color);
template <typename T>
void generate(T (*Matrix)[3], int (*coordinates)[3],int (*res)[3]);


int main(){
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode, (char*)"");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(15);
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

    outtextxy(getmaxx()/2 + 5, 2, (char*)"y");
    outtextxy(getmaxx()/2 + 5, getmaxy()-20, (char*)"-y");

    outtextxy(getmaxx()-20, getmaxy()/2 - 20, (char*)"x");
    outtextxy(2, getmaxy()/2-20, (char*)"-x");

    outtextxy(getmaxx()/2+5, getmaxy()/2-20, (char*)"(0,0)");

    // polygon coordinates (x,y,h)
    int coordinates[V][3] = {
        {50, 50, 1},
        {150, 50, 1},
        {150, 150, 1},
        {100, 200, 1},
        {50, 150, 1},
    };
    
    int Transformation[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int ReflectionX[3][3] = {
        {1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };
    int ReflectionY[3][3] = {
        {-1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    int ReflectionOrigin[3][3] = {
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, 1}
    };

    int res[V][3] = {0};
    createPolygon(coordinates, GREEN);

    generate(ReflectionX, coordinates, res);    
    createPolygon(res, 1);
    generate(ReflectionY, coordinates, res);    
    createPolygon(res, 4);
    generate(ReflectionOrigin, coordinates, res);    
    createPolygon(res, 3);
   
    getch();
    closegraph();
    
}

void createPolygon(int (*coordinates)[3], int color);
template <typename T>
void generate(T (*Matrix)[3], int (*coordinates)[3],int (*res)[3]){
    for(int i = 0; i < V; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = 0;
            for(int k = 0; k< 3; k++){
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

