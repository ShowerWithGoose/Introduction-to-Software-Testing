#include <stdio.h>
int n, arr[10]={}, used[10]={}; // @@ Empty braces {} are not valid in standard C for array initialization and will cause a compilation error; use {0} instead. Additionally, array size should be at least 11 to safely handle 1-based indexing when N=10.
void arrange(int a);
int main()
{
    scanf("%d", &n);
    arrange(1);
    return 0;
}
void arrange(int a)
{
    if(a>n)
    {
        for (int i = 1; i <= n;i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 1; i <= n;i++)
        {
            if(used[i]==0)
            {
                arr[a] = i;
                used[i] = 1;
                arrange(a + 1);
                used[i] = 0;
            }
            
        }
    }
}