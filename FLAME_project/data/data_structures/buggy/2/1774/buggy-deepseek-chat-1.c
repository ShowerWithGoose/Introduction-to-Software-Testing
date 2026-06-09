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
        while (s[i] == '\0' || s[i] == ' ') // @@ The condition is incorrect; s[i] is uninitialized, so it may not be '\0' or ' ', causing the loop to skip reading the operator. Should read the operator after the number.
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]); // @@ This line prints the first operator, which is not part of the expected output. It should be removed or commented out.
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
    for(i=1; s[i-1]!='='; i++) // @@ The loop condition s[i-1]!='=' may cause out-of-bounds access or incorrect termination because s[i-1] might not be '=' at the right time. Also, the loop starts from i=1 but should start from i=1 to process operators correctly.
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