#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(){
    int data;
    printf("enter data to be enetered (-1 for no node):- ");
    scanf("%d",&data);
    
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;

    if(data==-1){
        return 0;
    }

    printf("Enter Left child for node %d:- ",newnode->data);
    newnode->left=createnode();
    printf("Enter right child for node %d:- ",newnode->data);
    newnode->right=createnode();

    return newnode;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


int main(){
    struct node * root;

    root=createnode();

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}