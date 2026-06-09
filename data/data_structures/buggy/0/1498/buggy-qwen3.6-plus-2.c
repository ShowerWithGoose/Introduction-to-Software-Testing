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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [Logical Error: The condition incorrectly validates ranges. It fails to check that both p and q are within the same type bounds (e.g., missing p <= 'z' and q >= 'a') and does not verify p < q as required.]
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A); // @@ [Compilation Error: gets() is deprecated and removed in the C11 standard, causing compilation failure in modern environments. Use fgets() instead.]
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [Potential Out-of-Bounds: Accessing A[i+1] without checking if i+1 is within the string bounds may read past the null terminator.]
        {
            k = toexpand(A[i], A[i + 2]); // @@ [Potential Out-of-Bounds: Accessing A[i+2] without verifying the string length may cause undefined behavior if '-' appears near the end of the string.]
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