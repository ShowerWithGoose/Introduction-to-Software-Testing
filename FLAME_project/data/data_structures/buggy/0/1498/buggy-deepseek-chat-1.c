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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [Error: The condition should check that both p and q are within the same range, not just p >= lower bound and q <= upper bound. For example, p >= 'a' && q <= 'z' allows p='a' and q='z' but also p='a' and q='9' which is incorrect. It should be (p >= 'a' && p <= 'z' && q >= 'a' && q <= 'z') etc.]
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
                expand(A[i], A[i + 2]); // @@ [Error: The expand function prints characters from p to q inclusive, but the problem requires expanding a-d to abcd, meaning it should print characters from p+1 to q-1 (the missing ones). The current implementation prints p, p+1, ..., q, which includes the endpoints that are already printed elsewhere, causing duplication and incorrect output.]
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