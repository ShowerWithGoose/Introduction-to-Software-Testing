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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [The condition does not ensure both p and q are in the same character range (e.g., p could be a letter and q a digit). It should check p and q are both within the same type range and that p <= q.]
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
        if (A[i+1] == '-') // @@ [This checks the next character instead of the current one. When a hyphen is encountered, it should be processed using A[i-1] and A[i+1]. This logic fails for consecutive expansions (e.g., "c-g" after a previous expansion) because the hyphen itself is never examined as the current character.]
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ [After expansion, setting i = i + 2 combined with the later i++ causes the loop to skip the character after the hyphen (e.g., the 'g' in "c-g"), so subsequent hyphens are missed.]
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