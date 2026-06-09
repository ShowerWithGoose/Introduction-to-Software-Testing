#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char s[1000] = { '\0' };

int pd1(int i)
{
    if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z')
        if (s[i + 1] - s[i - 1] > 1) // @@ The condition should be > 0 to correctly expand adjacent characters (e.g., a-b to ab), as the problem requires expansion when the right character is strictly greater than the left.
            return 1;
    return 0;
}
int pd2(int i)
{
    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
        if (s[i + 1] - s[i - 1] > 1) // @@ The condition should be > 0 to correctly expand adjacent characters (e.g., a-b to ab), as the problem requires expansion when the right character is strictly greater than the left.
            return 1;
    return 0;
}
int pd3(int i)
{
    if (s[i - 1] >= '0' && s[i - 1] <= '1' && s[i + 1] >= '0' && s[i + 1] <= '1') // @@ The upper bound for the digit range is incorrectly set to '1'; it should be '9' to cover the full [0-9] range.
        if (s[i + 1] - s[i - 1] > 1) // @@ The condition should be > 0 to correctly expand adjacent characters (e.g., 1-2 to 12), as the problem requires expansion when the right character is strictly greater than the left.
            return 1;
    return 0;
}
int main()
{
    
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '-')
        {
            if (pd1(i) + pd2(i) + pd3(i))
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            else
                printf("-");
        }
        else
        printf("%c", s[i]);
    }

    return 0;
}