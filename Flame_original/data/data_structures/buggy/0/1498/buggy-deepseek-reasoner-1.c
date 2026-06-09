#include<stdio.h>

void expand(char p,char q)
{
    int i = 0;
    int k=p;
    for (i = 0; i <=(q - p); i++) // @@ [Error: This loop prints both endpoints p and q. It should only print intermediate characters (i from 1 to q-p-1) to avoid duplication and handle multiple expansions correctly.]
    {
        printf("%c", k);
        k++;
    }
}

int toexpand(char p, char q)
{
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [Error: Condition does not require both characters to be in the same category and p < q. Should check both p and q are within the same range (lowercase, uppercase, or digit) and p < q.]
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
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ [Error: This increment skips the character after the dash, causing the next potential expansion to miss its starting character. Should be i = i + 1 to skip only the dash, allowing the next iteration to process the end character.]
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