#include<stdio.h>
char list[50];
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = *a;	// Should be *b = temp; typo? Actually the code has *b = temp; but in provided code it's *b = temp; so fine.
}
void Perm(char* list, int k, int m)
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             
        {
            printf("%c ", list[i]); // @@ For N>=10, prints non‑digit character (e.g., ':') instead of "10".
        }
        printf("\n");
        return;
    }
    else
    {
        int i;
        for (i = k; i <= m; i++) // @@ This swapping algorithm does not produce permutations in lexicographic order (required by problem). For N>2 the output order is wrong.
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
        list[i]=list[i-1]+1; // @@ For N=10, this line sets list[9]=':' (ASCII 58) instead of the two‑character sequence "10". The character representation fails for multi‑digit numbers.
    }
    Perm(list, 0, n - 1);
    return 0;
}