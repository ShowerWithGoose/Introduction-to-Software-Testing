#include <stdio.h>
int n, arr[10]={}, used[10]={}; // @@ arr and used are size 10, but indices 1..n can access arr[10] and used[10] when n=10, which is out-of-bounds. Should be at least size 11 (e.g., arr[11]).
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
            printf("%d", arr[i]); // @@ Missing space after each number. Should be printf("%d ", arr[i]);
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