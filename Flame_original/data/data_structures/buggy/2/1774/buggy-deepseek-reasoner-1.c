#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1; // @@ Error: Starting index at 1 causes misalignment with 0‑based array handling; the later logic assumes indices start at 1 but shifts and comparisons become incorrect.
    while (scanf("%d", &a[i]) != EOF) // @@ Error: This loop attempts to read integers first, but the expression contains operators between numbers; also EOF will never be reached because input ends with '=', not EOF.
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ Error: s[i] is uninitialized; condition may not enter loop, and the logic to skip whitespace is flawed. Also reading a character after each integer assumes operator follows immediately, but spaces may exist.
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]); // @@ Error: s[1] is uninitialized if input reading failed; prints garbage.
    int h = i;
    for (i = 1; i < h; i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*')
                a[i] *= a[i + 1];
            else
                a[i] /= a[i + 1];
            for (int j = i+1; j < h; j++) // @@ Error: When j = h-1, a[j+1] and s[j] access out‑of‑bounds (h is the last index after increment). Also shifting s[j-1] = s[j] incorrectly overwrites operators.
            {
                a[j] = a[j + 1];
                s[j - 1] = s[j];
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ Error: s[0] is uninitialized, so the condition may never be true or cause undefined behavior. Also a[i+1] may index beyond input length.
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
    //printf("%d\n",sum); // @@ Error: The result is never printed; the only output is the commented line.
    return 0;



}