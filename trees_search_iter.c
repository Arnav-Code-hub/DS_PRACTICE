#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(){
    int data;
    printf("enter data to be entered in the node(-1 for no node):");
    scanf("%d",&data);

    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=data;

    if(data==-1){
        return 0;
    }

    printf("enter data For child node left of node %d",root->data);
    root->left=createnode();
    printf("enter data For child node right of node %d",root->data);
    root->right=createnode();

    return root;
}

struct node* searchiter(struct node* root,int key){
    while (root!=NULL)
    {
        if(root->data==key){
            return root;
        }
        else if(root->data < key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }

    return NULL;
        
}

int isBST(struct node* root){
    static struct node* prev=NULL;
    
    if(root!=NULL){
        if(!isBST(root->left)){
             return 0;
        }

        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct node* root;
    root=createnode();

    if(isBST(root)){
        struct node* result=searchiter(root,3);
        printf("%d",result->data);
    }
    else
        printf("not a binary search tree");

    return 0;
}