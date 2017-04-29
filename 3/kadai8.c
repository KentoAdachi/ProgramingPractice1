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
int main(){
    
    FILE *fp;
    int data[10];
    //import file
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("error : cannot open "filename"\n");
        return 1;
    }
    //read
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d",&data[i]);
    }
    //show
    
    for (int i = 0; i < 10; i++) {
        printf("%d ",data[i]);
    }
    printf("\n");
    
    //sort
    
    for (int j = 0;j < 9; j++) {
        //右端を外してループ継続
        for (int i = 0; i < 9 - j; i++) {
            if (data[i]> data[i + 1]) {
                int tmp;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
        
    }
    //show
    
    for (int i = 0; i < 10; i++) {
        printf("%d ",data[i]);
    }
    printf("\n");

    
    

}
