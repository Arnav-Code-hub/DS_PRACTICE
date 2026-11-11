#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front,rear;
    int size;
    int *arr;
};

int isempty(struct queue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int x){
    if(isfull(q)){
        printf("queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear]=x;
    }
}

void dequeue(struct queue *q){
    if(isempty(q)){
        printf("queue is empty \n");
    }
    else{
        q->front++;
        int x=q->arr[q->front];
        printf("dequeued element is %d\n", x);
    }
}

void display(struct queue *q){
    if(isempty(q)){
        printf("queue is empty\n");
    }
    else{
        for(int i=q->front+1;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->rear=q->front=-1;
    q->size=5;
    q->arr=(int *)malloc(sizeof(int)*(q->size));

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}