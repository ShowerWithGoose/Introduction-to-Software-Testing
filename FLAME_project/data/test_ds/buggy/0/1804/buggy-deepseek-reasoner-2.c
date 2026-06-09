#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [incorrect condition: should be b <= 'z' instead of b >= 'z']
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ [gets_s is a non-standard function; use fgets instead to avoid compilation/linker error]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ [potential out-of-bounds access when i == 0 or i == n-1]
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [shadows outer loop variable 'i', causing incorrect loop control and possible undefined behavior]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [inner loop uses shadowed 'i', logic flawed; also prints boundary characters twice]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}