#include <stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[b];
    for(int i = b; i > a; --i) // @@ Declaring loop variable inside the for loop initialization is a C99 feature and causes a compilation error in C89/C90 standard environments.
        arr[i] = arr[i - 1];
    arr[a] = temp;
}

void printout(int arr[], int len){
    for(int i = 0; i < len; ++i) // @@ Declaring loop variable inside the for loop initialization is a C99 feature and causes a compilation error in C89/C90 standard environments.
        printf("%d ", arr[i]);
    printf("\n");
}

void perm(int arr[], int start, int end){
    if(start == end)
        printout(arr, end + 1);
    else{
        for(int i = start; i <= end; ++i){ // @@ Declaring loop variable inside the for loop initialization is a C99 feature and causes a compilation error in C89/C90 standard environments.
            swap(arr, start, i);
            perm(arr, start + 1, end);
            swap(arr, start, i);
        }
    }
}


int main(){
    int n, arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) // @@ Declaring loop variable inside the for loop initialization is a C99 feature and causes a compilation error in C89/C90 standard environments.
        arr[i] = i + 1;
    perm(arr, 0, n - 1);
    return 0;
}