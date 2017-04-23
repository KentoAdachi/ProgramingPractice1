#include<stdio.h>

int main(){

    int *p;
    p = (int *)malloc(sizeof(int) * 5);
    free(p);
}
