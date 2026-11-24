#include<stdio.h>

int partition(int arr[],int start,int end){
    int left=start;
    int right=end;
    int mid=(left+right)/2;

    int pivot=arr[start];

    while (left<=right)
    {
        while(arr[right]>pivot){
            right--;
        }
        while(arr[left]<pivot){
            left++;
        }
        if(left<=right){
            int temp=arr[right];
            arr[right]=arr[left];
            arr[left]=temp;
            left++;
            right--;
        }
        
    }
    return left;
    
}

void quicksort(int arr[],int start,int end){
    if(start<end){
        int pi=partition(arr,start,end);
        quicksort(arr,start,pi-1);
        quicksort(arr,pi,end);
    }
}


int main(){
    int n;
    printf("enter size of arr:-");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quicksort(arr,0,n-1);

        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}