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
    while (scanf("%d", &a[i]) != EOF) // @@ [The loop condition does not check for the '=' terminator, and scanf for integer will fail on '=', causing infinite loop or incorrect input handling]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized at first iteration; this condition may cause issues. Also, the logic for reading operators is flawed]
        {
            scanf("%c", &s[i]); // @@ [This reads a single character, but does not skip spaces properly; it may read newline or other characters]
        }
        i++;
    }
printf("%c",s[1]); // @@ [This debug print is unnecessary and may output garbage if s[1] is not properly set]
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
    for(i=1; s[i-1]!='='; i++) // @@ [The loop condition uses s[i-1] which may be out of bounds or not properly set; also the loop logic for addition/subtraction is incorrect]
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