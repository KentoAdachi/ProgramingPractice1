/*
 データ構造とアルゴリズム
 課題番号 :課題1-3
 作成年月日 :2017/4/28
 学籍番号 :BP16001
 氏名 :足立 賢人

 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */
#include <stdio.h>
#include <stdlib.h>//malloc
#define FILE_NAME "04data1.csv"
//#define DEBUG//デバッグモード

#ifdef DEBUG
#define DPRINTF printf
#else
#define DPRINTF if(0) printf //絶対に分岐しない
#endif

typedef struct list{
  int score;
  struct list *next;
} List;
/*
例題1-3
04data1.csvからデータを読み込み、構造体リストに保存するプログラムを作成する
リストの先頭をlistheadとして、データを読み込むごとにmallocを使って動的に確保
平均点
最高点
を求める
*/

int main(int argc, char const *argv[]) {
  DPRINTF("DEBUG_MODE\n\n");
  List *listhead = NULL;//先頭アドレス
  List *guide = NULL;
  FILE *fp; //ファイルポインタ

  //fileopen
  printf("Data file : "FILE_NAME"\n\n");
  if ((fp = fopen(FILE_NAME,"r")) == NULL) {
    printf("error 01: cannot read "FILE_NAME"\n");
  }



  //read and store
  int data = 0;
  int datatotal = 0;
  fscanf(fp,"%d",&data);
  DPRINTF("DEBUG : data = %3d\n",data);
  datatotal += data;

  if ((guide = (List *)malloc(sizeof(List))) == NULL) {
    printf("malloc error\n");
  }
  guide->score = data;
  guide->next = NULL;
  listhead = guide;

  List *prev = listhead;
  while (fscanf(fp,"%d",&data) != EOF) {
    DPRINTF("DEBUG : data = %3d\n",data);
    datatotal += data;

    if ((guide = (List *)malloc(sizeof(List))) == NULL) {
      printf("malloc error\n");
    }
    guide->score = data;
    guide->next = NULL;
    prev->next = guide;
    prev = guide;
  }

  //calc
  int total = 0;
  int max = 0;
  guide = listhead;
  int counter = 0;
  int grades[5] ={0};
  while(guide->next != NULL) {
    counter ++;
    DPRINTF("DEBUG : counter = %4d, ",counter);
    total += guide->score;
    if (guide->score > 90) {
      DPRINTF("grade = S ");
      grades[0]++;
    }else if(guide->score > 80){
      DPRINTF("grade = A ");
      grades[1]++;
    }else if(guide->score > 70){
      DPRINTF("grade = B ");
      grades[2]++;
    }else if(guide->score > 60){
      DPRINTF("grade = C ");
      grades[3]++;
    }else {
      DPRINTF("grade = D ");
      grades[4]++;
    }
    DPRINTF("score = %3d ",guide->score);
    DPRINTF("total = %5d ",total);
    if(guide->score > max)max = guide->score;
    DPRINTF("max = %3d \n",max);
    guide = guide->next;
  }
  counter ++;
  DPRINTF("DEBUG : counter = %4d, ",counter);
  DPRINTF("score = %3d ",guide->score);
  DPRINTF("total = %5d ",total);
  DPRINTF("max = %3d \n",max);
  total += guide->score;
  DPRINTF("DEBUG : total = %d\n",total);
  DPRINTF("DEBUG : datatotal = %d\n\n",datatotal);
  printf("average score = %f\n",1.*total/counter );
  printf("    max score = %d\n\n",max );
  char sabcd[5] = "SABCD";
  for (int i = 0; i < 5; i++) {
    printf("      %c grade = %d\n",sabcd[i],grades[i] );
  }
  DPRINTF("単位取得率　= %f\n",1-1.*grades[4]/counter);
  return 0;
}
