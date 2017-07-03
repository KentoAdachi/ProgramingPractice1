#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 100

// 配列を表示する関数
void showarray( int *data, int n ) {
  int i;

  for ( i=0; i<n; i++ )
    fprintf( stdout, "%d ", data[i] );

  fprintf( stdout, "\n" );
  return;
}


int main( int argc, char *argv[] ) {
  int i;             // ループ用
  int p;             // 挿入場所を探す変数
  int n = 0;         // データ数を保存する変数
  int data[MAXDATA]; // データを格納する配列
  int dat;           // 整数を一時的に保存
  FILE *fp;          // ファイルポインタ

  
  // プログラム利用方法表示
  if ( argc != 2 ) {
    fprintf( stderr, "Usage: %s filename\n", argv[0] );
    exit( 1 );
  }

  // ファイルオープン
  if (( fp = fopen( argv[1], "r" ) ) == NULL ) {
    fprintf( stderr, "File open error %s\n", argv[1] );
    exit( 1 );
  }

  // データ読み込み&整列してデータを格納
  while( fscanf( fp, "%d", &dat ) != EOF ) {

    // 格納場所を探す
    for ( p=0; p<n; p++ )
      if ( data[p] > dat ) break;

    // 場所p以降のデータを一つずつ後ろへずらす
    for ( i=n-1; i>=p; i-- )
      data[i+1] = data[i];

    // 場所iにデータを格納する
    data[p] = dat;
    n++;

  }

  // 配列の内容を表示
  showarray( data, n );


  return 0;
}
