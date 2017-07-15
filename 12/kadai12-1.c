/*
 講義名 : プログラミング演習1
 課題番号 : 講義12
 問題番号 : 問題1
 作成年月日 : 2017/7/4
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : バイナリツリーへの挿入
 */

/********************** ヘッダファイルの宣言 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define bool int
#define true 1
#define false 0

/*****************************************************************/

struct node {
    char key[20];                /* 単語を格納 */
    int count;                   /* 単語の登録回数（出現頻度）を格納 */
    struct node *left, *right;   /* 左右の子へのポインタ */
};
typedef struct node CELL;

CELL *tinsert(CELL *p, char *name); /* 2分探索木に単語を登録する関数 */
int inorder(CELL *p);          /* 間順走査を行う関数 */
CELL *search(CELL *p, char *name);/* 2分探索木を探索する関数 xcodeの開発環境だとsearch.hのtsearch() と干渉したのでとりあえず置き換え */




int main(void)
{
    /************** 変数の宣言，必要ならば追加してもよい *************/
    CELL *root, *p;
    
    char name[20];
    char sfn[] = "the_constitution_of_the_usa.txt";
    //char sfn[] = "shakespeare.txt";
    FILE *sfp;
    
    /******************* 入力ファイルをオープンする ******************/
    sfp = fopen(sfn, "r");
    
    /*****************************************************************/
    
    printf("\n**************************\n");
    printf("入力ファイル名: %s\n\n", sfn);
    root=NULL;
    
    /*** ファイルから単語を読み込んで単語登録を行う関数を呼び出し，***/
    /*** 2分探索木に登録                                           ***/
    /*** 1つ目に読み込む単語は，節点のアドレスをrootに格納すること ***/
    
    char trash[20];
    while (fscanf(sfp, "%[A-Za-z0-9]",name) != EOF) {//スキャン集合指定子を使えば例外を一文字づつ指定しなくてもいいしなんならまとめて読み込める
        fscanf(sfp, "%[^A-Za-z0-9]",trash);//無限ループさせないために補集合を入れてバッファが必ず進む保証をする
        
        bool useable = true;
        for (int i = 0; name[i] != '\0'; i++) {
            if (isalpha(name[i])) {
                name[i] = tolower(name[i]);
            }else{
                useable = false;
            }
        }
        if (useable){
            root = tinsert(root, name);
            
        }
        
    }
    
    
    
    
    
    
    /*****************************************************************/
    
    printf("*** 単語の出現頻度 ***\n");
    
    /****** 間順走査を行って，2分探索木のデータを画面に表示する ******/
    /*          ヒント： 間順走査を行う再帰的関数を呼び出す          */
    
    printf("\n%d種類の単語を登録\n",inorder(root));
    
    
    
    
    /*****************************************************************/
    
    while(true){
        printf("\n単語, または00を入力して下さい（00なら終了します）:  ");
        scanf("%s", name);
        
        /*** 単語を入力させ，2分探索木を探索する再帰的関数を呼び出し， ***/
        /*** その単語が登録されているかどうかを調べる                  ***/
        /*** 00 が入力されるまで繰り返す                               ***/
        
        if (strcmp(name, "00") == 0) {
            break;
        }
        
        
        if((p = search(root, name)) == NULL){
            printf("%sは登録されていません!\n", name);
        }else{
            printf("%sの出現頻度: %d\n",name,p->count);
        }
        
        
    }
    
    
    /*****************************************************************/
    
    printf("終了します．\n");
    
    /******************* 入力ファイルをクローズする ******************/
    fclose(sfp);
    
    /*****************************************************************/
    return 0;
}

/* 2分探索木に単語を登録する再帰的関数 */
CELL *tinsert(CELL *p, char *name)
{
    //int ind;
    
    if (p==NULL){
        p=(CELL *)malloc(sizeof(CELL));
        strcpy(p->key, name);
        p->count=1;
        p->left = p->right = NULL;
        
    }
    
    /************* p が NULL ではない場合の処理を記述する ************/
    /* ヒント: データの比較を行う  →                                */
    /*         探している単語は自分? 左の子? 右の子?                 */
    /*         自分ならカウント増やす/左または右なら再帰的に呼び出す */
    
    else{
        
        if (strcmp(name, p->key) == 0) {
            p->count++;
        }else if(strcmp(name, p->key) < 0){
            p->left = tinsert(p->left, name);
        }else{
            p->right = tinsert(p->right, name);
        }
        
    }
    
    
    
    /*****************************************************************/
    
    return p;
}


/* 間順走査を行う再帰的関数 */
int inorder(CELL *p)
{
    /****** 間順走査を行って要素と頻度を表示する関数を完成させる *****/
    static int counter;
    
    if (p != NULL){
        if (p->left != NULL)  inorder(p->left);
        printf("%4d %s\n",p->count,p->key);
        //counter += p->count;
        counter ++;
        if (p->right != NULL) inorder(p->right);
        
    }
    
    
    return counter;
    /*****************************************************************/
    
}


/* 2分探索木を探索する再帰的関数 */
CELL *search(CELL *p, char *name)
{
    //int ind;
    
    if (p!=NULL) {
        /************* p が NULL ではない場合の処理を記述する ************/
        /* ヒント: データの比較を行う  →                                */
        /*         探している単語は自分? 左の子? 右の子?                 */
        /*         自分ならポインタを返す/左または右なら再帰的に呼び出す */
        
        
        if (strcmp(name, p->key) == 0) {
            //self
            return p;
        }else if(strcmp(name, p->key) < 0){
            //left
            return search(p->left, name);
        }else{
            //right
            return search(p->right,name);
        }
        
        
        /*****************************************************************/
    }
    
    else {
        return NULL;
    }
    
    return NULL;
}



