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
            printf("%c ", list[i]); // @@ prints a space after the last element, which is not required by the output format (expected no trailing space)
        }
        printf("\n");
        return;
    }
    else
    {
        int i;
        for (i = k; i <= m; i++)    // @@ the order of swaps does not generate permutations in lexicographic order; the problem requires sorted output in lexicographic order (see reference program)
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
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1;
    }
    Perm(list, 0, n - 1);
    return 0;
}