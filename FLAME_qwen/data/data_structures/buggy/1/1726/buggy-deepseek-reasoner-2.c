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
        printf("%d",arr[i]); // @@ Missing space between numbers; should be printf("%d ",arr[i]); to match required output format.
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
    int arr[n]; // @@ Variable-length array (VLA) not supported in all compilers (e.g., C90). Use a fixed-size array like int arr[11]; to match reference program and avoid compilation error.
    for(int i=0;i<n;i++)
    arr[i]=i+1;
    permute(arr,0,n-1);

    return 0;
}