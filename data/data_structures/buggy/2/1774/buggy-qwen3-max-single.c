#include <stdio.h>
#include<stdio.h> // @@ [Duplicate inclusion of stdio.h is unnecessary but not a compilation error; however, the real issue lies elsewhere]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF) // @@ [This loop condition is flawed: scanf returns the number of successfully read items, but when '=' is encountered, reading an integer will fail, yet the loop may not terminate correctly because the next character (non-digit) remains in the buffer. Also, the program never actually reads the '=' into s[], leading to undefined behavior in later loops.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [s[i] is uninitialized on first access; comparing uninitialized char to '\0' or ' ' is undefined behavior. Also, this inner loop tries to skip spaces but uses incorrect logic—it should read characters until a non-space operator or '=' is found, but it doesn't handle input properly.]
        {
            scanf("%c", &s[i]); // @@ [This reads one char at a time, but if the input has no space after a number, it may read the operator immediately. However, the outer loop already assumes a number was read, so this might work partially, but the logic is fragile and leads to misalignment between a[] and s[].]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Debug print left in code; more critically, s[1] may be uninitialized or contain garbage if input parsing failed, but this isn't the main compilation issue. However, note: the actual error reported is "gcc: not found", which is a system/environment error, not a code error—but per problem context, we are to find logical/semantic errors causing wrong behavior, assuming compilation succeeds. Since the prompt says "Compilation Error" but the output is "/bin/sh: 1: gcc: not found", that suggests the environment lacks gcc—but the instruction says to treat it as if the code has bugs causing failure on test cases. So we focus on runtime/logic bugs that would cause incorrect output or crash.]
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
                s[j - 1] = s[j]; // @@ [This shifts s[] left by one starting from j-1 = i, but s[h-1] becomes s[h], which is uninitialized. Also, the array bounds are violated when j = h-1: a[h-1] = a[h] (out of bounds), and s[h-2] = s[h-1]. This causes undefined behavior and corrupts data.]
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ [This loop condition checks s[i-1] != '=', but '=' was never stored in s[] due to flawed input reading. The input ends with '=', but the program reads numbers until scanf fails, and the '=' remains unread or is read into s[i] only if the inner while loop picks it up—but the inner loop condition skips only spaces and nulls, so '=' would be stored. However, the first loop exits when scanf("%d") fails, meaning the '=' is still in stdin and never read into s[]. Thus, s[i-1] never equals '=', causing infinite loop or out-of-bounds access.]
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