#include<stdio.h>


void TOH(int n, char src[], char aux[], char dest[]){
    static int step=1;
    if(n<=0){
        printf("invalid");
        return;
    }
    if(n==1){
        printf("step (%02d) disc %02d  %5s --> to --> %-5s \n", step, n, src, dest);
        step++;
        return;
    }

    TOH(n-1,src,dest,aux);
    printf("step (%02d) disc %02d  %5s --> to --> %-5s \n",step, n, src, dest);
    step++;
    TOH(n-1,aux,src,dest);

}


int main(){
    int n;
    
    printf("enter the number of disks: ");
    scanf("%d",&n);
    TOH(n,"src","aux","dest");


    return 0;
}