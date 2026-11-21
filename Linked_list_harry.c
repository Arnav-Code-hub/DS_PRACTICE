#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linkedlisttraversal(struct node *ptr){
    while(ptr!=NULL){
    printf("%d",ptr->data);
    if(ptr->next!=NULL){
        printf(" -> ");
    }
    ptr=ptr->next;
 }
 printf("\n");
}

struct node* insertatfirst(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;   
}

struct node * insertatindex(struct node* head,int data,int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p= head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;

    return head;
}

struct node * insertatend(struct node* head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    while(p!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;

    return head;
}


int main(){
    struct node *newnode,*head,*temp,*second,*third;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    linkedlisttraversal(head);

    head=insertatfirst(head, 77);
    linkedlisttraversal(head);


    printf("enter index where you want to insert your node");
    int index;
    scanf("%d",&index);
    head=insertatindex(head,80,index);
    linkedlisttraversal(head);

    head=insertatend(head,100);
    linkedlisttraversal(head);

    return 0;
}

