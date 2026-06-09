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
        return 1; // @@ The condition is incorrect. It should check that both p and q are within the same range, not just p >= lower bound and q <= upper bound. For example, it should be (p >= 'a' && q <= 'z' && p <= 'z' && q >= 'a') or more simply check each character individually. This causes incorrect expansion decisions.
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
                i = i + 2; // @@ After expanding, the loop increments i by 1 at the end, so i becomes i+3, skipping the character after the dash. However, the expected output for "a-c-g" is "abcdefg", meaning after expanding a-c, the next character should be '-' which should be processed again. This logic incorrectly skips the second dash.
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