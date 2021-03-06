/*
課題番号 : 課題6
問題番号 : 問題2
作成年月日 : 2017/05/24
学籍番号 : BP16001
氏名 : 足立賢人
動作環境 : Xcode8.2.1 - MacOS Sierra

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//..i
typedef struct cell {
  char c;
  struct cell *next;
} Cell;

Cell *stack;//..ii


int malloc_s(Cell **p){
  if ((*p = (Cell *)malloc(sizeof(Cell))) == NULL) {
    printf("malloc error\n");
    exit(EOF);
  }
  return 0;
}

//編集禁止
void push(char c){
  Cell *data;
  malloc_s(&data);
  data->c = c;
  data->next = stack;
  stack = data;

}

//編集禁止
char pop(){
  if (stack == NULL) {
    printf("プログラムを終了します\n");
    exit(0);
  }
  char c = stack->c;
  Cell *p = stack;
  stack = stack->next;
  free(p);
  return c;
}

//..v
void free_stack(){
  if (stack != NULL) {
    Cell *q = NULL;
    for (Cell *p = stack; p != NULL;) {
      q = p;

      p = p->next;
      free(q);

    }
    printf("スタックを解放しました\n");
  }
}

void print_stack(){
  if (stack == NULL) {
    printf("stack is empty\n");
  }else{
    for (Cell *p = stack; p != NULL; p = p->next) {
      printf("%c",p->c);
    }
    printf("\n");
  }
}


int main (){

  while (1) {
    char in[256];

    printf("文字列かendを入力してください : ");
    scanf("%s",in);

    if (strcmp(in,"end") == 0) {
      printf("プログラムを終了します\n");
      free_stack();
      exit(0);
    }
    printf("%s",in);
    int i;
    for (i = 0;in[i] != '\0';i++) {
      push(in[i]);
    }
    for (;i > 0;i--) {
      printf("%c",pop());
    }
    printf("\n");

  }

}
