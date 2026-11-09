#include<stdio.h>
int top=-1;

void check_parenthesis(){

}

int isstackempty(char arr[],int n){
    if(top==-1){
        printf("array is empty");
        return 0;
    }
    else
        return 1;
}

int isstackfull(char arr[],int n){
    if(top == n-1){
        printf("stack is full");
        return 0;
    }
    else 
        return 1;
}

int push(char arr[],int n,char x){
    if((isstackfull(arr,n))){
        top++;
        arr[top]=x;
    }
}

int pop(char arr[],int n){
    if((isstackfull(arr,n))){
        printf("element popped is %c",arr[top]);
        top--;
    }
}



int main(){
    int n;
    printf("enter size of Stack:- ");
    scanf("%d",&n);

    char arr[n];
    printf("enter the parenthesis:- ");
    for (int i=0;i<n;i++){
        scanf("%c",                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            &arr[i]);
    }


}