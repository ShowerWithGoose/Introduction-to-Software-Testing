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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ The condition is incorrect; it should check that both p and q are within the same range, not just p >= lower bound and q <= upper bound. For example, it should be (p >= 'a' && p <= 'z' && q >= 'a' && q <= 'z') etc.
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
                expand(A[i], A[i + 2]); // @@ The expand function prints characters from p to q inclusive, but the problem requires printing the characters between p and q, not including p (since p is already printed in the previous iteration or will be handled incorrectly). Additionally, the expand function prints p again, leading to duplication. The loop should start from p+1 to q-1 or adjust the logic.
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