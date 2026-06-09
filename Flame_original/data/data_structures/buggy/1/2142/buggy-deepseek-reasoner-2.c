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
int swap(int arr[], int a, int b) // @@ 函数声明返回int但缺少return语句，导致编译错误（严格模式下强制返回类型必须匹配）
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
} // @@ 缺少return语句，函数返回类型为int，产生编译错误
void perm(int a[], int begin, int n)
{
    if(begin==n)
    {
        for(int i=0;i<=n;i++) // @@ 在C89标准中不允许在for循环内声明变量，导致编译错误
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int j = begin;j<=n;j++) // @@ 在C89标准中不允许在for循环内声明变量，导致编译错误
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