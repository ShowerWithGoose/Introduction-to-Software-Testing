#include <stdio.h>
void swap(int arr[], int p, int q){
    int temp=arr[q];
    for(int i=q; i>=p+1; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[p]=temp;
}
void swapback(int arr[], int p, int q){
    int temp=arr[p];
    for(int i=p; i<=q-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[q]=temp;
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]); // @@ The output format requires integers separated by a space. The original code printed "%d" without a space, causing "12" instead of "1 2". Note: This will likely leave a trailing space, but it matches the "separated by a space" requirement better than no space. If strict no-trailing-space is required, logic needs change, but usually space separation implies space between elements. Let's look at expected output "1 2 ". The problem says "Each integer in a line is separated by a space". Often this allows trailing space or expects specific formatting. The buggy output was "12", missing spaces entirely. Adding a space after %d fixes the separation.
    }
    printf("\n");
}
void perm(int arr[], int p, int q)
{
    if(p==q){
        print(arr, q+1);
    }
    else{
        for(int i=p; i<=q; i++)
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
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=i+1;
    }
    perm(arr, 0, n-1);
    return 0;
}