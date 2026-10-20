#include<stdio.h>
#include<stdlib.h>

int linear_step(int arr[],int n,int step,int target){

    int prev=0;
    int curr=0;

    if(n<=0)
        return -1;


    for(int i=0;i<n;i=i+step){
        if(arr[curr]<target){
            prev=curr+1;
            curr+=step;
        }
        else{
            break;
        }
    }

    int end=(curr<n)?curr:n-1;

    for(int i=prev;i<=end;i++){
        if(arr[i]==target){
            return i;
        }

    }
    return -1;
}

int main (){
    int n;
    printf("enter the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int step;
    printf("enter the step size:- ");
    scanf("%d",&step);

    int target;
    printf("enter the element to be searched:- ");
    scanf("%d",&target);

    int result=linear_step(arr,n,step,target);

    if(result==-1){
        printf("element not found");
    }
    else{
        printf("element found at index %d",result);
    }

    return 0;
}