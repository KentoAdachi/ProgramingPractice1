/*
 課題番号 :課題3
 問題番号 :問題11
 作成年月日 :2017/4/26
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <ctype.h>
#define filename "data.txt"

int strread(FILE *fp){
    /*
     read a word from file
     arg1 :FILE *fp, file pointer
     */
    int c;
    int return_value;
    //..2
    while ((c = fgetc(fp)) != EOF) {
        //..3
        if (c == (int)' ') {
            ungetc(c, fp);//..4
            if (isdigit(c)) {
                fscanf(fp, "%d",&c);
                return_value += c;
                printf("%d is digit",c);
            }else{
                char s[100];
                fscanf(fp, "%s",s);
                printf("%s is word",s);
            }
        }
    }
    return return_value;
}




int main(){
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("error : cannot open "filename"\n");
        return 1;
    }

    printf("%d",strread(fp));
    
    return 0;
}
