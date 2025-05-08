#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

typedef struct {
    int x, y;
} Point;


long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

long long C(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

float bernstein(int i, int n, float u) {
    return C(n, i) * pow(1 - u, n - i) * pow(u, i);
}

Point bezierSurface(Point P[3][3], float u, float v) {
    Point P_uv = {0, 0};
    int m = 2, n = 2;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            float Bi = bernstein(i, m, u);
            float Bj = bernstein(j, n, v);
            float weight = Bi * Bj;
            P_uv.x += P[i][j].x * weight;
            P_uv.y += P[i][j].y * weight;
        }
    }
    return P_uv;
}

void PlotPoint(int x, int y, int COLOR){
    putpixel(x-1, y  , COLOR);
    putpixel(x+1, y  , COLOR);
    putpixel(x  , y  , COLOR);
    putpixel(x  , y+1, COLOR);
    putpixel(x  , y-1, COLOR);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
    cleardevice(); 

    Point P[3][3] = {
        {{100, 300}, {150, 200}, {200, 300}},
        {{150, 150}, {200, 100}, {250, 150}},
        {{200, 300}, {250, 200}, {300, 300}}
    };

    setcolor(BLACK);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            PlotPoint(P[i][j].x, P[i][j].y, BLACK);
        }
    }

    setcolor(RED);
    for (float u = 0; u <= 1; u += 0.01f) {
        for (float v = 0; v <= 1; v += 0.01f) {
            Point p = bezierSurface(P, u, v);
            putpixel(p.x, p.y, RED);
        }
    }

    getch();
    closegraph();
    return 0;
}
