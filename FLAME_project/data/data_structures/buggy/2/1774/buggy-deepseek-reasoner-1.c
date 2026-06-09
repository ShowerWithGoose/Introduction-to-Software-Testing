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
    while (scanf("%d", &a[i]) != EOF)  // @@ [Error: The loop condition should check for '=' to stop input, not EOF. This will cause infinite loop when encountering '=' because scanf fails but does not return EOF.]
    {
        while (s[i] == '\0' || s[i] == ' ')
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]);  // @@ [Error: This line prints the first operator (e.g., '+') as output, but the program should output the calculated result. This is a stray debug print.]
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
    for(i=1; s[i-1]!='='; i++)
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
    //printf("%d\n",sum);  // @@ [Error: The final printf is commented out, so the calculated result is never output. It should be uncommented to print the result.]
    return 0;
}