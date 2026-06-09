#include<stdio.h>
char list[50]; // @@ Should be int list[50] to store integers 1 to N correctly, especially for N=10.
void Swap(char *a, char *b) // @@ Parameter types should be int* to match the integer array elements.
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m) // @@ Parameter type should be int* to match the integer array.
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             
        {
            printf("%c ", list[i]); // @@ Should use "%d" to print integers instead of characters.
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
    list[0]='1'; // @@ Should initialize with integer 1 instead of character '1'.
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1;
    }
    Perm(list, 0, n - 1);
    return 0;
}