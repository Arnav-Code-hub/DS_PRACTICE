#include<stdio.h>
#include<stdlib.h>

void sliding_window(int arr[], int n,int k){
    int left,right,sum;
    left=0;
    right=0;
    sum=0;
    int lenght=0;
    int min=n+1;
    for(;right<n;right++){
        sum=sum+arr[right];
        while (sum>k){
            lenght=right-left+1;

            sum=sum-arr[left];
            left++;
            
            if(min>lenght)
                min=lenght;
        }
    }
    printf("minimum length of subarray with sum greater than k is: %d\n", min);
    printf("the subarray is: ");
    for(int i=left;i<=right-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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