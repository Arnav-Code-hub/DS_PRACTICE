#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];

int front=-1,rear=-1;

int isfull(){
    if(rear==N-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(){
    if(rear==front){
        front=-1;
        rear=-1;
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int x){
    if(isfull()){
        return ;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}


void dequeue(){
    if(isempty()){
        return;
    }
    else{
        front++;
        int x=queue[front];
        printf("dequeued element is %d\n", x);
    }
}

void diplay(){
    for(int i=front+1;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    diplay();
    dequeue();
    diplay();
    return 0;
}