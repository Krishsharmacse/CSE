#include<stdio.h>
#include<limits.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int memo[10000] = {0};
int coinChange(int* coins, int coinsSize, int amount){
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    if(memo[amount]) return memo[amount] == INT_MAX ? -1: memo[amount];

    int res = INT_MAX;
    for(int i=0; i < coinsSize; i++){
        int sub = amount - coins[i];
        int subRes = coinChange(coins, coinsSize, sub);
        if (subRes != -1) {  
            res = MIN(res, subRes + 1);
        }
    }
    memo[amount] = res;
    return (res == INT_MAX) ? -1: res;
}


int main(){
    int coins[] = {2};
    int amount = 3;
    printf("%d\n", coinChange(coins, 1, amount));
}