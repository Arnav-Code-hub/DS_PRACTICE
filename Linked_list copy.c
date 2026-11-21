#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
    };

void print(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        if(temp ->next!=NULL){
            printf("->");
        }
        temp = temp->next;
    }
}

int count(struct node *head){
    struct node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insert(struct node *head,int x){

}

int main(){
    
    struct node *newnode,*head,*temp;
    head = NULL;
    
    int choice=0;
    while (choice!=1){
        newnode = (struct node *)malloc(sizeof(struct node));
        
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;

        if((head)==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("do you want to continue?? 0:yes 1:no  ");
        scanf("%d",&choice);
    }

    print(head);
    return 0;
}