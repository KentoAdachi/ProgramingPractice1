/*
 課題番号 :課題4
 問題番号 :問題7
 作成年月日 :2017/5/14
 学籍番号 :BP16001
 氏名 :足立 賢人
 
 動作環境 :xcode8.1(MacOS Sierra 10.12.4)
 */
#include <stdio.h>
#include <stdlib.h>//malloc

#define FILE_NAME "input_0407.txt"
//#define DEBUG_MODE//デバッグモード
#define PLOT_MODE//プロットモード,"gnuplot"が使えない環境だったらこの行をアウトしてください

#ifdef DEBUG_MODE
#define DPRINTF printf
#else
#define DPRINTF if(0) printf
#endif

#ifdef PLOT_MODE
#define PLOT_FLAG 1
#define FPLOTF fprintf
#else
#define PLOT_FLAG 0
#define FPLOTF if(0) fprintf
#endif

typedef struct point_list{
    double x,y;
    struct point_list *next;
} List;

struct vector2{
    double x,y;
};

int main() {
    DPRINTF("DEBUG MODE\n\n");
    if(PLOT_FLAG)printf("PLOT MODE\n\n");
    
    List *listhead = NULL;//..(1)
    List *p = NULL;
    FILE *fp,*gp;
    struct vector2 data;
    
    printf("data : "FILE_NAME"\n");
    //fileopen
    if ((fp = (fopen(FILE_NAME, "r"))) == NULL) {
        printf("cannot open "FILE_NAME"\n");
        exit(EOF);
    }
    
    while(fscanf(fp, "%lf,%lf",&data.x,&data.y) != EOF){//..(2)
        DPRINTF("data = (%f,%f)\n",data.x,data.y);
        p = (List *)malloc(sizeof(List));//..(3)
        p->x = data.x;
        p->y = data.y;
        p->next = listhead;//..(4)
        listhead = p;
    }
    
    //plot
    
    if(PLOT_FLAG) gp = popen("gnuplot -persist","w");
    FPLOTF(gp, "set xrange [-8.0:8.0]\n");
    FPLOTF(gp, "set yrange [-8.0:8.0]\n");
    FPLOTF(gp, "plot '-' with lines linetype 1 title \""FILE_NAME"\"\n");//アンダースコアが下付き文字になっちゃうけど解決策わからないから放置
    
    List *temp;
    while (p != NULL) {

        FPLOTF(gp,"%f\t%f\n",p->x,p->y);
        
        printf("p = (%f,%f)\n",p->x,p->y);
        temp = p->next;//先に解放してしまうと次への参照が取れなくなる
        free(p);
        p = temp;
    }
    
    return 0;
}


