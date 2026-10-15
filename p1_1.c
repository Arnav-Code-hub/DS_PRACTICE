#include<stdio.h>
#include<stdlib.h>

void bitonic(int arr[],int n){
    int inc[n],dec[n];

    inc[0]=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]<arr[i+1]){
            inc[i+1]=inc[i]+1;
        }
        else
            inc[i+1]=1;
    }

    dec[n-1]=1;
    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            dec[i-1]=dec[i]+1;
        }
        else
            dec[i-1]=1;
    }

    int index=0;
    int lenght=0,max=0;

    for(int i=0;i<n;i++){
        lenght=inc[i]+dec[i]-1;
        if(lenght>max){
            max=lenght;
            index=i;
        }  
    }

    int start=index-inc[index]+1;
    int end=index+dec[index]-1;

    printf("Length of longest bitonic subsequence is %d\n",max);
    printf("The longest bitonic subsequence is:\n");
    for(int i=start;i<=end;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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

    bitonic(arr,n);
}