/*
 課題番号 :課題2
 問題番号 :問題2
 作成年月日 :2017/4/19
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100   //文字配列のサイズ（入力文字列の最大長さ＋１）

//文字列の画面出力用関数..9
void output_strings(char **array_p, int m)
{
    printf("%d\n",m);
    
    for (int i = 0; i < m; i++) {
        printf("%s\n",array_p[i]);
    }
    
    
}


int main( void )
{
    int i,j;
    int n;  //文字列の個数
    char data[MAX_LEN]={};  //入力用文字列
    char **str_p;
    char *p;
    
    //文字列の個数の入力 ..1
    printf("Number of strings : ");
    scanf("%d",&n);
    
    
    
    //文字列へのポインタを格納するポインタ配列の動的確保 ..2
    str_p = (char **)malloc(sizeof(char *) * n);
    if (str_p == NULL) {
        printf("error : memory could not be allocated\n");
        exit(EXIT_FAILURE);//異常終了
    }
    
    
    //iii〜vの処理
    //..5
    for (i = 0; i < n; i++) {
        //..3
        printf("Input strings : ");
        scanf("%s",data);
        printf("%s\n",data);
        
        //..4
        str_p[i] = (char *)malloc(sizeof(char) * (strlen(data) + 1));
        if (str_p[i] == NULL) {//ところでメモリが確保できない状況ってどうやってテストすれば良いのだろう
            printf("error : memory could not be allocated\n");
            //異常終了する前に正常に確保できた領域を解放しておく
            for (i--; i >= 0; i--) {
                free(str_p[i]);
            }
            free(str_p);
            exit(EXIT_FAILURE);
        }
        strcpy(str_p[i], data);
    }
    
    
    
    //文字列の画面表示
    printf("\nBefore sorting\n");
    output_strings(str_p,n);
    
    //文字列を長さが短い順番に並べ替え..6
    /*バブルソート図解
     333    最初
     22
     1
     
     22     1巡目結果
     1
     333    <-確定
     
     1      2巡目結果
     22     <-確定
     333    <-確定
     */
    //最右確定を要素数-1巡だけ行う,最後に残ったものが最左確定なためn-1巡で良い
    for (j = 0;j < n - 1; j++) {
        //右端を外してループ継続
        for (i = 0; i < n - 1 - j; i++) {
            if (strlen(str_p[i]) > strlen(str_p[i + 1])) {
                p = str_p[i];
                str_p[i] = str_p[i+1];
                str_p[i+1] = p;
            }
        }
        
    }
    
    
    //並べ変えた文字列の画面表示..7
    printf("\nAfter sorting\n");
    output_strings(str_p,n);
    
    //動的確保した領域の開放
    //(..5)の処理に対応
    for (int i = 0; i < n; i++) {
        free(str_p[i]);
    }
    //(..2)の処理に対応
    free(str_p);
    
    return 0;
}


