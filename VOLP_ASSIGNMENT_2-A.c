#include<stdio.h>
#include<stdlib.h>

int linear_step(int arr[],int step,int n,int key){
    int prev,curr;
    
    if(n<0)
        return -1;
    
    for(int i=0;i<n;i=i+step){
        if(arr[curr]<key){
            prev=curr;
            curr=curr+step;
        }
        else{
            break;
        }        
    }

    int end=0;
    if(curr<n){
        end=curr;
    }
    else{
        end=n-1;
    }

    for(int i=prev;i<end;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("enter size of arr:-");
    scanf("%d",&n);

    int arr[n];

    printf("enter sorted arr:-");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int step;
    printf("enter size of step:-");
    scanf("%d",&step);

    int key;
    printf("enter key to be searched:-");
    scanf("%d",&key);

    int result=linear_step(arr,step,n,key);
    printf("%d",result);

    return 0;
}