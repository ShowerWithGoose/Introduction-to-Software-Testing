#include <stdio.h>
void swap(int arr[], int p, int q){
    int temp=arr[q];
    for(int i=q; i>=p+1; i--) // @@ [C89 does not allow declaration in for loop]
    {
        arr[i] = arr[i-1];
    }
    arr[p]=temp;
}
void swapback(int arr[], int p, int q){
    int temp=arr[p];
    for(int i=p; i<=q-1; i++) // @@ [C89 does not allow declaration in for loop]
    {
        arr[i] = arr[i+1];
    }
    arr[q]=temp;
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++) // @@ [C89 does not allow declaration in for loop]
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void perm(int arr[], int p, int q)
{
    if(p==q){
        print(arr, q+1);
    }
    else{
        for(int i=p; i<=q; i++) // @@ [C89 does not allow declaration in for loop]
        {
            swap(arr, p, i);
            perm(arr, p+1, q);
            swapback(arr, p, i);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n]; // @@ [Variable-length array not allowed in C89]
    for(int i=0; i<n; i++) // @@ [C89 does not allow declaration in for loop]
    {
        arr[i]=i+1;
    }
    perm(arr, 0, n-1);
    return 0;
}