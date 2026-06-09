#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char s[10000],z[10000];
    int main()
    {
        int i,t=0;
        char j; // @@ [Using 'char' for loop variable 'j' can cause overflow or undefined behavior when incrementing beyond CHAR_MAX, especially in expansions like 'z' to something higher. Should be 'int'.]
        gets(s); // @@ [The function 'gets' is unsafe and deprecated; it may cause buffer overflow. Moreover, some compilers (especially modern ones) do not support 'gets', leading to compilation errors. Use 'fgets' instead.]
        for (i = 0; s[i] != '\0'; i++)
        {
            if (i >= 1&&i<=strlen(s)-2)
            {
                if (s[i] == '-')
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Loop variable 'j' is of type 'char'; if s[i+1] is greater than CHAR_MAX (unlikely here but still risky), or during increment, it may overflow. Also, comparing signed/unsigned chars can lead to unexpected behavior.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same issue: 'j' should be 'int' to safely handle character arithmetic without overflow or sign issues.]
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++) // @@ [Same problem with 'char' loop variable.]
                        {
                            z[t++] = j;
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
            else
            {
                z[t++] = s[i];
            }
        }
        z[t] = '\0';
        puts(z);
        return 0;
    }