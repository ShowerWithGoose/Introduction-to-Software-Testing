#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char s[10000],z[10000];
    int main()
    {
        int i,t=0;
        char j;
        gets(s);
        for (i = 0; s[i] != '\0'; i++)
        {
            if (i >= 1&&i<=strlen(s)-2)
            {
                if (s[i] == '-')
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++)
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++)
                        {
                            z[t++] = j;
                        }
                    }
                    else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
                    {
                        for (j = s[i - 1]+1; j < s[i + 1]; j++)
                        {
                            z[t++] = j;
                        }
                    }
                } // @@ Missing else clause: if none of the expansion conditions are met, the dash should be appended unchanged. Without this else, the dash is silently skipped for cases like "b-a" or "a-A".
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