/*
 課題番号 :講義3
 問題番号 :問題2
 作成年月日 :2017/4/26
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE *fp;
    char word[128];
    
    if ((fp = fopen("data.txt", "r")) == NULL) {
        exit(1);
    }
    
    while (1) {
        
        printf("英単語を入力 : ");
        //scanf("%s",word);
        fgets(word,10,fp);
        word[strlen(word)-1] = '\0';
        
        
        if (strcmp(word,"quit") == 0) {
            puts("終了する");
            break;
        }
        //printf("%s",word);
        puts(word);
    }
}
