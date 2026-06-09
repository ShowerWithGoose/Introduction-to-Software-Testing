#include <stdio.h>
void swap(int arr[],int p,int q){ // @@ The swap function rotates elements instead of swapping, causing incorrect permutation generation and failure to restore the array state when p equals q. It should implement a simple swap.
    int temp=arr[q];
    for(int i=q;i>=p+1;i--){
        arr[i]=arr[i-1];
    }
    arr[p]=temp;
}

void swapback(int arr[],int p,int q){ // @@ The swapback function similarly rotates elements to restore, but does not correctly revert the array when p equals i, leading to corrupted array states. It should use a simple swap to restore.
    int temp=arr[p];
    for(int i=p;i<=q-1;i++){
        arr[i]=arr[i+1];
    }
    arr[q]=temp;
}


void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]); // @@ Missing space between numbers; expected output requires spaces (e.g., "%d ").
    }
    printf("\n");
}

void permute(int arr[],int p,int q){
    if(p==q){
        printArr(arr,q+1);
    }
    
    for(int i=p;i<=q;i++){
        swap(arr,p,i);
        permute(arr,p+1,q);
        swapback(arr,p,i);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=i+1;
    permute(arr,0,n-1);

    return 0;
}