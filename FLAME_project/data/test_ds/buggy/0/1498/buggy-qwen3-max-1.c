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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [The condition is incorrect: it checks if p is >= 'a' and q <= 'z', which allows mixed cases like p='z' and q='a'; it should ensure both p and q are in the same category and p < q]
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
        if (A[i+1] == '-') // @@ [This accesses A[i+1] and later A[i+2] without checking bounds; also logic is flawed because it only triggers when the next character is '-', but should trigger when current character is part of a pattern like X-Y]
        {
            k = toexpand(A[i], A[i + 2]); // @@ [Accesses A[i+2] without ensuring i+2 is within string bounds; also toexpand logic is wrong as noted above]
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ [Skips two characters after expansion, but loop increments i again, causing potential skip of next character; also doesn't handle multiple consecutive expansions correctly]
            }
            if(k==0)
                printf("%c",A[i]); // @@ [Only prints A[i] if expansion fails, but doesn't print the '-' or A[i+2], leading to missing characters in output]
        }
        else
            printf("%c", A[i]);
        i++;
    }
    return 0;
}