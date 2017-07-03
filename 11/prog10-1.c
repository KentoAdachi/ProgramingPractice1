#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} LIST;

// リストの先頭と最後を指すためのポインタ
LIST *listhead = NULL;
LIST *listtail = NULL;

// リストを表示する関数(再帰的関数)
void showlist( LIST *p ) {

  if ( p == NULL )
    fprintf( stdout, "\n" );
  else {
    fprintf( stdout, "-> %d ", p->data );
    showlist( p->next );
  }
  return;
}


int main( int argc, char *argv[] ) {
  int dat;       // 整数を一時的に保存
  int counter;   // データが何個目にあるかを示す変数
  LIST *p;       // リスト型の一時ポインタ
  FILE *fp;      // ファイルポインタ

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

  // データ読み込み&リスト作成
  while( fscanf( fp, "%d", &dat ) != EOF ) {
    p = ( LIST * )malloc( sizeof( LIST ) );
    p->data = dat;
    p->next = NULL;

    if ( listtail == NULL ) {
      listhead = p;
      listtail = p;
    }
    else {
      listtail->next = p;
      listtail = p;
    }
  }

  // リスト表示
  showlist( listhead );

  // 探索
  while ( 1 ) {
    fprintf( stdout, "探索する数値を入力して下さい(-1で終了)→ " );
    fscanf( stdin, "%d", &dat );
  
    if ( dat == -1 ) break;

    p = listhead;
    counter = 0;
    while( p != NULL ) {
      if ( p->data == dat )
	break;
      else
	p = p->next;
      counter++;
    }

    if ( p != NULL )
      fprintf( stdout, "%dは%d個目に登録されています\n", dat, counter );
    else
      fprintf( stdout, "%dは登録されていません\n", dat );
  }
  return 0;
}
