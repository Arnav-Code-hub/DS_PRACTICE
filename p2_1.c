#include <stdio.h>

int linear_step(int arr[], int n, int key,int step) {
    int curr=0,prev=0;
    
    if(n<=0)
        return -1;
    
    while(curr<n && key>arr[curr]){
        prev=curr+1;
        curr=curr+step;
    }

    int end;
    if(curr>n-1){
       end=n-1; 
    }
    else{
        end=curr;
    }

    for(int i=prev;i<=end;i++){
        if(arr[i]==key){
            return i;
        }
    }

    return -1;
}

int main(){
    printf("enter the array size");
    int n,key,step;
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements:-");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to be searched :- ");
    scanf("%d",&key);

    printf("enter the step size:- ");
    scanf("%d",&step);

    int result=linear_step(arr,n,key,step);

    if(result==-1){
        printf("key not found");
    }
    else
        printf("element found at index %d",result);
}