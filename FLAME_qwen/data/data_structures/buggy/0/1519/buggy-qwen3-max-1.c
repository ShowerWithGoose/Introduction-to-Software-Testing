#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char s[10000],z[10000];
    int main()
    {
        int i,t=0;
        char j; // @@ [Using 'char' for loop variable 'j' can cause overflow or undefined behavior when incrementing beyond 127 (for signed char) or 255 (for unsigned char), especially when expanding ranges like '0'-'9' or letters. Should use 'int' instead.]
        gets(s); // @@ [The function 'gets' is unsafe and deprecated; it can cause buffer overflow. Moreover, some compilers may not support it, leading to compilation errors or warnings that might be treated as errors. Use 'fgets' instead.]
        for (i = 0; s[i] != '\0'; i++)
        {
            if (i >= 1&&i<=strlen(s)-2)
            {
                if (s[i] == '-')
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Loop variable 'j' is of type 'char'; when s[i-1] is near the upper limit of char (e.g., 'z'), incrementing may overflow, causing infinite loop or incorrect behavior.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same issue: 'j' is char, which is insufficient for safe loop control in character ranges.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Again, 'j' as char is problematic; e.g., if s[i-1] is '8', j becomes '9', then increments to ':' which is > '9', but if it were higher, overflow could occur. Still, using char for arithmetic is error-prone.]
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