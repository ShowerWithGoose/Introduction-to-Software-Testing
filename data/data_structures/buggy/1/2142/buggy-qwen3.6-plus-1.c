#include<stdio.h>/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdlib.h>
long long f(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return n*f(n-1);
}
int swap(int arr[], int a, int b) // @@ Function is declared to return int but lacks a return statement, causing a compilation error. It should be void.
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void perm(int a[], int begin, int n) // @@ The current backtracking algorithm does not guarantee lexicographical order of output permutations as required by the problem statement.
{
    if(begin==n)
    {
        for(int i=0;i<=n;i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int j = begin;j<=n;j++)
        {
            swap(a, begin, j);
            perm(a, begin+1, n);
            swap(a, begin, j);
        }
    }
}
int main()
{
    
    int n, i;
    int* a;
    scanf("%d", &n);
    a=(int*)calloc(n, sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        
    }
    perm(a, 0, n-1);
    return 0;
}