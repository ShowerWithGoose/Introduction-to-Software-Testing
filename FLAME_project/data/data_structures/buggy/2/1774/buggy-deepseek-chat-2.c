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
        while (s[i] == '\0' || s[i] == ' ') // @@ The condition is incorrect; s[i] is uninitialized and may not be '\0', causing the loop to skip reading the operator. Should read the operator character directly after the number.
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]); // @@ This line prints the first operator, which is not part of the expected output and causes the buggy output "+".
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
    for(i=1; s[i-1]!='='; i++) // @@ The loop condition uses s[i-1]!='=', but s[0] is never set (starts from index 1), so this may cause undefined behavior or incorrect termination. Should check s[i] != '='.
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