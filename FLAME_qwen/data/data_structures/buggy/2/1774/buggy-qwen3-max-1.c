#include <stdio.h>
#include<stdio.h> // @@ [Duplicate include of stdio.h is unnecessary but not a compilation error; however, the real issue lies elsewhere]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF) // @@ [This loop condition is flawed: scanf returns the number of successfully read items, but the input ends with '=', which is not an integer. When '=' is encountered, scanf fails to read an integer and returns 0 (not EOF), causing undefined behavior or infinite loop. Also, the program never reads the '=' into s[].]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; comparing uninitialized char to '\0' is unreliable. Also, this inner loop tries to skip spaces but uses incorrect logic—it should read characters until a non-space operator is found, but it doesn't handle the '=' properly.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time, but if the input has no space before '=', it may read '=' here, yet the outer loop continues trying to read another integer, which fails.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; also, s[1] may be uninitialized or contain unexpected value due to earlier logic errors.]
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
                s[j - 1] = s[j]; // @@ [Array shifting logic is incorrect: after processing operator at i, it shifts a[] and s[], but s[j-1] = s[j] overwrites previous operator incorrectly. Also, h is not decremented, so loop bounds become invalid.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [Loop condition uses s[i-1] but s[0] was never set; also, the '=' may not be stored in s[] at all due to earlier input logic failure, leading to infinite loop or accessing uninitialized memory.]
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