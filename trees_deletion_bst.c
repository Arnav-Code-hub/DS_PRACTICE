#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right ;
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

struct node* deletenode(struct node* root,int value){
        struct node* inpre;
        if (root==NULL){
            return NULL;
        }
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }


        if(root->data>value){
            deletenode(root->left,value);
        }
        else if(root->data<value){
            deletenode(root->right,value);
        }
        else{
           inpre=inorderpredecesscor(root);
           root->data=inpre->data;
           root->left=deletenode(root->left,inpre->data);
        }

        return root;

}

int main(){
    struct node* root;
    root=createnode();

    if(isBST(root)){
        struct node* result=search(root,3);
        printf("%d",result->data);
    }
    else
        printf("not a binary search tree");

    return 0;
}