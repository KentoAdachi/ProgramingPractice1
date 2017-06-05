/*
 課題番号 : 講義7
 問題番号 : 問題1
 作成年月日 : 2017/05/31
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : 単方向リスト構造を用いたキューの作成
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct cell {
    double num;
    struct cell *next;
} Cell;

Cell  *listhead;
Cell  *listtail;

void enq();
void deq();
void show();
void end();

//エラー表示付きのmalloc_single
void malloc_s(Cell **dp){
    if((*dp = malloc(sizeof(Cell))) == NULL){
        printf("malloc error\n");
        exit(EOF);
    }
}

//データの追加
void enq(){
    double data;
    printf("追加する値を入力してください : ");
    scanf("%lf",&data);
    
    
    if (listhead == NULL) {
        malloc_s(&listhead);
        listhead->num = data;
        listhead->next = NULL;
        listtail = listhead;
    }else{
        Cell *p;
        malloc_s(&p);
        p->num = data;
        p->next = NULL;
        listtail->next = p;
        listtail = p;
    }
    
    show();
    
}

//削除
void deq(){
    if (listhead == NULL) {
        end();
    }else{
        printf("%f はキューから削除されました.\n",listhead->num);
        Cell *p = listhead;
        listhead = listhead->next;
        free(p);
    }
    
    show();
}

//表示 ->enq(),deq()
void show(){
    Cell *p;
    printf("キュー内のデータ : ");
    for (p = listhead; p != NULL; p = p->next) {
        printf(" -> %f",p->num);
    }
    printf("\n");
}

//終了
void end(){
    //リストが空になるまでdeqする
    while (listhead != NULL) {
        deq();
    }
    //空保証
    printf("キューは空です\nプログラムを終了します\n");
    free(listhead);
    exit(0);
}





int main(){
    //init
    
    while (1) {
        
        char s[128];
        printf("操作を選択(enq/deq/end) : ");
        scanf("%s",s);
        
        if (strcmp(s, "enq") == 0) {
            //call function
            enq();
        }
        if (strcmp(s, "deq") == 0) {
            //call function
            deq();
        }
        if (strcmp(s, "end") == 0) {
            //call function
            end();
        }
    }
}
