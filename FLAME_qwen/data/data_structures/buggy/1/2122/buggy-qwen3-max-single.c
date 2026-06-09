#include <stdio.h>
int n, arr[10]={}, used[10]={};
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
            printf("%d", arr[i]); // @@ [Missing space between numbers as required by output format; should be "%d " instead of "%d"]
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