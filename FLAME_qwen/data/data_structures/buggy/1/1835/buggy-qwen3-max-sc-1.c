#include <stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[b];
    for(int i = b; i > a; --i)
        arr[i] = arr[i - 1];
    arr[a] = temp;
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
            swap(arr, start, i);
            perm(arr, start + 1, end);
            swap(arr, start, i); // @@ [The swap function does not correctly reverse the rotation. The current 'swap' actually rotates elements left-to-right, and undoing it requires a different operation (like the 'derearr' in the reference). Using the same 'swap' to undo leads to incorrect array state restoration, causing wrong permutations and possibly duplicates or missing outputs.]
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