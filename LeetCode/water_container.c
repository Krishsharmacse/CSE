#include<stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int max=0;
    for(int i=0; i< heightSize; i++){
        for(int j = heightSize-1; j>0; j--){
            int area = MIN(height[i], height[j]) * (j-i);
            if( area > max){
                max = area; 
            }
        }
    }
    return max;
}


int main(){
    int h[] = {1,8,6,2,5,4,8,3,7};
    printf("%d", maxArea(h, 9));
}