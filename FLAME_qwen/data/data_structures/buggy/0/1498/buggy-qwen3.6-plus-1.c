#include<stdio.h>

void expand(char p,char q)
{
    int i = 0;
    int k=p;
    for (i = 0; i <=(q - p); i++)
    {
        printf("%c", k);
        k++;
    }
}

int toexpand(char p, char q)
{
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ Logical error: The condition incorrectly checks ranges. It should verify that both p and q belong to the same category (lowercase, uppercase, or digits) and that q > p. The current expression allows mixed types (e.g., 'a' and 'A') and does not ensure p is within the specified range.
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A); // @@ Compilation error: 'gets' is deprecated and officially removed in the C11 standard, which causes compilation failures in modern strict environments. It should be replaced with 'fgets(A, sizeof(A), stdin)'.
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-')
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2;
            }
            if(k==0)
                printf("%c",A[i]);
        }
        else
            printf("%c", A[i]);
        i++;
    }
    return 0;
}