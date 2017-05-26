/*
 課題番号 : 課題6
 問題番号 : 問題1
 作成年月日 : 2017/05/24
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
    char c;
    struct cell *next;
} Cell;

Cell *stack;


int malloc_s(Cell **p){
    if ((*p = (Cell *)malloc(sizeof(Cell))) == NULL) {
        printf("malloc error\n");
        exit(EOF);
    }
    return 0;
}

void push(char c){
    Cell *data;
    malloc_s(&data);
    data->c = c;
    data->next = stack;
    stack = data;

}

char pop(){
    if (stack == NULL) {
        exit(EOF);
    }
    char c = stack->c;
    Cell *p = stack;
    stack = stack->next;
    free(p);
    return c;
}

void free_stack(){
    if (stack != NULL) {
        Cell *q = NULL;
        for (Cell *p = stack; p != NULL;) {
            q = p;

            p = p->next;
            free(q);
        }
    }
}

void print_stack(){

    for (Cell *p = stack; p != NULL; p = p->next) {
        printf("%c",p->c);
    }
    printf("\n");
}


int main (){

    while (1) {
        char in[256];
        printf("モードを入力 :\n");
        scanf("%s",in);

        if (strcmp(in, "end") == 0) {
            free_stack();
            break;
        }else if (strcmp(in, "pop") == 0) {
            printf("%c\n",pop());
            print_stack();
        }else if (strlen(in) == 1){
            push(in[0]);
            print_stack();
        } else{

          printf("不正な入力です\n");
        }

    }

}
