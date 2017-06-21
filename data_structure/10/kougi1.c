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
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAXDAT 100000

// 時刻を計測して double値として返す関数
double gettimeofday_sec() {
    struct timeval tv;
    gettimeofday( &tv, NULL );
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main( int argc, char *argv[] ) {
    int i, dat;
    int n = 0;
    int data[MAXDAT];
    double t1, t2;
    double avg = 0.0;
    FILE *fp;
    
    // 実行時引数にファイル名を指定する(エラー表示)
    if ( argc != 2 ) {
        fprintf( stderr, "Usage: %s data_file\n", argv[0] );
        exit( 1 );
    }
    
    // ファイルを開く
    if (( fp = fopen( argv[1], "r" )) == NULL ) {
        fprintf( stderr, "Cannot open file.\n" );
        exit( 1 );
    }
    
    // 時刻計測(t1)
    t1 = gettimeofday_sec();
    
    while( fscanf( fp, "%d", &dat ) != EOF ) {
        data[n] = dat;
        n++;
        printf("%d\n",n);
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j++) {
                if (data[j] > data[i]) {
                    int tmp = data[j];
                    data[j] = data[i];
                    data[i] = tmp;
                }
            }
        }
        
    }
    
    // 時刻計測(t2)
    t2 = gettimeofday_sec();
    
    for ( i=0; i<n; i++ )
        avg += data[i];
    avg /= n;
    
    fprintf( stdout, "読み込んだデータ数: %d\n", n );
    fprintf( stdout, "データの平均値: %f\n", avg );
    fprintf( stdout, "かかった時間: %.10f\n", t2-t1 );
    
    fclose( fp );
    
    return 0;
}
