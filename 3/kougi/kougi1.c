/*
 課題番号 :講義3
 問題番号 :問題1
 作成年月日 :2017/4/26
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>

int main(){
    
    int v;
    
    while (1) {
        printf("一桁の整数 : ");
        v = getchar();
        getchar();
        putchar(v);
        putchar('\n');
        if (v == (int)'0') {
            printf("終了する\n");
            break;
        }
    }
    
}
