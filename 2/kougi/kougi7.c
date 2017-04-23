#include<stdio.h>
#include<stdlib.h>
int main(){

    int a[5][4];
    
    int ** array;
    
    array = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++) {
        array[i] = (int *)malloc(sizeof(int) * 4);
    }
    
    for (int i = 0; i < 5; i++) {
        free(array[i]);
    }
    
    free(array);
}
