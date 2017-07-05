/*
 講義名 : データ構造とアルゴリズム1
 課題番号 : 講義12
 問題番号 : 問題1
 作成年月日 : 2017/7/4
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : バイナリツリーへの挿入
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
} NODE;

NODE *root;


//prototype
void insert(NODE **p,int dat);




void insert(NODE **p,int dat){
    if (*p == NULL) {
        *p = (NODE *)malloc(sizeof(NODE));
        (*p)->left = NULL;
        (*p)->right = NULL;
        (*p)->data = dat;
    }else{
        if ((*p)->data > dat) {
            insert(&(*p)->left, dat);
        }else{
            insert(&(*p)->right, dat);
        }
    
    }

}


//node != NULLを前提条件にして3行でもいい気はする
void showTreeByPreoder(NODE *node){
    if (node != NULL){
        printf("%d ",node->data);
        if (node->left != NULL) showTreeByPreoder(node->left);
        if (node->right != NULL) showTreeByPreoder(node->right);
    }
}

void showTreeByInorder(NODE *node){
    if (node != NULL){
        if (node->left != NULL) showTreeByInorder(node->left);
        printf("%d ",node->data);
        if (node->right != NULL) showTreeByInorder(node->right);
    }
}

void showTreeByPostorder(NODE *node){
    if (node != NULL){
        if (node->left != NULL) showTreeByPostorder(node->left);
        if (node->right != NULL) showTreeByPostorder(node->right);
        printf("%d ",node->data);
    }
}




int main(){
    
    while (1) {
        printf("inset data (-1 to quit): ");
        int dat;
        scanf("%d",&dat);
        if (dat == -1)break;
        insert(&root, dat);
        printf("Preoder  : ");
        showTreeByPreoder(root);
        printf("\n");
        printf("Inoder   : ");
        showTreeByInorder(root);
        printf("\n");
        printf("Postoder : ");
        showTreeByPostorder(root);
        printf("\n\n");
    }

}
