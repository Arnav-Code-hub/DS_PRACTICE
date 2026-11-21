#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char * arr;
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

void push (struct stack* ptr,char x){
    printf("enter element to be pushed :-");
    int ch;
    ch=x;

    if(isstackfull(ptr)){
        printf("stack is full \n");
        return -1;
    } 
    else{
    ptr->top++;
    ptr->arr[ptr->top]=ch;
    }
}

int pop(struct stack* ptr){
    if(isstackempty(ptr)){
        printf("stack is empty \n");
        return -1;
    }   
    else{
    printf("the popped element is %c \n",ptr->arr[ptr->top]);
    ptr->top--;
    }
}

void peek(struct stack* ptr){
    printf("The topmost element is %c \n",ptr->arr[ptr->top]);
}

void display (struct stack* ptr){
    int n=ptr->top;
    for(int i=n;i>=0;i--){
        printf("%d   ",ptr->arr[i]);
    }
}

int checkparenthesis(char * exp){
    struct stack * sp;
    sp->size=sizeof(exp);
    sp->top=-1;
    sp->arr=(char *)malloc(sizeof(char)*sp->size);

    for(int i=0;exp[i]!=0;i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isstackempty(sp)){
                return 0;
            }
            if(sp->arr[sp->top]==exp[i]){
                pop(sp);
            }
            else{
                return 0;
            }

        }

    }
    return isstackempty(sp);
}


int main(){
    struct stack *s;
    printf("enter size of Stack:- ");
    scanf("%d",&s -> size);
    s -> top=-1;
    s -> arr=(char *)malloc(s -> size*sizeof(char));

    printf("enter the expression:- ");
    char exp[100];
    scanf("%s",exp);
    int result = checkparenthesis(exp);
    if(result){
        printf("The expression has balanced parentheses.\n");
    }
    else{
        printf("The expression has unbalanced parentheses.\n");
    }

}