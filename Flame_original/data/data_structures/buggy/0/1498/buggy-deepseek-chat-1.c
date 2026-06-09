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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ The condition is incorrect. It should check that both p and q are within the same range, not just that p is at the start and q is at the end. For example, 'a' and 'z' would pass, but 'a' and 'b' would also pass, which is fine, but 'a' and 'R' would incorrectly pass because p >= 'a' is true and q <= 'z' is false, but the OR condition with other ranges might still pass incorrectly. The correct logic should be: ((p >= 'a' && p <= 'z' && q >= 'a' && q <= 'z') || (p >= 'A' && p <= 'Z' && q >= 'A' && q <= 'Z') || (p >= '0' && p <= '9' && q >= '0' && q <= '9'))
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