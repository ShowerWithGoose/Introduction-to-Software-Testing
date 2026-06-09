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
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ Condition is incorrect: it does not ensure both characters are of the same type and within the same range (e.g., 'a' and '0' would pass). Should check both within [a-z], both within [A-Z], or both within [0-9].
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
        if (A[i+1] == '-') // @@ Flawed logic: checks if next character is '-', but after a previous expansion the index may skip the character that should be the start of the next expansion. This causes the second '-' in "c-g" to be missed. Should instead check A[i] == '-'.
        {
            k = toexpand(A[i], A[i + 2]);
            if (k == 1)
            {
                expand(A[i], A[i + 2]);
                i = i + 2; // @@ Incorrect increment: after expanding, i is set to the index of the end character, then the loop's i++ moves past it, losing that character as a potential start for the next expansion. Should use a different update to keep the end character for the next iteration.
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