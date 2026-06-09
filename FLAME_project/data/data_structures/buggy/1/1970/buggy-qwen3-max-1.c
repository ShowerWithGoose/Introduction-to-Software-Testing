#include<stdio.h>
char list[50];
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m)
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             // @@ [The loop should run from 0 to m-1, not m. Since m = n-1, this prints n+1 characters instead of n.]
        {
            printf("%c ", list[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        int i;
        for (i = k; i <= m; i++)
        {
            Swap(&list[k], &list[i]);  
            Perm(list, k + 1, m);
            Swap(&list[k], &list[i]);
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    list[0]='1';
    for(i=1;i<n;i++)                         // @@ [This loop only fills indices 0 to n-2, leaving list[n-1] uninitialized. It should be i < n, not i < n.]
    {
        list[i]=list[i-1]+1;
    }
    Perm(list, 0, n - 1);
    return 0;
}