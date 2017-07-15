/*
 講義名 : プログラミング演習I
 課題番号 : 講義13
 問題番号 : 問題1
 作成年月日 : 2017/7/12
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : ハッシュ法を用いた探索
 */


#include <stdio.h>
#include <string.h>
#define FILENAME "phone.txt"
#define DATA_SIZ 70

typedef struct data {
    char name[64];
    int number;
    
} Data;



//prototype
int hash(char * str);
void insert(int i,char *name,Data *dp,int number);
Data *search(char *name, Data*dp);

int main(){
    
    /*open file*/
    FILE *fp = fopen(FILENAME, "r");
    
    /*read file*/
    Data book[DATA_SIZ] = {0,0};
    char name[128];
    int number;
    for (int i = 0; fscanf(fp, "%s %d",name,&number) != EOF; i++) {
        //        printf("%2d , %15s , %5d\n",i,name,number);
        //        printf("hash = %d\n",hash(name));
        
        int j = hash(name);
//        printf("%d\n",hash(name));
        insert(j, name, book, number);
        
    }
    
    /*print*/
    
    for (int i= 0; i < DATA_SIZ; i ++) {
        printf("%3d %20s %5d \n",i,book[i].name,book[i].number);
    }
    
    
    /*search*/
    Data * p;
    while (1) {
        
        
        printf("名前または!を入力してください : ");
        scanf("%s",name);
        if (strcmp(name, "!") == 0) {
            break;
        }
        
        if ((p = search(name,book)) != NULL) {
            printf("内線番号 : %d\n",p->number);
        }else{
            printf("%sはハッシュ表に登録されていません\n",name);
        }
        
    }
    
}

//線形走査
Data *search(char *name, Data*dp){
    static int i = 0;
    
    if (strcmp(dp[i].name, name) == 0) {
        int j = i;
        i = 0;
        
        return &dp[j];
    }else{
        if (i == DATA_SIZ) {
            i = 0;
            return NULL;
        }
        i++;
        return search(name,dp);
    }
    
    return NULL;
}

//再帰関数によって線形走査法を実現
void insert(int i,char *name,Data *dp,int number){
    if (dp[i].name[0] == '\0') {
        strcpy(dp[i].name, name);
        dp[i].number = number;
//        printf("%dに%sを格納しました\n",i,name);
    }else{
//        printf("%dに%sを格納できませんでした\n",i,name);
        insert(i+1, name, dp, number);
    }
}



//ハッシュ関数
int hash(char * str){
    int ret = 0;
    for (int i = 0;str[i] != '\0'; i++) {
        ret += (unsigned int)str[i];
    }
    
    return ret % DATA_SIZ;
}







