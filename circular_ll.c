#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linkedlisttraversal(struct node* head){
    struct node* p=head;

    do{
        printf("%d ",p->data);
        if(p->next != head)
            printf("->");
        p=p->next;
    }while(p!=head);
}

int main(){
    struct node *newnode,*head,*temp,*second,*third,*fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=4;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;

    linkedlisttraversal(head);

}