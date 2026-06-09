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
} // @@ [The condition checks are incorrect: it should verify that both p and q are in the same category (e.g., both lowercase), but instead it checks p >= 'a' and q <= 'z', which allows mixed cases like p='A' and q='z' to pass. Also, it doesn't ensure p < q.]

 
int main(void)
{
    char A[50] ;
    gets(A);
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [This accesses A[i+1] and later A[i+2] without checking if they exist, leading to out-of-bounds access when '-' is at the end or second last position. Also, logic is flawed: it checks for pattern "X-Y" by looking ahead, but skips handling standalone '-' or cases where '-' appears at start.]
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                expand(A[i], A[i + 2]); // @@ [The expand function prints from p to q inclusive, but according to problem, a-c should become abc (excluding the starting character since it was already printed). However, in this code, the previous character hasn't been printed yet, so including it causes duplication or incorrect output. But more critically, the main loop never prints A[i] before expanding, so for "a-c", it expands from 'a' to 'c' as "abc", which is correct only if 'a' wasn't printed before — however, the logic of when to print what is inconsistent.]
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