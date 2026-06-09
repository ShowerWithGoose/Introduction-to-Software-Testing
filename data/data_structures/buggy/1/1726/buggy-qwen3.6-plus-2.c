#include <stdio.h>
void swap(int arr[],int p,int q){
    int temp=arr[q];
    for(int i=q;i>=p+1;i--){
        arr[i]=arr[i-1];
    }
    arr[p]=temp;
}

void swapback(int arr[],int p,int q){
    int temp=arr[p];
    for(int i=p;i<=q-1;i++){
        arr[i]=arr[i+1];
    }
    arr[q]=temp;
}


void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]); // @@ Missing space separator between numbers, violates the output format requirement.
    }
    printf("\n");
}

void permute(int arr[],int p,int q){
    if(p==q){
        printArr(arr,q+1); // @@ Missing return statement after the base case, which leads to incorrect recursion flow and potential duplicate or out-of-order outputs.
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
    int arr[n]; // @@ Variable Length Array (VLA) may cause a compilation error in strict C89/C90 environments; use a fixed-size array (e.g., int arr[11];) since N<=10.
    for(int i=0;i<n;i++)
    arr[i]=i+1;
    permute(arr,0,n-1);

    return 0;
}