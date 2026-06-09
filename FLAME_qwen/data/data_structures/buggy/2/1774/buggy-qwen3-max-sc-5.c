#include <stdio.h>
#include<stdio.h> // @@ [duplicate include of stdio.h is unnecessary but not a compilation error; however, the real issue lies elsewhere]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF) // @@ [This loop condition is flawed: scanf returns the number of successfully read items, not EOF on '='. The input ends with '=', which is not an integer, so scanf fails and returns 0, not EOF, causing infinite loop or undefined behavior. Also, no check for '=' termination.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; reading uninitialized memory leads to undefined behavior. Also, this inner loop doesn't properly handle non-space, non-null characters like operators or '='.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time but doesn't skip leading spaces correctly before the operator; also, after reading '=', the outer loop still tries to read next integer, which fails.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; more importantly, logic assumes s[1] is valid, but indexing may be off due to earlier flaws.]
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
                s[j - 1] = s[j]; // @@ [Array shifting is incorrect: s[j-1] = s[j] shifts operator array left, but a[j] = a[j+1] shifts numbers left; however, h is not decremented, leading to out-of-bounds access and incorrect parsing. Also, s[h-1] may be unassigned.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition uses s[i-1] but i starts at 1, so checks s[0], which was never set (input starts storing from s[1]). Also, '=' may not be in s at expected position due to flawed input reading.]
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