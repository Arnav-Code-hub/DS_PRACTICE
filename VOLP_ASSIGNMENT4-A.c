#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
    int n=high+1;
    int b[n];

    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high){
        if(arr[i]< arr[j]){
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k]=arr[j];
        j++;
        k++;
    }

    for(int l=low;l<=high;l++){
        arr[l]=b[l];
    }
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){}