/*
 課題番号 : 講義7
 問題番号 : 問題2
 作成年月日 : 2017/6/6
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : リングバッファを用いたキューの作成
 */

#include <stdio.h>
#include <string.h>
double ring_buff[10] = {0};
int head = 0;
int tail = 0;
int siz = 0;


void enq();
void deq();
void show();

//追加
void enq(){
    if (siz < 10) {
        printf("追加するデータを入力 : ");
        double data;
        scanf("%lf",&data);
        ring_buff[tail] = data;
        tail = (tail+1)%10;
        siz ++;
        
        show();
    }else{
        printf("キューが全て埋まっています\nデータを削除してください\n");
    }
}

//削除
void deq(){
    if (siz > 0) {
        printf("%f\n",ring_buff[head]);
        head = (head + 1)%10;
        siz --;
        
        show();
    }
}

//表示
void show(){
    for (int i = head; i%10 != tail; i++) {
        printf(" -> %f",ring_buff[i%10]);
    }
    printf("\n");
}


int main(){
    //init
    
    while (1) {
        
        char s[128];
        printf("操作を選択(enq/deq/end) : ");
        scanf("%s",s);
        
        if (strcmp(s, "enq") == 0) {
            //call function
            enq();
        }
        if (strcmp(s, "deq") == 0) {
            //call function
            deq();
        }
        if (strcmp(s, "end") == 0) {
            //call function
            printf("終了します\n");
            break;
        }
    }
}
