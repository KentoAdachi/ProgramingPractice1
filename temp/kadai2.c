#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define  N_ALPH 26
#define FILE_NAME "alice29.txt"
//２次の情報源は2回whileを通す,EOFに気をつける,


double entropy2(double p[N_ALPH][N_ALPH],int count){
  double entropy = 0;

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      if (p[i][j] > 0) {
        entropy += -p[i][j] * log10(p[i][j])/log10(2.);
      }
    }
  }

  return entropy;
}

int main(int argc,char *argv[])
{
  /*宣言領域*/
  /*
  fp :filepointer
  ic : i or c つまり振り分ける前の1文字
  aplh : 振り分けた後の1文字 counterの値を増加させるのに使う
  count_alph[] : カウンター,文字ごとの出現数をカウントする
  num_alph : 読んだ文字の総数
  num_alph_total : 読んだ文字の総数,count_alphの総和から算出したもの
  probability_alph[] : アルファベットごとの生起確率
  probability_alph_total : 上の総和, == 1になる

  */
  FILE   *fp;
  int    ic, i;
  char   alph,alph2;
  int    num_alph, num_alph_total;
  int    count_alph2[N_ALPH][N_ALPH];
  double probability_alph_total;
  double probability_alph2[N_ALPH][N_ALPH];

  /*初期化領域*/
  for (int i = 0; i < N_ALPH; i++) {
    for (int j = 0; j < N_ALPH; j++) {
      count_alph2[i][j] = 0;
    }
  }

  //ファイルを開く
  if((fp = fopen(FILE_NAME, "rb")) == NULL ) {
    fprintf(stderr,"# fopen error!"FILE_NAME"\n");
    exit(1);
  }



  //読み取り領域

  num_alph =0;
  while ((ic=fgetc(fp)) != EOF) {
    if (isalpha(ic)) {
      alph = tolower(ic);
      num_alph++;
      while ((ic=fgetc(fp)) != EOF) {
        if (isalpha(ic)) {
          alph2 = tolower(ic);
          count_alph2[(int)(alph - 'a')][(int)(alph2 - 'a')]++;
          break;
        }
      }
    }
  }


  fclose(fp);

  //計算領域
  //plot
  FILE *gp;
  gp = popen("gnuplot -persist","w");
  fprintf(gp, "plot '-' with boxes title \"probability2[i][j]|([a][a]=0,[a][b]=1,[a][c]=2...)\"\n");

  //総文字数の計算
  num_alph_total = 0;
  for(int i=0;i<N_ALPH;i++) {
    for(int j = 0;j < N_ALPH;j++){
      num_alph_total +=count_alph2[i][j];
    }
  }


  printf("num_alph=%14d,num_alph_total=%14d \n",num_alph,num_alph_total);

  probability_alph_total = 0.;
  int index[2];
  int max = 0;
  for(i=0;i < N_ALPH;i++) {
    for(int j = 0;j < N_ALPH;j++){
      if (count_alph2[i][j] > 0) {
        probability_alph2[i][j] = (double)count_alph2[i][j] / (double)num_alph_total;
      }
      else {
        probability_alph2[i][j] = 0.;
        //printf("#CAUTION! count_alph2[%d][%d]=%d(=0)\n",i,j,count_alph2[i][j]);
      }

      //printf("%2c%2c: %10d, %10.7f\n",i+'a',j+'a',count_alph2[i][j],probability_alph2[i][j]);
      fprintf(gp,"%d\t%f\n",i*26 + j,probability_alph2[i][j]);//plot,26進法->10進法に直して表示
      probability_alph_total += probability_alph2[i][j];

      if (count_alph2[i][j] > max) {
        max = count_alph2[i][j];
        index[0] = i;
        index[1] = j;
      }
    }
  }
  printf("probability_alph_total=%10.7f\n",probability_alph_total);


  printf("H(S^2) entropy = %f\n",entropy2(probability_alph2,N_ALPH));
  printf("Half   entropy = %f\n",entropy2(probability_alph2,N_ALPH)/2 );

  double probability_homo[N_ALPH];
  for (int i = 0; i < N_ALPH; i++) {
    probability_homo[i] = 1./N_ALPH;
  }
  //printf("homo entropy = %f\n",entropy(probability_homo,N_ALPH));

  printf("max prob :%2c%c = %f\n",index[0] + 'a',index[1] + 'a',probability_alph2[index[0]][index[1]]);

  fprintf(gp,"e\n");//plot
  pclose(gp);//plot

}
