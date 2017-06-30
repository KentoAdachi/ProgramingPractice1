/*
 講義名 : プログラミング演習1
 課題番号 : 講義10
 問題番号 : 問題2
 作成年月日 : 2017/6/19
 学籍番号 : BP16001
 氏名 : 足立賢人
 動作環境 : Xcode8.2.1 - MacOS Sierra
 
 
 課題概要 : 算術式
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//node
typedef struct node{
    char oper[10];
    struct node *left;
    struct node *right;
} Node;

struct node *root;

//prototype
void malloc_s(Node ** dp);
struct node *mkNode(char data[10]);
struct node *bin_tree();


//malloc with error printing
//from kadai9
void malloc_s(Node ** dp){
    if ((*dp = (Node *)malloc(sizeof(Node))) == NULL ) {
        printf("error : memory not allocated\n");
        exit(-1);
    }
}

//construct node with value
//from kadai9
Node *mkNode(char data[10]){
    Node *node;
    malloc_s(&node);
    
    strcpy(node->oper,data);
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

Node *bin_tree(){
    char c;
    Node *p = NULL;
    char str[128];
    
    
    while((c = getchar()) != EOF){
//        printf("getchar : %c\n",c);
        if (c != ' ') {
            //2
            ungetc(c,stdin);
            scanf("%s",str);
//            printf("getstring : %s\n",str);
            
            //3,4
            malloc_s(&p);
            strcpy(p->oper, str);
            
            
            
            //5
            if (isdigit(c)) {
                p->left = NULL;
                p->right = NULL;
                
//                printf("oper c!=0: %s\n",p->oper);
                return p;
            }
            
            //6
            else {
                p->left = bin_tree();
                p->right = bin_tree();
//                printf("oper C==0: %s\n",p->oper);
                return p;
                
            }
            
            
        }
    }
    
    
    return NULL;
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
    
    root = bin_tree();
    
    
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























