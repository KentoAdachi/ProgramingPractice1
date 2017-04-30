/*
 課題番号 :課題3
 問題番号 :問題8
 作成年月日 :2017/4/28
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */

#include <stdio.h>
#define filename "output_0307.txt"
#define bool int
void show(int data[10],bool onlyData){
    /*
     各種計算結果の出力をする
     return : なし
     arg1 : int data[10], 読み込んだデータ
     arg2 : bool onlyData, データの表示のみを行う
     var : float total, データの合計値.平均値の算出に用いる
     output : data(,平均値,最大値,最小値 |onlydata == 0)
     */
    
    float total = 0;
    
    //data
    for (int i = 0; i < 10; i++) {
        printf("%d ",data[i]);
        total += data[i];
    }
    printf("\n");
    
    if (onlyData == 0) {
        //ave
        printf("平均値 = %f\n",total/10);
        
        //max 実行前にソートする必要がある
        printf("最大値 = %d\n",data[9]);
        
        //min
        printf("最小値 = %d\n",data[0]);
    }
}

int main(){
    
    FILE *fp;
    int data[10];
    
    //ファイルを開く
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("error : cannot open "filename"\n");
        return 1;
    }
    
    //データを入力
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d",&data[i]);
    }
    
    //出力1
    printf("読み込んだデータ: ");
    show(data,1);
    
    //バブルソート -前回のソースとほぼ同一-
    for (int j = 0;j < 9; j++) {
        for (int i = 0; i < 9 - j; i++) {
            if (data[i]> data[i + 1]) {
                int tmp;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
    
    //出力2
    printf("小さい順に並び替え: ");
    show(data,0);
    
    fclose(fp);
    return 0;
}
