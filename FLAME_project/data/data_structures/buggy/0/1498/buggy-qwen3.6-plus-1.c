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
    if ((p >= 'a' && p <= 'z' && q >= 'a' && q <= 'z') || (p >= 'A' && p <= 'Z' && q >= 'A' && q <= 'Z') || (p >= '0' && p <= '9' && q >= '0' && q <= '9')) // @@ [The original logic incorrectly checked if p was in range and q was in range independently without ensuring they were the SAME type. For example, 'a' (>= 'a') and 'Z' (<= 'Z') would return true in the original code because it used OR logic across different ranges improperly or mixed bounds. The correct logic requires both characters to be in the same specific range: both lowercase, both uppercase, or both digits.]
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
                if (A[i] < A[i+2]) // @@ [The problem states expansion only happens if the character after '-' is greater than the one before. The original code missed this check, causing invalid expansions like 'c-a' or printing ranges when start > end.]
                    expand(A[i], A[i + 2]);
                else // @@ [If expansion condition (start < end) is not met, the original character and the dash should be printed as is, but the original code skipped printing anything for the current char if k==1 but start >= end, leading to missing output.]
                {
                    printf("%c", A[i]);
                    printf("%c", A[i+1]);
                }
                i = i + 2;
            }
            if(k==0)
            {
                printf("%c",A[i]); // @@ [When types don't match, we print the current char. The next iteration will handle the '-' and the following char correctly if structured right, but typically we just print current and move on. However, looking at the loop structure, if k==0, we print A[i]. Then i increments. Next loop sees A[i] which is '-', checks A[i+1]. This seems okay for single chars, but let's trace 'a-R'. i=0 ('a'), next is '-'. toexpand('a', 'R') is 0. Prints 'a'. i becomes 1. Loop ends iteration, i++ makes i=2. Next iter: A[2] is 'R'. A[3] is not '-'. Prints 'R'. This part is actually logically acceptable for non-expanding cases IF the expansion case handles the skip correctly. However, the main error is the missing start < end check and the type checking logic.]
            }
        }
        else
            printf("%c", A[i]);
        i++;
    }
    return 0;
}