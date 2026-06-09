#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic does not build output in s1 but prints directly, causing incorrect output order and duplication]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Condition checks only upper bound for s[i+1] and lower bound for s[i-1]; should verify both characters are digits using isdigit or full range check like (s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9')]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Same issue: only checks s[i-1] >= 'a' and s[i+1] <= 'z', but doesn't ensure s[i-1] <= 'z' and s[i+1] >= 'a'; e.g., 'Z'-'a' could pass incorrectly]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Same issue: incomplete range validation for uppercase letters]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else
            {
                printf("%c",s[i]); // @@ [This else is missing! The original code does not print '-' when expansion conditions fail, but it should output the '-' unchanged. However, note: in this buggy code, the 'else' clause for the outer 'if(s[i]=='-')' is actually the final 'else' below, so this is a structural logic error: when '-' is found but conditions fail, nothing is printed for '-', leading to omission. But wait — actually, in this code, if s[i]=='-' and none of the if/else-if blocks execute, then the '-' is never printed. That's a critical bug. However, looking closely: there is no 'else' after the last else-if inside the s[i]=='-' block. So if '-' is encountered and none of the type-matching conditions are met, the code does nothing — the '-' is skipped entirely. This causes "B-e" to become "Be" instead of "B-e".]
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1); // @@ [s1 is never assigned any value, so printing it appends garbage or empty string; also, the entire approach of printing character-by-character interleaved with expansion breaks the requirement to output a single expanded string — especially when '-' should be preserved. The correct method is to build the result in a buffer (like t[] in reference) and print once at the end.]
    return 0;
}