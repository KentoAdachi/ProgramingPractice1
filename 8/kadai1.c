/*
 課題番号 : 講義8
 問題番号 : 問題1
 作成年月日 : 2017/6/6
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : スタックの応用演習 - 括弧の包含関係の整合性の確認
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
    char c;
    if (stack == NULL) {
        //        printf("プログラムを終了します\n");
        //        exit(0);
        //        printf("スタックは空です\n");
        c = '\0';
    }else{
        c = stack->c;
        Cell *p = stack;
        stack = stack->next;
        free(p);
    }
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
        stack = NULL;//解放したアドレスをpopしないように追記
        printf("スタックを解放しました\n");
    }
}

void clr_stack(){
    
}

int count_stack(){
    int return_value = 0;//スタックの要素数を返す
    if (stack == NULL) {
        //printf("stack is empty\n");
    }else{
        for (Cell *p = stack; p != NULL; p = p->next) {
            //printf("->%c",p->c);
            return_value++;
        }
        //printf("\n");
    }
    
    return return_value;
}

int decide(char c){
    int return_value = 0;
    if (c == '(') {
        // (が来たらaをpush
        push('a');//'('に対応したトークンを送信
        count_stack();
    }else if (c == '<') {
        // <が来たらbをpush
        push('b');
        count_stack();
    }else if (c == ')') {
        // )が来たらaをpop <-成功するか判断
        if (pop() == 'a') {
            //printf("correct a : success\n");
            return_value = 0;
        }else{
            //printf("correct a : failure\n");
            return_value = -1;
        }
    }else if (c == '>') {
        // >が来たらbをpop <-成功するか判断
        if (pop() == 'b') {
            //printf("correct b : success\n");
            return_value =  0;
        }else{
            //printf("correct b : failure\n");
            return_value =  -1;
        }
    }
    return return_value;
    
}


int main(){
    char s[256];
    while (1){
        int flag = 0;
        printf("チェックする文字列かendを入力してください--> ");
        scanf("%s",s);
        if (strcmp(s, "end") == 0) {
            printf("プログラムを終了します.\n");
            break;
        }
        for (int i = 0; i < strlen(s); i++) {
            if(decide(s[i]) == -1){
                flag =1;
            }
        }
        if (flag == 1 | count_stack() != 0) {
            printf("正しくない.\n");
            free_stack();
        }else{
            printf("正しい.\n");
        }
    }
}








