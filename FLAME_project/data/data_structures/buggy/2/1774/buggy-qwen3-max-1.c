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
        while (s[i] == '\0' || s[i] == ' ')
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]); // @@ [This prints the first operator instead of the final result; also, it causes premature output and does not match expected behavior. The problem requires only the integer result to be printed.]
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
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition is incorrect: it checks s[i-1] but should check s[i] or use proper bounds. Also, after processing operators, the '=' may not be at expected index due to shifting during array compaction. This can cause out-of-bound access or early termination.]
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
    //printf("%d\n",sum); // @@ [The correct result 'sum' is computed but never printed because this line is commented out. Instead, an erroneous printf("%c",s[1]) was used earlier.]
    return 0;



}