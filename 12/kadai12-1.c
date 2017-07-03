/*
 講義名 : プログラミング演習1
 課題番号 : 講義11
 問題番号 : 問題2
 作成年月日 : 2017/6/30
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : 整列リストへの番兵を用いた線形探索による挿入
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    int data;
    struct list *next;
} LIST;

// リストの先頭と最後を指すためのポインタ
LIST *listhead = NULL;
LIST *listtail = NULL;
LIST *sentinel = NULL;

void end(){
    if (listhead != NULL) {
        LIST *q = NULL;
        for (LIST *p = listhead; p != NULL;) {
            q = p;
            
            p = p->next;
            free(q);
            
        }
        printf("挿入操作を終了します\n");
    }
}

// リストを表示する関数(再帰的関数)
void showlist( LIST *p ) {
    
    if ( p == NULL )
        printf( "\n" );
    else {
        printf( "-> %d ", p->data );
        showlist( p->next );
    }
    return;
}


int main( int argc, char *argv[] ) {
    int dat;       // 整数を一時的に保存
    int counter;   // データが何個目にあるかを示す変数
    LIST *p;       // リスト型の一時ポインタ
    
    
    // リスト表示
    
    
    listhead = (LIST *)malloc(sizeof(LIST));
    listhead->data = 0;//まあダミーなんだけどね
    listhead->next = NULL;
    listtail = listhead;
    
    
    // 探索
    while ( 1 ) {
        printf("挿入するデータがありますか : ");
        char yn[10];
        scanf("%s",yn);
        if (strcmp(yn, "no") == 0) {
            break;
        }
        printf( "データを入力してください : " );
        scanf("%d", &dat );
        
        
        
        //番兵をくっつける
        sentinel = (LIST *)malloc(sizeof(LIST));
        sentinel->data = dat;
        sentinel->next = NULL;
        listtail->next = sentinel;
        
        
        if ( dat == -1 ) break;
        
        p = listhead;
        counter = 0;
        while( p != NULL ) {
            if ( p->data == dat )
                break;
            else
                p = p->next;
            counter++;
        }
        
        if ( p->next != NULL ){
            printf( "%dは%d個目に登録されています\n", dat, counter );
            listtail->next = NULL;
            free(sentinel);
        }else{
            printf( "%dは登録されていません\n", dat );
            listtail->next = NULL;
            for (p = listhead;p->next != NULL && p->next->data < dat ; p = p->next) {
                
            }
            sentinel->next = p->next;
            p->next = sentinel;
            
            
            for (p = listhead;p->next != NULL; p = p->next) {
                
            }
            listtail = p;
            
            
        }
        showlist( listhead->next );
    }
    end();
    
    
    return 0;
}
