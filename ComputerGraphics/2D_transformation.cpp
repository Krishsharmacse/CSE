// g++ 2D_transformation.cpp -o 2D_transformation.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && 2D_transformation.exe

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;


class Transformation{
    int **Coordinates;
    int V;
    int color = 1;
    public:
        Transformation(int (*Matrix)[3], int vertices){
            V = vertices;
            Coordinates = (int**)malloc(V * sizeof(int*));
            for(int i=0; i<V; i++){
                Coordinates[i] = (int*)calloc(3, sizeof(int));
                for(int j = 0; j<3;j++){
                    Coordinates[i][j] = Matrix[i][j];
                }
            }
        }

        Transformation(int (*Matrix)[3], int vertices, int color){
            V = vertices;
            this->color = color;
            Coordinates = (int**)malloc(V * sizeof(int*));
            for(int i=0; i<V; i++){
                Coordinates[i] = (int*)calloc(3, sizeof(int));
                for(int j = 0; j<3;j++){
                    Coordinates[i][j] = Matrix[i][j];
                }
            }
        }

        void SetColor(int color){
            this->color = color;
        }

        void updateCoordinates(int **Matrix, int vertices){
            V = vertices;
            for(int i=0; i<V; i++){
                for(int j = 0; j<3;j++){
                    Coordinates[i][j] = Matrix[i][j];
                }
            }
        }
        void updateCoordinates(int (*Matrix)[3], int vertices){
            V = vertices;
            for(int i=0; i<V; i++){
                for(int j = 0; j<3;j++){
                    Coordinates[i][j] = Matrix[i][j];
                }
            }
        }

        int **Translate(int tx, int ty){
            int **Matrix = (int**)malloc(3 * sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[0][2] = tx;
            Matrix[1][2] = ty;

            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;
        }

        int **Rotate(double angle){
            double **Matrix = (double**)malloc(3 * sizeof(double*));
            for(int i=0; i<3; i++){
                Matrix[i] = (double*)calloc(3, sizeof(double));
                Matrix[i][i] = 1.0;
            }
            Matrix[0][0] = cos(angle);
            Matrix[0][1] = -sin(angle);
            Matrix[1][0] = sin(angle);
            Matrix[1][1] = cos(angle);
            
            
            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;

        }
        int **Scale(int sx, int sy){
            int **Matrix = (int**)malloc(3 * sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[0][0] = sx;
            Matrix[1][1] = sy;

            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;


        } 

        int ** ReflectX(){
            int **Matrix = (int**)malloc(3* sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[0][0] = -1;

            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;

        }
        int ** ReflectY(){
            int **Matrix = (int**)malloc(3* sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[1][1] = -1;
            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;

        }

        int ** ReflectOrigin(){
            int **Matrix = (int**)malloc(3* sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[0][0] = -1;
            Matrix[1][1] = -1;

            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;

        }

        int ** Shear(int shx, int shy){
            int **Matrix = (int**)malloc(3 * sizeof(int*));
            for(int i=0; i<3; i++){
                Matrix[i] = (int*)calloc(3, sizeof(int));
                Matrix[i][i] = 1;
            }
            Matrix[0][1] = shx;
            Matrix[1][0] = shy;

            int **M = generateMatrix(Matrix);
            createPolygon(M);
            return M;

        }

        void DrawAxis(int c = 15){
            setcolor(c);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
            line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

            outtextxy(getmaxx()/2 + 5, 2, (char*)"y");
            outtextxy(getmaxx()/2 + 5, getmaxy()-20, (char*)"-y");

            outtextxy(getmaxx()-20, getmaxy()/2 - 20, (char*)"x");
            outtextxy(2, getmaxy()/2-20, (char*)"-x");

            outtextxy(getmaxx()/2+5, getmaxy()/2-20, (char*)"(0,0)");
        }



        template<typename T>
        int** generateMatrix(T (*Matrix)[3]){
            int **res = (int**)malloc(V * sizeof(int*));
            for(int i=0; i<V; i++){
                res[i] = (int*)calloc(3, sizeof(int));
            }
            
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < 3; j++) {
                    res[i][j] = 0;
                   for(int k = 0; k < 3; k++){
                        res[i][j] += Matrix[j][k] * Coordinates[i][k];    
                   }
                }
            } 
            return res;
        }


        template<typename T>
        int** generateMatrix(T **Matrix){
            int **res = (int**)malloc(V * sizeof(int*));
            for(int i=0; i<V; i++){
                res[i] = (int*)calloc(3, sizeof(int));
            }
            
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < 3; j++) {
                    res[i][j] = 0;
                   for(int k = 0; k < 3; k++){
                        res[i][j] += Matrix[j][k] * Coordinates[i][k];    
                   }
                }
            } 
            return res;
        }

        void createPolygon(){
            int xc = getmaxx()/2, yc = getmaxy()/2;
            setcolor(color);
            for(int i = 0; i < V; i++){
                int x1 = xc + Coordinates[i%(V)][0],     y1 = yc - Coordinates[i%(V)][1];
                int x2 = xc + Coordinates[(i+1)%(V)][0], y2 = yc - Coordinates[(i+1)%(V)][1];
                line(x1, y1, x2, y2);
            }
        }
        void createPolygon(int **Matrix){
            int xc = getmaxx()/2, yc = getmaxy()/2;
            setcolor(color);
            for(int i = 0; i < V; i++){
                int x1 = xc + Matrix[i%(V)][0],     y1 = yc - Matrix[i%(V)][1];
                int x2 = xc + Matrix[(i+1)%(V)][0], y2 = yc - Matrix[(i+1)%(V)][1];
                line(x1, y1, x2, y2);
            }
        }

    private:
        template<typename T>
        void PrintMatrix(T **Arr){
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < 3; j++) {
                    cout << Arr[i][j] << " ";
                }
                printf("\n");
            } 
            printf("\n\n");
        }

};

int main(){
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode, (char*)"");
    int V = 4; 
    
    int coordinates[V][3] = {
        {-100 ,  -100, 1},
        {-50,  -100, 1},
        {-50  ,-50, 1},
        {-100 ,  -50, 1},
    }; 

    Transformation obj(coordinates, V);
    obj.createPolygon();
    // obj.SetColor(15);
    // obj.Translate(0,200);
    // obj.SetColor(14);
    // obj.Shear(1,0);
    // obj.SetColor(13);
    // obj.Scale(2,3);
    // obj.SetColor(12);
    // obj.Rotate(M_PI/3);


    
    int **res;
    for(int i = 1; i<=100; i+=5){
        cleardevice();
        res = obj.Translate(i,i);
        delay(100);
    }

    obj.updateCoordinates(res, V);
    
    for(int i = 1; i<=4*M_PI; i++){
        cleardevice();
        res = obj.Rotate(i);
        delay(100);
    }
    obj.updateCoordinates(res, V);

    for(int i = 1; i<=4; i++){
        cleardevice();
        res = obj.Scale(i,i);
        delay(100);
    }
    
    obj.updateCoordinates(res, V);

    
    getch();
    closegraph();
    
}