#include<stdio.h>

int main(){

    int i = 5, *pi;
    
    pi = &i;
    
    printf("i = %d, &i=%p\n",i,&i);
    printf("pi = %p,&pi = %p, *pi=%d\n",pi,&pi,*pi);

}
