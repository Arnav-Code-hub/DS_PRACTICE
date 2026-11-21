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

struct node * deletefirstnode(struct node* head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node * deleteindexnode(struct node *head,int index){
    struct node * p=head;
    struct node * q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;
}

struct node * deletelastnode(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
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

    head=deletefirstnode(head);
    print(head);

    head=deleteindexnode(head,3);
    print(head);
    return 0;
}