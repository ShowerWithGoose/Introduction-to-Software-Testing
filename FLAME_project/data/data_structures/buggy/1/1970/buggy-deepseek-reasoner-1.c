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
        for (i = 0; i <= m; ++i)             
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
            Swap(&list[k], &list[i]);  // @@ This algorithm does not generate permutations in lexicographic order. For N>=3, output order will be incorrect.
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
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1; // @@ This works only for N<=9. For N=10, it produces ':' instead of "10". Should use integer array and print integers.
    }
    Perm(list, 0, n - 1);
    return 0;
}