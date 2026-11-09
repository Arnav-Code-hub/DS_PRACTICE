#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isstackempty(struct stack* ptr){
    if(ptr -> top == -1){
        printf("stack is empty \n");
        return 1;
    }
    else 
        return 0;
}

int isstackfull(struct stack* ptr){
    if(ptr -> top == (ptr->size)-1){
        printf("stack is full \n");
        return 1;
    }
    else 
        return 0;
}

void push (struct stack* ptr){
    printf("enter element to be pushed :-");
    int x;
    scanf("%d",&x);
    ptr->top++;
    ptr->arr[ptr->top]=x;
}

void pop(struct stack* ptr){
    printf("the popped element is %d \n",ptr->arr[ptr->top]);
    ptr->top--;
}

void peek(struct stack* ptr){
    printf("The topmost element is %d \n",ptr->arr[ptr->top]);
}

void display (struct stack* ptr){
    int n=ptr->top;
    for(int i=n;i>=0;i--){
        printf("%d   ",ptr->arr[i]);
    }
}

int main(){
    // struct stack s;
    // printf("enter size of Stack:- ");
    // scanf("%d",&s.size);
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    //else if we create a stack using pointer then we can use this method
    struct stack *s;
    printf("enter size of Stack:- ");
    scanf("%d",&s -> size);
    s -> top=-1;
    s -> arr=(int *)malloc(s -> size*sizeof(int));

    push(s);

    if(isstackempty(s)){
        printf("stack is empty \n");
    }
    else 
        printf("stack is not empty \n");

    pop(s);
    if(isstackempty(s)){
        printf("stack is empty \n");
    }
    else 
        printf("stack is not empty \n");

}