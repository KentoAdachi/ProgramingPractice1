#include<stdio.h>

int main(){

    int i, a[5] = {3,4,0,-2,5};
    for (int i = 0; i<5; i++) {
        printf("&a[%d] = %p, a[%d] = %d\n",i,&a[i],i,a[i]);
    }
    for (int i = 0; i<5; i++) {
        printf("a+%d = %p, *(a+%d)=%d\n",i,a+i,i,*(a+i));
    }

}
