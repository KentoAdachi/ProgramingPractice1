/*
 講義名 : プログラミング演習1
 課題番号 : 講義9
 問題番号 : 問題3
 作成年月日 : 2017/6/14
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra


 課題概要 : 木構造のプログラムによる表現
 */

/*更新履歴
 6/14 : 作成

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char oper[10];
    struct node *left;
    struct node *right;
} Node;

//prototype
void malloc_s(Node ** dp);
Node *mkNode(char data[10]);

//malloc with error
void malloc_s(Node ** dp){
    if ((*dp = (Node *)malloc(sizeof(Node))) == NULL ) {
        printf("error : memory not allocated\n");
        exit(-1);
    }
}

//construct node with value
Node *mkNode(char data[10]){
    Node *node;
    malloc_s(&node);

    strcpy(node->oper,data);
    node->left = NULL;
    node->right = NULL;

    return node;
}

//node != NULLを前提条件にして3行でもいい気はする
void showTreeByPreoder(Node *node){
    if (node != NULL){
        printf("%s ",node->oper);
        if (node->left != NULL) showTreeByPreoder(node->left);
        if (node->right != NULL) showTreeByPreoder(node->right);
    }
}

void showTreeByInorder(Node *node){
    if (node != NULL){
        if (node->left != NULL) showTreeByInorder(node->left);
        printf("%s ",node->oper);
        if (node->right != NULL) showTreeByInorder(node->right);
    }
}

void showTreeByPostorder(Node *node){
    if (node != NULL){
        if (node->left != NULL) showTreeByPostorder(node->left);
        if (node->right != NULL) showTreeByPostorder(node->right);
        printf("%s ",node->oper);
    }
}

int main(){

    //make tree
    Node *root;
    root = mkNode("*");
    root->left = mkNode("+");
    root->left->left = mkNode("a");
    root->left->right = mkNode("b");
    root->right = mkNode("-");
    root->right->left = mkNode("c");
    root->right->right = mkNode("/");
    root->right->right->left = mkNode("d");
    root->right->right->right = mkNode("e");

    printf("prefix notation ===> ");
    showTreeByPreoder(root);
    printf("\n");
    printf("infix notation ====> ");
    showTreeByInorder(root);
    printf("\n");
    printf("postfix notation ==> ");
    showTreeByPostorder(root);
    printf("\n");
    printf("***** END OF TRAVERSAL *****\n");
}
