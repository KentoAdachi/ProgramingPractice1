/*
 課題番号 :課題5
 問題番号 :9
 作成年月日 :2017/5/23
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#include <stdlib.h>//malloc

typedef struct SCORE_DATA_LIST {
    char name[256];
    int score;
    struct SCORE_DATA_LIST *next;
} LIST;

LIST *search_max(struct SCORE_DATA_LIST *head) {
    LIST *q = head;
    int max = head->score;
    for (LIST *p = head; p != NULL; p = p->next) {
        if (max < p->score) {
            q = p;
            max = p->score;
        }
    }
    return q;
}

LIST *search_min(struct SCORE_DATA_LIST *head) {
    LIST *q = head;
    int min = head->score;
    for (LIST *p = head; p != NULL; p = p->next) {
        if (min > p->score) {
            q = p;
            min = p->score;
        }
    }
    return q;
}


int main(int argc, char const *argv[]) {
    LIST *head;
    
    char flag = 'n';
    for (LIST *p = head; flag == 'n';) {
        p = (LIST *)malloc(sizeof(LIST));
        //名前とスコアの入力
        printf("名前とスコアを入力 : ");
        scanf("%s %d",p->name,&p->score);
        p->next = head;
        head = p;
        //終了しますか
        printf("do you want to quit?(y/n)\n");
        scanf(" %c",&flag);
    }
    
//    for (LIST *p = head; p != NULL; p = p->next) {
//        printf("score %d\n",p->score);
//    }
    printf("最高点 : %d点(%sさん)\n",search_max(head)->score,search_max(head)->name);
    printf("最低点 : %d点(%sさん)\n",search_min(head)->score,search_min(head)->name);
    
    
    return 0;
}
