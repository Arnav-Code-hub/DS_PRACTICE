#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char * arr;
};

int isstackempty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isstackfull(struct stack *s){
    if(s->top==(s->size)-1){
        return 1;
    }
    else{
        return 0;
    }
}


int push(struct stack *s,char x){
    if(isstackfull(s)){
        return -1;
    }
    else{
        s->top++;
        s->arr[s->top]=x;
    }
    return 0;
}

char pop(struct stack *s){
    if(isstackempty(s)){
        return -1;
    }
    else{
        char x=s->arr[s->top];
        s->top--;
        return x;
    }
}

int main(){
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=100;
    s->arr=(char *)malloc(sizeof(char)*(s->size));

    printf("Enter the word to be pushed in to the stack:- ");
    scanf("%s",s->arr);

    for(int i=0;s->arr[i]!='\0';i++){
        push(s,s->arr[i]);
    }

    for(int i=s->top;i>=0;i--){
        printf("%c",pop(s));
    }
}