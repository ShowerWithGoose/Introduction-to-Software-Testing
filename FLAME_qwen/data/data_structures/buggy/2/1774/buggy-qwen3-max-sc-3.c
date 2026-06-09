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
    while (scanf("%d", &a[i]) != EOF) // @@ [The loop condition is incorrect: it reads integers until EOF, but the input ends with '=', not EOF. This causes infinite loop or undefined behavior when '=' is encountered.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; comparing uninitialized char to '\0' or ' ' leads to undefined behavior. Also, this inner loop doesn't properly handle reading the operator after the number.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time without skipping leading spaces correctly, and may read the newline or other unexpected characters. It also doesn't stop at '=' properly.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; also, s[1] may not be valid if input parsing failed. More critically, program logic never checks for '=' to terminate input.]
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
                s[j - 1] = s[j]; // @@ [Array shifting is incorrect: s[j-1] = s[j] overwrites earlier operators and breaks expression structure. Also, h is not decremented, leading to out-of-bounds access.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition uses s[i-1] but s was never guaranteed to contain '='; also, if '=' was never stored in s, this loops indefinitely or accesses invalid memory.]
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
    //printf("%d\n",sum);
    return 0;



}