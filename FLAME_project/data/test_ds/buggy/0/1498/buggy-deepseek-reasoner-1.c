#include<stdio.h>

void expand(char p,char q)
{
    int i = 0;
    int k=p;
    for (i = 0; i <=(q - p); i++) // @@ This loop prints the starting character p, which causes duplication when multiple expansions are adjacent (e.g., a-c-g). The reference program prints only from p+1 to q after printing p separately.
    {
        printf("%c", k);
        k++;
    }
}

int toexpand(char p, char q)
{
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ The condition is incorrect: it only checks that p is at least the lower bound and q is at most the upper bound, not that both are within the same range. It should check both p and q are in the same character category and also that p < q (the character after dash must be greater). For example, p='0', q='A' incorrectly returns 1 under the '0'-'9' case because '0'>= '0' and 'A'<='9'? Actually 'A' <= '9' is false, so this example fails, but other cases like p='z', q='a' would return 1 incorrectly.
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
        if (A[i+1] == '-') // @@ Error: Should check if the current character is '-' (A[i] == '-'), not the next one. This causes the program to never detect dashes at their own position; instead it looks ahead, so dashes are printed as normal characters when encountered later, and expansions are only triggered for the character before a dash, leading to missed expansions and extra printed dashes.
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ This line, combined with the i++ at the end of the loop, skips one index too many, causing the next dash (if any) to be processed incorrectly. After expansion, the index should be adjusted so that the next iteration processes the character after the expanded range exactly once.
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