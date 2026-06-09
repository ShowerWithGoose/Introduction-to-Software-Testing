#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF)
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ The condition `s[i] == '\0'` is incorrect for checking if the character has been read or is a space. `s` is uninitialized or contains garbage/zero initially, but the logic here fails to correctly consume the operator following the number. It should simply read the next non-space character which is the operator. The loop condition prevents reading the operator correctly if `s[i]` happens to be 0 initially, or it gets stuck. More critically, the subsequent logic relies on `s[i]` holding the operator.
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]); // @@ This line prints a character (likely the first operator or garbage) instead of calculating and printing the result. It also interferes with the expected output format.
    int h = i;
    for (i = 1; i < h; i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*')
                a[i] *= a[i + 1];
            else
                a[i] /= a[i + 1];
            for (int j = i+1; j < h; j++)
            {
                a[j] = a[j + 1];
                s[j - 1] = s[j];
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ The termination condition `s[i-1]!='='` is flawed. The array `s` stores operators. The `=` sign is likely stored in `s` at some index, but accessing `s[i-1]` when `i=1` accesses `s[0]` which is uninitialized. Also, the loop bounds and logic for processing remaining `+` and `-` operators are coupled with incorrect indexing after the compaction step.
    {
        if(s[i]=='+')
        {
            sum+=a[i+1];
        }
        if(s[i]=='-')
        {
            sum-=a[i+1];
        }
    }
    //printf("%d\n",sum); // @@ The final result calculation is commented out, so nothing is printed.
    return 0;



}