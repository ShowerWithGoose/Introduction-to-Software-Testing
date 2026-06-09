#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char s[1000] = { '\0' };

int pd1(int i)
{
    if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z')
        if (s[i + 1] - s[i - 1] > 1)
            return 1;
    return 0;
}
int pd2(int i)
{
    if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
        if (s[i + 1] - s[i - 1] > 1)
            return 1;
    return 0;
}
int pd3(int i)
{
    if (s[i - 1] >= '0' && s[i - 1] <= '1' && s[i + 1] >= '0' && s[i + 1] <= '1') // @@ Error: The range check is incorrect. It should be s[i-1] >= '0' && s[i-1] <= '9' and s[i+1] >= '0' && s[i+1] <= '9', not limited to '0' to '1'. This causes the function to return 0 for digits like '8', so no expansion occurs.
        if (s[i + 1] - s[i - 1] > 1)
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