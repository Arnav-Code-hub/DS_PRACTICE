#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->data);
    }
}

struct node * createnode(){
    int data;
    printf("enter data to be entered(-1 for no node):");
    scanf("%d",&data);

    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;

    if(data==-1){
        return 0;
    }
    
    printf("Enter left child for node %d",newnode->data);
    newnode->left=createnode();
    printf("Enter left child for node %d",newnode->data);
    newnode->right=createnode();

    return newnode;

}

int isBST(struct node * root){
    static struct node * prev=NULL;    
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}