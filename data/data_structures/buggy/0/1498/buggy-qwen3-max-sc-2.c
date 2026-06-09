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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [The condition is incorrect: it checks if p is >= 'a' and q <= 'z', which allows mixed cases like p='z' and q='a'; it should ensure both are in the same category and p < q]
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, the problem expects handling of '-' at any position, but logic below only checks if next char is '-', not current]
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [This checks if the NEXT character is '-', meaning it processes patterns like "a-b" as when i points to 'a', but misses standalone '-' at start or end, and misaligns indices]
        {
            k = toexpand(A[i], A[i + 2]); // @@ [If A[i+1] is '-', then A[i] and A[i+2] are the bounds, but this assumes there is always a character after '-', which may not be true if '-' is at the end]
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ [Skips two characters after expansion, but loop increments i again, causing potential skip of next character or out-of-bound access]
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