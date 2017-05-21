#include <stdio.h>
#include <stdlib.h>

#define FILENAME "05data.csv"

struct LIST {
  int score;
  struct LIST *next;
};
typedef struct LIST LIST;


// リストを表示する関数
// ここに追加





int main( void ) {
  int dat;
  LIST *listhead = NULL;  // リストの先頭へのポインタ
  LIST *listtail = NULL;  // リストの末尾へのポインタ
  LIST *p;                // 一時ポインタ
  FILE *fp;               // ファイルポインタ

  // ファイルを開く
  if ( ( fp = fopen( FILENAME, "r" ) ) == NULL ) {
    fprintf( stderr,"ファイルが開けません\n" );
    exit( 1 );
  }

  // 1個目のデータを読み込み、構造体リストに格納する
  fscanf( fp, "%d", &dat );
  p = ( LIST * )malloc( sizeof( LIST ) );
  p->score = dat;
  p->next = NULL;
  listhead = listtail = p;
  

  // 2個目以降のデータを読み込み、構造体リストに格納する
  while( fscanf( fp, "%d",  &dat) != EOF ) {
    // ここに追加


  }

  // リストに格納されたデータを表示する
  show_list( listhead );

  // リストのメモリを開放する
  // ここに追加




  // ファイルを閉じる
  fclose( fp );
  return 0;
}
