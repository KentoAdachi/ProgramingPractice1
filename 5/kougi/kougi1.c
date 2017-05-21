/*
 課題番号 :課題5
 問題番号 :1
 作成年月日 :2017/5/20
 学籍番号 :BP16001
 氏名 :足立 賢人

 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "05data.csv"

struct LIST {
    int score;
    struct LIST *next;
};
typedef struct LIST LIST;


// リストを表示する関数
// ここに追加

void show_list(LIST * listhead){
    printf("Listhead");
    LIST *p;
    for (p = listhead; p != NULL; p = p->next) {
        printf(" -> %d",p->score);
    }
    printf("\n");
}





int main( void ) {
    int dat;
    LIST *listhead = NULL;  // リストの先頭へのポインタ
    LIST *listtail = NULL;  // リストの末尾へのポインタ
    LIST *p;                // 一時ポインタ
    FILE *fp;               // ファイルポインタ

    // ファイルを開く
    if ( ( fp = fopen( FILENAME, "r" ) ) == NULL ) {
        fprintf( stderr,"ファイルが開けません\n" );
        exit( 1 );
    }

    // 1個目のデータを読み込み、構造体リストに格納する
    fscanf( fp, "%d", &dat );
    //printf("%d\n",dat);
    p = ( LIST * )malloc( sizeof( LIST ) );
    p->score = dat;
    p->next = NULL;
    listhead = listtail = p;


    // 2個目以降のデータを読み込み、構造体リストに格納する
    while( fscanf( fp, "%d",  &dat) != EOF ) {

        p = (LIST *)malloc(sizeof(LIST));
        p->score = dat;
        //printf("%d\n",dat);
        p->next = NULL;

        listtail->next = p;
        listtail = p;


    }

    // リストに格納されたデータを表示する
    show_list( listhead );

    // リストのメモリを開放する
    // ここに追加
    LIST *temp = NULL;
    for (p = listhead; p != NULL; p = temp->next) {
        temp = p;
        //printf("free %p\n",p);
        free(p);

    }



    // ファイルを閉じる
    fclose( fp );
    return 0;
}
