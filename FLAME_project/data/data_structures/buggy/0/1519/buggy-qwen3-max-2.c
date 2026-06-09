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
                    else
                    {
                        z[t++] = s[i]; // @@ [When '-' is not expanded (e.g., mixed case like B-e), the '-' itself should be output, but this line only adds s[i] (which is '-') when inside valid index range. However, the logic skips adding '-' in some edge placements due to flawed control flow. More critically, the program fails to output the '-' character when expansion conditions are not met because it only appends s[i] in the 'else' of the inner 'if (s[i] == '-')', but misses appending '-' when expansion fails. Actually, in this code, if s[i]=='-' and none of the expansion conditions are satisfied, it falls through without appending anything. This is the core bug.]
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