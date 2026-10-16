#include<stdio.h>
#include<stdlib.h>

void sliding_window(int arr[], int n,int k){
    int left,right,sum;
    left=0;
    right=n-1;
    sum=0;
    int lenght=0;
    int min=n+1;
    for(int i=0;i<right;i++){
        sum=sum+arr[i];
        while (sum>k){
            sum=sum-arr[left];
            left++;
        }
        lenght=i-left+1;
        if(min>lenght)
            min=lenght;
    }
    
}
int main(){
    int n;
    printf("enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int k;
    printf("enter the sum size:-");
    scanf("%d",&k);

    sliding_window(arr,n,k);
}