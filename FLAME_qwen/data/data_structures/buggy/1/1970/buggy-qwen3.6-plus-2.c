#include<stdio.h>
char list[50]; // @@ Should be int list[50] to store integers 1 to N correctly, as char cannot hold values >= 10 and %c prints ASCII characters.
void Swap(char *a, char *b) // @@ Parameters should be int* to match the array element type.
{
    char temp; // @@ Should be int temp to match the swapped element type.
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m) // @@ Parameter should be int* list to match the array type.
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             
        {
            printf("%c ", list[i]); // @@ Should use %d format specifier to print integers instead of characters.
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
    list[0]='1'; // @@ Should assign integer 1 instead of character '1' to initialize the sequence correctly.
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1;
    }
    Perm(list, 0, n - 1);
    return 0;
}