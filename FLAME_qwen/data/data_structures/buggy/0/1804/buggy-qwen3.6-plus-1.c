#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Error: 'b >= 'z'' is incorrect; it should be 'b <= 'z'' to correctly check if b is within the lowercase range.
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) // @@ Error: This condition incorrectly checks for lowercase letters again instead of uppercase '[A-Z]'. It should check 'a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z''.
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s);
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Error: Declaring 'char i' shadows the outer loop variable 'int i', disrupting the outer loop's index tracking and causing logical errors.
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Error: The loop range includes boundary characters, causing duplicate output. It should iterate from 's[i-1] + 1' to 's[i+1] - 1'. Also uses the shadowed variable.
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}