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