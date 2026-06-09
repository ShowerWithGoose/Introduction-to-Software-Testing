#include <stdio.h>
#include<stdio.h> // @@ [Duplicate include of stdio.h; harmless but unnecessary]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF) // @@ [This loop condition is flawed: scanf returns number of successfully read items, not EOF on '='. Also, it doesn't stop at '=' as required.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; reading uninitialized memory leads to undefined behavior. Also, this inner loop may never terminate if input doesn't contain non-space characters.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time but doesn't handle the '=' properly to break outer loop. Also, no check for EOF or input failure.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; also accesses s[1] which may be uninitialized or not set correctly due to earlier logic errors.]
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
                s[j - 1] = s[j]; // @@ [Array shifting logic is incorrect: shifts s[j] to s[j-1], but then next iteration may access out-of-bound or corrupted data. Also, h is not decremented, so loop runs too long.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition uses s[i-1] but i starts at 1 → checks s[0], which was never set. Also, loop may run beyond valid data since h is not used as bound.]
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
    return 0; // @@ [Program does not output the result; expected to print the integer result, but printf is commented out.]


}