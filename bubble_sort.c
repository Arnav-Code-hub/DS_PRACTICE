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

    int count=0;
    int flag=1;

    for(int i=0;i<n-1;i++){
        flag=1;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=0;
                count ++;
            }
        }
        if(flag==1){
            break;
        }
    }

    printf("The bubble sorted order is :- ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("%d ",count);
}