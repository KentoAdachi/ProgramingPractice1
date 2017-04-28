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

//ファイルを読み和を計算する関数
int strreadsum(FILE *fp){
    /*
     return : int total : total sum
     arg1 : FILE *fp :file pointer
     */
    int c;
    //..1
    int total = 0;
    //..2
    while ((c = fgetc(fp)) != EOF) {
        //..3
        if (c != (int)' ') {
            //..4
            ungetc(c, fp);
            //..5
            if (isdigit(c)) {
                fscanf(fp, "%d",&c);
                total += c;
                printf("%d is digit\n",c);
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
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("error : cannot open "filename"\n");
        return 1;
    }
    //..7
    printf("total sum = %d\n",strreadsum(fp));
    
    
    return 0;
}
