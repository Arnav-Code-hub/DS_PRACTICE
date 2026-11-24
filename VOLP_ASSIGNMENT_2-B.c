#include<stdio.h>

int fisrtoccurance(int arr[],int n,int key){
    int high=n-1;
    int low=0,mid=0;
    int first=0;

    while(high>=low){
        mid=(high+low)/2;

        if(arr[mid]==key){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return first;
}

int lastoccurance(int arr[],int n,int key){
    int high=n-1;
    int low=0,mid=0;
    int last=0;

    while(high>=low){
        mid=(high+low)/2;

        if(arr[mid]==key){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return last;
}

int frequency(int arr[],int n,int key){
    int first=fisrtoccurance(arr,n,key);
    int last=lastoccurance(arr,n,key); 

    if(first==-1 || last==-1)
        return -1;

    return(last=last-first+1);
}

int main(){
    int n;
    printf("enter size of arr:-");
    scanf("%d",&n);

    int arr[n];

    printf("enter sorted arr:-");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("enter key to be searched:-");
    scanf("%d",&key);

    int result = frequency(arr,n,key);
    printf("\n %d",result);
    return 0;
}