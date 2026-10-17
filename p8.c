#include<stdio.h>

void mergesort(int arr[],int start,int end){
    if(start<end){
        int mid=start+((end-start)/2);
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void merge(int arr[],int start,int mid,int end){
    int n=end+1;
    int b[n];
    int k=start;
    int i=start;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]>=arr[j]){
            b[k]=arr[j];
            j++;
        }
        else{
            b[k]=arr[i];
            i++;
        }
        k++;
    }

    while(i<=mid){
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=end){
        b[k]=arr[j];
        k++;
        j++;
    }

    for(int idx=start;idx<end;idx++){
        arr[idx]=b[idx];
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

    mergesort(arr,0,n-1);

    printf("sorted array is: ");
    for(int i=0; i<=n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}