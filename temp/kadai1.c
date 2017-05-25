#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define  N_ALPH 26
#define FILE_NAME "alice29.txt"

double entropy(double p[],int count){
  double entropy = 0;
  for (int i = 0; i < count; i++) {
    entropy += -p[i] * log10(p[i])/log10(2.);
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
  probability_alph_total : 上の総和,理論上は == 1になる


  */
  FILE   *fp;
  int    ic, i;
  char   alph;
  int    count_alph[N_ALPH], num_alph, num_alph_total;
  double probability_alph[N_ALPH], probability_alph_total;


  /*初期化領域*/

  for(i=0;i<N_ALPH;i++) count_alph[i]=0;

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
      count_alph[(int)(alph - 'a')]++;
    }
  }

  fclose(fp);

  //計算領域

  //plot
  FILE *gp;
  gp = popen("gnuplot -persist","w");
  fprintf(gp, "plot '-' with boxes title \"probability[i] | i = (0=a,1=b,2=c...)\"\n");

  //総文字数の計算
  num_alph_total = 0;
  for(i=0;i<N_ALPH;i++) {
    num_alph_total +=count_alph[i];
  }

  printf("num_alph=%14d,num_alph_total=%14d \n",num_alph,num_alph_total);
  printf("\n       count alph,  probability_alph\n");
  probability_alph_total = 0.;
  for(i=0;i < N_ALPH;i++) {
    if (count_alph[i] > 0) {
      probability_alph[i] = (double)count_alph[i] / (double)num_alph_total;
    }
    else {
      probability_alph[i] = 0.;
      printf("#CAUTION! count_alph[i]=%d(=0)\n", count_alph[i]);
    }

    printf("%2d %2c: %10d, %10.7f\n",i,i+'a',count_alph[i],probability_alph[i]);

    fprintf(gp,"%d\t%f\n",i,probability_alph[i]);//plot
    probability_alph_total += probability_alph[i];


  }
  printf("\nnum_alph_total=%10d,probability_alph_total=%10.7f\n",num_alph_total,probability_alph_total);


  printf("H(S) entropy = %f\n",entropy(probability_alph,N_ALPH));

  double probability_homo[N_ALPH];
  for (int i = 0; i < N_ALPH; i++) {
    probability_homo[i] = 1./N_ALPH;
  }
  printf("homo entropy = %f\n",entropy(probability_homo,N_ALPH));
  fprintf(gp,"e\n");//plot
  pclose(gp);//plot
}
