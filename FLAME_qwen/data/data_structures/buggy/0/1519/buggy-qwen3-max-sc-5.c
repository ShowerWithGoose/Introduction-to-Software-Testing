#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char s[10000],z[10000];
    int main()
    {
        int i,t=0;
        char j; // @@ [Using 'char' for loop variable 'j' can cause overflow or undefined behavior when incrementing beyond 127 (for signed char) or 255 (for unsigned char), especially when expanding ranges like 'a' to 'z'. Should use 'int' instead.]
        gets(s); // @@ [The function 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors or warnings in modern compilers. Use 'fgets' instead. Also, this likely causes the "gcc: not found" error indirectly if the environment blocks unsafe functions, but more directly it's a compilation/security issue.]
        for (i = 0; s[i] != '\0'; i++)
        {
            if (i >= 1&&i<=strlen(s)-2)
            {
                if (s[i] == '-')
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Loop variable 'j' is of type 'char'; when s[i-1] is near 'z', incrementing may overflow, leading to infinite loop or incorrect behavior.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same issue: 'char' loop variable may overflow during increment.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same issue: 'char' used as integer loop counter—unsafe for arithmetic loops.]
                        {
                            z[t++] = j;
                        }
                    }
                }
                else
                {
                    z[t++] = s[i];
                }
            }
            else
            {
                z[t++] = s[i];
            }
        }
        z[t] = '\0';
        puts(z);
        return 0;
    }