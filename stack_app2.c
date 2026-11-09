#include<stdio.h>
int top=-1;

int isstackfull(int arr[],int n){
    if(top==n-1){
        printf("stack is full");
        return 1;
    }
    else{
        return 0;
    }
}

int isstackempty(int arr[],int n){
    if(top==-1){
        printf("stack is empty");
        return 1;
    }
    else{
        return 0;
    }
}

int push(int arr[],int n,int x){
    if(!(isstackfull(arr,n))){
        top++;
        arr[top]=x;
    }
}

int pop(int arr[],int n){
    if(!(isstackempty(arr,n))){
        printf("popped item is:- %d",arr[top]);
        top--;
    }
}

void diplay(int arr[],int n){
    for(int i=top;i>=0;i--){
        printf("%d ",arr[i]);
    }
}

int peek(int arr[],int n){
    if(top==-1){
        printf("array is empty");
    }
    else{
        printf("peeked element is :- %d",arr[top]);
    }
}

int main(){
    int n;
    printf("enter size of Stack:- ");
    scanf("%d",&n);

    int arr[n];
    int arr_1[n];

    int choice=0;
    while(choice!=5){
        switch(choice){
            case 1: {
                int x;
                printf("enter element to process:- ");
                scanf("%d", &x);

                if (x % 2 == 0) {
                    push(arr, n, x); // Even = Push
                } 
                else {
                    pop(arr, n);     // Odd = Pop (using the same stack!)
                }
                break;
            }
            case 2:
                pop(arr,n);
                break;
            case 3:
                peek(arr,n);
                break;
            case 4:
                display(arr,n);
                break;
            default:
                printf("invalid choice");
        }
        printf("\nenter your choice:- ");
        scanf("%d",&choice);
    }

    return 0;
}