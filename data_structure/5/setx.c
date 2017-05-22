#include <stdio.h>

void setX(int *x){
    *x=2;
}

int main() {
  int x=1;
  setX(&x);
  printf("x = %d\n",x);
}
