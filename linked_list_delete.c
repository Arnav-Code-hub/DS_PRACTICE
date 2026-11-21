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

struct node * deletefirstnode(struct node* head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node * deleteindexnode(struct node *head,int index){
    struct node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    struct node * q=p->next;
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

struct node* deletevaluenode(struct node * head,int key){
    struct node* p=head;
    struct node* q=head->next;
    while(key!=q->data && q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    if(q->data==key){
        p->next=q->next;
        free(q);        
    }   

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

    // head=deletefirstnode(head);
    // head=deleteindexnode(head,1);
    // head=deletelastnode(head);
    head=deletevaluenode(head,2);
    linkedlisttraversal(head);

    return 0;
}

