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
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]>arr[min]){
            min=j;
        }
    }
    if(min!=i){
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
  }  

    printf("sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}