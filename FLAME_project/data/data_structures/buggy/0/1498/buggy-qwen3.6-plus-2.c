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
    if ((p >= 'a' && p <= 'z' && q >= 'a' && q <= 'z') || (p >= 'A' && p <= 'Z' && q >= 'A' && q <= 'Z') || (p >= '0' && p <= '9' && q >= '0' && q <= '9')) // @@ [The original logic incorrectly checked if p was in range and q was in range independently without ensuring they were the SAME type. For example, 'a' (>= 'a') and 'Z' (<= 'Z') would return true in the original code because it used ORs loosely or mixed ranges. Specifically, the original code `(p >= 'a' && q <= 'z')` checks if p is lowercase start and q is lowercase end, but doesn't check if p is also <= 'z' or q is also >= 'a'. More importantly, it fails to enforce that BOTH are lowercase, or BOTH are uppercase, or BOTH are digits. The corrected version ensures p and q fall within the same specific character class.]
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A);
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-')
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                if (A[i] < A[i+2]) // @@ [The problem requires expansion only if the character after '-' is greater than the one before. The original code missed this check, potentially expanding invalid ranges like c-a.]
                {
                    expand(A[i], A[i + 2]);
                    i = i + 2;
                }
                else
                {
                     printf("%c", A[i]); // @@ [If expansion condition (greater than) is not met, output the current character normally.]
                }
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