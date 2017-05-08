/*
 課題番号 :課題3
 問題番号 :問題11
 作成年月日 :2017/4/26
 学籍番号 :BP16001
 氏名 :足立 賢人

 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <ctype.h>//isdigit()
#define filename "input_0311.txt"

int strreadsum(FILE *fp){
    /*
     ファイルを読み和を計算する関数
     return : int total,整数の合計値
     arg1 : FILE *fp, 読み取り先
     var : int c, ファイルから読み取った文字を一時的に格納
     var : char s[100],ファイルから読み取った文字列を一時的に格納
     output : cが整数か単語か
     */
    char c;
    //..1
    int total = 0;
    //..2 (..6)
    while ((c = fgetc(fp)) != EOF) {
        //..3
        if (c != (int)' ') {
            //..4
            ungetc(c, fp);
            //..5
            if (isdigit(c)) {
                int i;
                fscanf(fp, "%d",&i);
                total += i;
                printf("%d is digit\n",i);
            }else{
                char s[100];
                fscanf(fp, "%s",s);
                printf("%s is word\n",s);
            }
        }
    }
    return total;
}


int main(){
    FILE *fp;

    //ファイルを開く
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("error : cannot open "filename"\n");
        return 1;
    }
    //..7
    printf("total sum = %d\n",strreadsum(fp));


    fclose(fp);
    return 0;
}
