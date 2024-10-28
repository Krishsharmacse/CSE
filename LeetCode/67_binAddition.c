#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int addBits(char a, char b, char Cin, int *Cout){
    int bitA = a - '0';
    int bitB = b - '0';
    int carryIn = Cin - '0';

    int sum = bitA ^ bitB ^ carryIn;
    *Cout = (bitA & bitB) | (bitA & carryIn) | (bitB & carryIn);

    return sum;
}

char* addBinary(char* a, char* b) {
    
}

int main(){
    int Cout;
    int sum = addBits('1','1','0', &Cout);
    printf("%d %d\n", sum, Cout);
}