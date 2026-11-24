#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front,rear;
    int size;
    int *arr;
};

int isempty(struct queue *q){
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
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

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("queue is empty \n");
    }
    else{
        q->front++;
        int x=q->arr[q->front];
        printf("dequeued element is %d\n", x);
        return x;
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

    //bfs implementation
    int node;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isempty(q)){
        int node=dequeue(q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                visited[j]=1;
                printf("%d",j);
                enqueue(q,j);
            }
        }
    }

    return 0;
}