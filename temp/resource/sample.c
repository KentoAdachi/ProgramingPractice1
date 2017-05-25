#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define  N_ALPH 26

int main(int argc,char *argv[])
{
  FILE   *fin;
  int    ic, i_alph;
  char   alph;
  int    count_alph[N_ALPH], num_alph, num_alph_tot;
  double prob_alph[N_ALPH], prob_alph_tot;
  double entropy_alph;
  double scale;

  /* initialization */
  scale = 1./log10(2.);
  for(i_alph=0;i_alph<N_ALPH;i_alph++) count_alph[i_alph]=0;

  if((fin = fopen(argv[1], "rb")) == NULL ) {
    fprintf(stderr,"# fopen error! %s\n",argv[1]);
    exit(1);
  }

  num_alph =0;
  while ((ic=fgetc(fin)) != EOF) {
    if (isalpha(ic)) { 
       alph = tolower(ic);
       num_alph++;
       count_alph[(int)(alph - 'a')]++;
    }
  }

  fclose(fin);

  num_alph_tot = 0;
  for(i_alph=0;i_alph<N_ALPH;i_alph++) {
     num_alph_tot +=count_alph[i_alph];
  }

  printf("num_alph=%14d,num_alph_tot=%14d \n",num_alph,num_alph_tot);

  prob_alph_tot = 0.;
  for(i_alph=0;i_alph<N_ALPH;i_alph++) {
    if (count_alph[i_alph] > 0) {
      prob_alph[i_alph] = (double)count_alph[i_alph] / (double)num_alph_tot;
    }
    else {
      prob_alph[i_alph] = 0.;
      printf("#CAUTION! count_alph[i_alph]=%d(=0)\n", count_alph[i_alph]);
    }

    printf("%2c: %10d, %10.7f\n",
            i_alph+'a',count_alph[i_alph],prob_alph[i_alph]);

    prob_alph_tot += prob_alph[i_alph];
  }

  printf("num_alph_tot=%10d,prob_alph_tot=%10.7f\n",
         num_alph_tot,prob_alph_tot);
}









