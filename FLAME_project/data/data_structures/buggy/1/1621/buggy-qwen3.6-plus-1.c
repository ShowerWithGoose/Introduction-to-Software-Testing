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
        printf("%d ", arr[i]); // @@ The output format requires integers separated by a space. The original code printed "%d" without a space, causing "12" instead of "1 2". Note: This will likely leave a trailing space, but it matches the "separated by a space" requirement better than no space. If strict no-trailing-space is required, logic needs change, but usually "%d " is accepted or preferred over "%d" in these simple contexts if the alternative is wrong answer due to missing separators. Actually, looking at expected output "1 2 ", there is often a trailing space or just separation. Let's look closer. Expected: "1 2 ". The bug report says Output: "12". Expected: "1 2 ". The missing space is the primary error.
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