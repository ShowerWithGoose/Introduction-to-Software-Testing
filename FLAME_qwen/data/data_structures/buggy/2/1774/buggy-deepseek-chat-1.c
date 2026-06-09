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
    while (scanf("%d", &a[i]) != EOF) // @@ [Error: The loop condition does not check for the '=' terminator, causing it to read indefinitely or until EOF, but the input ends with '=' not EOF. Also, the input format has spaces and operators, so reading integers directly without handling operators will fail.]
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ [Error: s[i] is uninitialized (contains garbage) when first checked, so this condition may not work as intended. Also, the logic for reading operators is flawed; it should read the operator after each number, but the loop structure is incorrect.]
        {
            scanf("%c", &s[i]); // @@ [Error: This reads a character into s[i], but if the character is a space, it will be overwritten in the next iteration; however, the condition checks s[i] which may not be updated correctly.]
        }
        i++;
    }
printf("%c",s[1]); // @@ [Error: This prints a single character, likely for debugging, but it will output an unexpected character and is not part of the required output.]
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
    for(i=1; s[i-1]!='='; i++) // @@ [Error: The loop condition uses s[i-1] which may be out of bounds or incorrect because the array s[] may not contain '=' properly due to flawed input reading. Also, the loop starts from i=1 but the first operator is at s[1]? The indexing is inconsistent.]
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