#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [The condition `b >= 'z'` is incorrect; it should be `b <= 'z'`. This typo causes the first condition to never be true for valid lowercase ranges.]
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
    gets_s(s); // @@ [`gets_s` is not standard in all C environments and may cause compilation errors; the reference uses `gets`, though both are unsafe. More critically, `gets_s` requires a second argument (buffer size) in C11, so this call is invalid.]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable `i` is redeclared as `char` inside the loop, shadowing the outer loop variable `i` (which is `int`). This breaks the loop control and causes undefined behavior.]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Due to the redeclaration of `i` as `char`, this loop uses the wrong type and also modifies the loop counter incorrectly, leading to logic errors and potential infinite loops. Additionally, it prints from `s[i-1]` to `s[i+1]` inclusive, but the problem requires expansion *between* them (exclusive of endpoints).]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}