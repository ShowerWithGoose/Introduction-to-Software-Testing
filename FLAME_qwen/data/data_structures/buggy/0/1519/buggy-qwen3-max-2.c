#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char s[10000],z[10000];
    int main()
    {
        int i,t=0;
        char j; // @@ [Using 'char' for loop counter 'j' can cause overflow or undefined behavior when incrementing beyond 127 (for signed char) or 255 (for unsigned char), especially when expanding ranges like 'a' to 'z'. Should use 'int' instead.]
        gets(s); // @@ [The function 'gets' is unsafe and deprecated; it can cause buffer overflow. It was removed in C11. Use 'fgets' instead. Also, this may cause compilation error if compiler enforces secure functions or strict standards.]
        for (i = 0; s[i] != '\0'; i++)
        {
            if (i >= 1&&i<=strlen(s)-2)
            {
                if (s[i] == '-')
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Loop variable 'j' is of type 'char'; when used in arithmetic like 'j++', it may overflow or behave unexpectedly, especially near CHAR_MAX. This leads to incorrect expansion or infinite loops.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same issue: 'j' is char, not suitable for loop counter over character ranges.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Again, 'j' as char causes potential overflow or incorrect iteration.]
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