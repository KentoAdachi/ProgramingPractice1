/*
 課題番号 :課題1
 問題番号 :問題6
 作成年月日 :2017/4/12
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4) 
 */

#include <stdio.h>
#include <stdlib.h>

void input_data(char name[5][64]);
int find_data(char name[5][64], char key[64]);

int main(){
    
    char name[5][64], key[64];
    
    input_data(name);
    
    while (1) {
        int fout = find_data(name, key);
        int flag = 0;
        switch (fout) {
            case -2:
                printf("quit\n");
                flag =1;
                break;
            case -1:
                printf("%s is not found\n", key);
                break;
            default:
                printf("%s is in name[%d]\n",key,fout);
                break;
        }
        
        if (flag == 1) {
            break;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("name[%d] = %s\n",i,name[i]);
    }
    
}

void input_data(char name[5][64]){
    for (int i = 0; i < 5; i++) {
        printf("input name[%d] : ",i);
        scanf("%s",name[i]);
    }
    
}

int find_data(char name[5][64], char key[64]){
    int isCorrect = -1;
    char sQuit[5] = "quit";
    
    printf("input key : ");
    scanf("%s",key);
    if (strcmp(sQuit, key) == 0) {
        //quit
        isCorrect = -2;
    }else{
        for (int i = 0; i < 5; i++) {
            if (strcmp(name[i], key) == 0) {
                isCorrect = i;
            }
        }
    }
    
    return isCorrect;
}
