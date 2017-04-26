/*
 課題番号 :講義3
 問題番号 :問題4
 作成年月日 :2017/4/26
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char name[10];
    int score;
}BOOK;

int separate(char *sheet,char **np,int *sp){
    /*
     return : error code
     arg1 :char *|sheet
     arg2 :char **|name pointer
     arg3 :int *|score pointer
     */
    
    

    return 0;
}

int main(){
    
    FILE *fp;
    BOOK libraly[10];
    char sheet[100];
    
    if ((fp = fopen("lib.txt", "r")) == NULL) {
        exit(1);
    }
    
    fgets(sheet, 100, fp);
    

}
