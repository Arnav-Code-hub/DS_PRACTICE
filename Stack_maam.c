#include<stdio.h>
int top=-1;

int isstackfull(int arr[],int n){
    if(n-1==top){
        return 1;
    }
    else{
        return 0;
    }
}

int isstackempty(int arr[],int n){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(int arr[],int n,int x){
    if(!(isstackfull)){
        top++;
        arr[top]=x;
    }
    else{
        printf("stack is full");
    }
}

int pop(int arr[],int n){
    if(!(isstackempty)){
        printf("popped item is:- %d",arr[top]);
        top--;
    }
    else{
        printf("stack is empty");
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

void display(int arr[],int n){
    for(int i=top;i>=0;i--){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("enter size of Stack:- ");
    scanf("%d",&n);

    int arr[n];

    int choice=0;
    clrscr();
    printf("enter 1 to push\n");
    printf("enter 2 to pop\n");
    printf("enter 3 to peek\n");
    printf("enter 4 to display\n");
    printf("enter 5 to exit\n");

    printf("enter your choice:- ");
    scanf("%d",&choice);

    while(choice!=5){
        switch(choice){
            case 1:
                int x;
                printf("enter element to push:- ");
                scanf("%d",&x);
                push(arr,n,x);
                break;
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