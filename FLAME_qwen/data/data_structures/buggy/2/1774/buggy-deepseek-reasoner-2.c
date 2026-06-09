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
    while (scanf("%d", &a[i]) != EOF) // @@ [Error: does not stop at '='; may cause infinite loop if non-integer input like '=' is encountered]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [Error: s[i] is uninitialized, leading to undefined behavior]
        {
            scanf("%c", &s[i]); // @@ [Error: does not skip whitespace correctly; the enclosing while condition is flawed]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Error: s[1] may be uninitialized, debug print is not part of required output]
    int h = i;
    for (i = 1; i < h; i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*')
                a[i] *= a[i + 1]; // @@ [Error: a[i+1] may be out of bounds; algorithm incorrectly modifies array in place without proper handling]
            else
                a[i] /= a[i + 1]; // @@ [Error: same as above; also integer division not considered correctly with shifting]
            for (int j = i+1; j < h; j++)
            {
                a[j] = a[j + 1]; // @@ [Error: when j = h-1, a[j+1] is out of bounds; array shift logic is flawed]
                s[j - 1] = s[j];
            }
            i--;
        }
    }
    int sum=a[1]; // @@ [Error: a[1] may not hold the first number correctly due to index starting at 1 and shifting operations]
    for(i=1; s[i-1]!='='; i++) // @@ [Error: condition may never be true because '=' is not stored in s; loop will access out-of-bounds memory]
    {
        if(s[i]=='+')
        {
            sum+=a[i+1]; // @@ [Error: a[i+1] may be out of bounds]
        }
        if(s[i]=='-')
        {
            sum-=a[i+1]; // @@ [Error: same as above]
        }
    }
    //printf("%d\n",sum); // @@ [Error: required output is commented out, so program produces no result]
    return 0;
}