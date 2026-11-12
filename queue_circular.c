#include<stdio.h>
#include<stdlib.h>

struct queue{
        int size;
        int front;
        int rear;
        int *arr;
    };

int isfull(struct queue *q){
    if((q->rear+1)%q->size==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(struct queue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q , int data){
    if(isfull(q)){
        printf("the queue is full \n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=data;
    }
}

int dequeue(struct queue *q){
    int val=0;
    if(isempty(q)){
        printf("The queue is empty \n");
        val=-1;
    }
    else{
        q->front=(q->front+1)%q->size;
        val=q->arr[q->front];
    }
    return val;
}

void peek(struct queue *q){
    if(isempty(q)){
        printf("the queue is empty \n");
    }
    else{
        printf("the peek element is %d\n",q->arr[q->front+1]);
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

    q=(struct queue *)malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    printf("Enter the size of the queue: ");
    scanf("%d",&q->size);
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,12);
    enqueue(q,13);
    enqueue(q,14);
    enqueue(q,15);
    enqueue(q,16);

    peek(q);

    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    display(q);

    return 0;
}