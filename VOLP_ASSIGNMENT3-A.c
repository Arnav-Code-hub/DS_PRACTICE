#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter size of arr:-");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-2;i=i+2){
        for(int j=0;j+2<n-i;j=j+2){
            if(arr[j]>arr[j+2]){
                int temp=arr[j];
                arr[j]=arr[j+2];
                arr[j+2]=temp;
            }
        }
    }
    for(int i=1;i<n-2;i=i+2){
        for(int j=1;j+2<n-i;j=j+2){
            if(arr[j]>arr[j+2]){
                int temp=arr[j];
                arr[j]=arr[j+2];
                arr[j+2]=temp;
            }
        }
    }

    printf("The bubble sorted order is :- ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}