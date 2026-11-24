#include<stdio.h>

void quicksort(int arr[],int start,int end){
    if(start<=end){
        int pi=partition(arr,start,end);
        quicksort(arr,start,pi-1);
        quicksort(arr,pi+1,end);
    }
}

int partition(){
    int pivot;
    int index;

    for(){
        if(){
            index++;
            swap
        }
    }

    swap()

    return index+1;
}