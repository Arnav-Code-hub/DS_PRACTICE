#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node * left;
    struct node * right;
    int hieght ;
};

int gethieght(struct node * n){
    if(n==NULL){
        return 0;
    }
    return n->hieght;
}

 int getbalacncefactor(struct node * n){
    if(n==NULL){
        return 0;
    }
    return (gethieght(n->left)-gethieght(n->right));
 }

 struct node * createnode(int key){
    struct node * node=(struct node *)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->hieght=1;
    return node;
 }

 struct node * LR(struct node * y){
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->hieght= max(gethieght(y->right),gethieght(y->left))+1;
    x->hieght= max(gethieght(x->right),gethieght(x->left))+1;

    return x;

 }

  struct node * RR(struct node * x){
    struct node* y=x->right;
    struct node* T2=y->left;

    y->left=x;
    x->right=T2;

    y->hieght= max(gethieght(y->right),gethieght(y->left))+1;
    x->hieght= max(gethieght(x->right),gethieght(x->left))+1;

    return y ;
 }

 void insert(struct node * root,int key){
    struct node * prev=NULL;
    prev=root;
    while(root!=NULL){
        if(root->key==key){
            return;
        }
        else if(root->key>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->key=key;
    newnode->left=NULL;
    newnode->right=NULL;

    if(prev->key>key){
        prev->left=newnode;
    }
    else{
        prev->right=newnode;
    }
 }