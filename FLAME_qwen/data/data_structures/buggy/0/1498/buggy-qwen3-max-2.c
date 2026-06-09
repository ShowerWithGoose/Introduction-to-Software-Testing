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
    gets(A); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic for detecting '-' is flawed—it checks A[i+1]=='-' instead of A[i]=='-']
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [This checks the next character for '-', but expansion should trigger when current character is '-'; also fails when '-' is at the end or beginning]
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