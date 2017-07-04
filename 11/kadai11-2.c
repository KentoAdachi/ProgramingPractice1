/*
 講義名 : プログラミング演習1
 課題番号 : 講義11
 問題番号 : 問題2
 作成年月日 : 2017/7/4
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : 二分探索
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "dic-u.txt"

typedef struct page{
    char eng[64];
    char jap[64];
    
}DIC_CELL;


char *search(DIC_CELL * book,int lower,int upper,char * key){
    
    if (lower > upper) {
        return NULL;
    }else{
        int middle = (lower + upper)/2;
        if (strcmp(book[middle].eng, key) > 0) {
            return search(book, lower, middle-1, key);
        }else if(strcmp(book[middle].eng, key) < 0){
            return search(book, middle + 1, upper, key);
        }else {
            return book[middle].jap;
        }
    }
}




int main(){
    
    
    FILE *fp=fopen(FILENAME, "r");
    DIC_CELL book[50];
    
    
    //read
    int i = 0;
    for (i = 0;fscanf(fp, "%s %s",book[i].eng,book[i].jap) != EOF;i ++);
    
    while (1) {

        
        //input
        printf("英単語を入力してください : ");
        char key[64];
        scanf("%s",key);
        
        
        //search
        char *tmp;
        if ( (tmp = search(book, 0, i, key)) == NULL) {
            printf("%sは登録されていません\n",key);
        }else{
            printf("%sの意味 : %s\n",key,tmp);
        }
        
        
        char yn[64];
        printf("続けますか?(yes/no)\n");
        scanf("%s",yn);
        if (strcmp(yn, "no") == 0)break;
    
    }
    
    printf("プログラムを終了します\n");
    fclose(fp);
}
