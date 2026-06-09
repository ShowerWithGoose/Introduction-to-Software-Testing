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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9'))
        return 1;
    else
        return 0;
} // @@ [The condition checks are incorrect: it should verify that both p and q are in the same category (e.g., both lowercase), but current logic allows mixed cases like p='a' and q='Z' to pass as long as p >= 'a' and q <= 'z', which is logically wrong.]

 
int main(void)
{
    char A[50] ;
    gets(A);
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [This accesses A[i+1] and later A[i+2] without checking if they exist, leading to out-of-bounds access when '-' is at the end or second last position. Also, the logic looks ahead for '-' instead of processing current character, causing misalignment in parsing.]
        {
            k = toexpand(A[i], A[i + 2]); // @@ [Relies on faulty toexpand() and accesses A[i+2] without bounds check.]
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