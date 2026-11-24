#include<stdio.h>

int main(){
    int n;
    printf("enter size of arr:-");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("enter key to be searched:-");
    scanf("%d",&key);

    int high=n-1;
    int low=0;
    int mid=0;
    int flag =0;

    while(high>=low){
        mid=(high+low)/2;

        if(arr[mid]==key){
            printf("%d",mid);
            flag=1;
            break;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    if(flag==0){
       printf("element not found"); 
    }
    return 0;
}