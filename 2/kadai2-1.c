/*
 課題番号 :課題2
 問題番号 :問題1
 作成年月日 :2017/4/19
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRING 20  //文字列の最大個数
#define MAX_LEN 100   //文字配列のサイズ（入力文字列の最大長さ＋１）
//int MAX_LEN = 100
//文字列の画面出力用関数（逆順）
void output_strings_reverse(char **array_p, int m)
{
    
    printf("%d\n",m);
    
    //デクリメントで表示の順番を逆に
    for (int i = m-1; i > -1; i--) {
        printf("%s\n", array_p[i]);
    }
    
    
}


int main( void )
{
    int i;
    int n;  //文字列の個数
    char data[MAX_LEN]={};  //入力用文字列
    char *str_p[NUM_STRING];  //文字列へのポインタを格納するポインタ配列
    
    //i〜iiiの処理
    
    //..3
    for (i = 0; i < NUM_STRING; i++) {
        
        //..1 格納
        printf("Input strings : ");
        scanf("%s",data);
        printf("%s\n",data);
        
        // 入力終了は確保の前が望ましいのでこの位置
        int flag = strcmp(data, "end");
        if (flag == 0) {
            break;
        }
        
        //..2 メモリの確保とコピー
        str_p[i] = (char *)malloc(sizeof(char) * (strlen(data) + 1));
        
        if (str_p[i] == NULL) {
            printf("error : memory could not be allocated\n");
            break;
        }
        
        strcpy(str_p[i], data);
        
        
    }
    
    n = i;
    
    
    //文字列の画面出力
    output_strings_reverse(str_p,n);
    
    //動的確保した領域の開放
    for (int i = 0; i < n; i++) {
        free(str_p[i]);
    }
    
    
    
    return 0;
}
