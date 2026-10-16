#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
            
        }
        if(flag==0)
                break;
    }

    printf("sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}