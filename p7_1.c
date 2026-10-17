#include<stdio.h>

int partition(int arr[],int start,int end){
    int index=start-1;
    int pivot=arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<pivot){
            index++;
            int temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
        }
    }

    //swap index element
    int temp=arr[end];
    arr[end]=arr[index+1];
    arr[index+1]=temp;

    return (index+1);
}

void quicksort(int arr[],int start,int end){
    if(start<end){
        int pi=partition(arr,start,end);
        quicksort(arr,start,pi-1);
        quicksort(arr,pi+1,end);
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

    quicksort(arr, 0, n-1);

    printf("sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
}