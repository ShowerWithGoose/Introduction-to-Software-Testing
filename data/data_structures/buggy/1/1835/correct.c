#include <stdio.h>

void swap_a(int arr[], int a, int b){
    int temp = arr[b];
    for(int i = b; i > a; i--)
        arr[i] = arr[i - 1];
    arr[a] = temp;
}

void swap_b(int arr[], int a, int b){
    int temp = arr[a];
    for(int i = a; i < b; i++)
        arr[i] = arr[i + 1];
    arr[b] = temp;
}
void printout(int arr[], int len){
    for(int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void perm(int arr[], int start, int end){
    if(start == end)
        printout(arr, end + 1);
    else{
        for(int i = start; i <= end; ++i){
            swap_a(arr, start, i);
            perm(arr, start + 1, end);
            swap_b(arr, start, i);
        }
    }
}


int main(){
    int n, arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    perm(arr, 0, n - 1);
    return 0;
}

