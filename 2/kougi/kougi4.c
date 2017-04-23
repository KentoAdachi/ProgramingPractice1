#include<stdio.h>

struct score {
    char name[10];
    int math;
    int physics;
    float average;
};
int main(){
    int *pI = (int *)malloc(sizeof(int));
    char *pC = (char *)malloc(sizeof(char));
    struct score *pS = (struct score *)malloc(sizeof(struct score));
}
