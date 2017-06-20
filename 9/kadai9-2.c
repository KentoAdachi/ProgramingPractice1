/*
 講義名 : プログラミング演習1
 課題番号 : 講義9
 問題番号 : 問題2
 作成年月日 : 2017/6/19
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : 再帰的ユークリッド互除法
 */
#include <stdio.h>


int GCD(int p, int q){
    
    if (p % q == 0) {
        return  q;
    }else{
        return GCD(p, p%q);
    }
    
}

int main(){
    int p = 0,q = 0;
    
    printf("二つの自然数を入力 --> ");
    
    // 大小関係を確定
    scanf("%d %d",&p,&q);
    if (p < q) {
        int tmp = 0;
        tmp = p;
        p = q;
        q = tmp;
    }
    
    //呼び出し
    printf("GCD = %d\n",GCD(p, q));
    
    return 0;
}
