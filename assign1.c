#include <stdio.h>
#include <math.h>
#include "assign1.h"

int quick_power(int x,int n);
int main() {
    printf("%d", quick_power(4,3));
    return 0;
}
int quick_power(int x, int n){
    int part_factor;
    int ans;
    if (n==0){
        return 1;
    }
    part_factor= quick_power(x,floor(n/2));
    if (n%2!=0){
        return (part_factor*part_factor*x)%(MODULO);
    }
    else{
        return (part_factor*part_factor)%(MODULO);
    }
}