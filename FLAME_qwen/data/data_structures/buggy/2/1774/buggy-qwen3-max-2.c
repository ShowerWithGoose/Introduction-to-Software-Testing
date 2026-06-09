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
    while (scanf("%d", &a[i]) != EOF) // @@ [This loop condition is flawed: scanf returns number of successfully read items, not EOF on '='. Also, it doesn't stop at '=', leading to infinite loop or undefined behavior.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; reading uninitialized memory leads to undefined behavior. Also, logic for skipping spaces is incorrect.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time but doesn't handle multi-space or operator correctly; also may read '=' into s[i] without breaking outer loop properly.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; also accesses s[1] which may be uninitialized or invalid if input is malformed.]
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
                s[j - 1] = s[j]; // @@ [Array shift logic is off-by-one and corrupts operator/operand alignment; also accesses a[h] which is out-of-bounds.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition uses s[i-1] but s[0] was never set; also, '=' may not be in s at expected position due to earlier parsing errors.]
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