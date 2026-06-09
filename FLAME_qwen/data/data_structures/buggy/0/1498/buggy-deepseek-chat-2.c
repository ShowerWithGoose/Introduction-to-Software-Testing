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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ The condition is incorrect; it should check that both characters are within the same range, not just that p is at the start and q is at the end. For example, 'a' and 'z' would pass, but 'a' and 'b' would also pass, which is fine, but the logic is flawed because it doesn't ensure both are in the same category. Additionally, it should check that p < q, which is missing.
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A); // @@ gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.
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
                i = i + 2; // @@ This skips the character after the dash, but the loop will increment i again, causing it to skip the next character after the expansion. This can lead to missing characters or out-of-bounds access.
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