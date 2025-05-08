#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
 
#define V 5 // number of vertices
 
void createPolygon(int (*coordinates)[3], int color);
template <typename T>
void generate(T (*Matrix)[3], int (*coordinates)[3],int (*res)[3]);
 
int main(){
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode, (char*)"");
 
    // polygon coordinates (x,y,h)
    int coordinates[V][3] = {
        {50  , 30, 1},
        {50  ,-10, 1},
        {-50, -10, 1},
        {-50 , 30, 1},
        {0 , 80, 1},
    };
    
    int Transformation[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    int tx = 0, ty = 100;
    int res[V][3] = {0};
    int i = 0, j = 0;
    while(i < tx || j < ty){
        cleardevice();
        Transformation[0][2] = i < tx ? i+=5 : tx;
        Transformation[1][2] = j < ty ? j+=5 : ty;
        generate(Transformation, coordinates, res);    
        createPolygon(res, GREEN);
 
        delay(100);
    }
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
