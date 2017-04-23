#include<stdio.h>
#include<stdlib.h>
typedef struct score{
    char name[10];
    int math;
    int physics;
    float avarage;

} SCORE;

int main(){

    int *pi = (int *)malloc(sizeof(int) * 10);
    char *pc = (char *)malloc(sizeof(char) * 256);
    SCORE *ps = (SCORE *)malloc(sizeof(SCORE) * 5);
    printf("insert name : ");
    scanf("%s",ps->name);
    printf("%s\n",ps->name);
}
