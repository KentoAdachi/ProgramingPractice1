/*
 課題番号 :課題5
 問題番号 :5
 作成年月日 :2017/5/23
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>//malloc

typedef struct SCORE_DATA {
    char name[256];
    int score;
} DATA;

int search_max(struct SCORE_DATA *p, int n) {
    int i = 0;
    int max = 0;
    for (i = 1; i<n; i++) {
        if (p[i].score > p[max].score)max = i;
    }
    return max;
}
int search_min(struct SCORE_DATA *p, int n) {
    
    int i = 0;
    int min = 0;
    for (i = 1; i<n; i++) {
        if (p[i].score < p[min].score)min = i;
    }
    return min;
}

int main(int argc, char const *argv[]) {
    //データ数の入力
    int n;
    printf("input the number of data : ");
    scanf("%d",&n);
    DATA *dp = (DATA *)malloc(sizeof(DATA) * n);
    
    for (int i = 0; i < n; i ++) {
         printf("名前と点数を入力(スペース区切り) : ");
        scanf("%s %d",dp[i].name,&dp[i].score);
    }
   
    
    //最高点の算出
    printf("最大値 : %3d点(%sさん)\n",dp[search_max(dp,n)].score,dp[search_max(dp,n)].name);
    //最低点の算出
    printf("最小値 : %3d点(%sさん)\n",dp[search_min(dp,n)].score,dp[search_min(dp,n)].name);
    return 0;
}
