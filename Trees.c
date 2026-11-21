#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * createnode(int value){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int main(){
    /*
    struct node * p=(struct node *)malloc(sizeof(struct node));
    printf("enter root node data :- ");
    scanf("%d",p->data);
    p->left=NULL;
    p->right=NULL;

    struct node * p1=(struct node *)malloc(sizeof(struct node));
    printf("enter root node data :- ");
    scanf("%d",p1->data);
    p1->left=NULL;
    p1->right=NULL;

    struct node * p2=(struct node *)malloc(sizeof(struct node));
    printf("enter root node data :- ");
    scanf("%d",p2->data);
    p2->left=NULL;
    p2->right=NULL;
    */

    struct node * p=createnode(2);
    struct node * p1=createnode(1);
    struct node * p2=createnode(4); 
    
    p->left=p1;
    p->right=p2;

    
    return 0;
}