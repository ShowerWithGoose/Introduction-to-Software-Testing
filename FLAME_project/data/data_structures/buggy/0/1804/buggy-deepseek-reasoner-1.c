#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b) // @@ [Logical error: function does not handle uppercase letters A-Z, missing condition for uppercase]
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Logical error: 'b >= 'z'' should be 'b <= 'z''; this condition is wrong and limits expansion to only when b is exactly 'z']
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
    gets_s(s); // @@ [Compilation error: 'gets_s' is not a standard C function; leads to implicit declaration and linker error. Should use scanf or fgets instead.]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ [Logical error: No boundary check; when i=0, s[i-1] accesses out-of-bounds memory. The reference program checks 'i>=1' before accessing s[i-1].]
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Logical error: This redeclares 'i' as a char, shadowing the outer loop variable. Then 's[i+1]' uses the char i as an index, which is invalid and leads to undefined behavior. The outer i is hidden, so subsequent statements lose the original index.]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Logical error: (1) The inner loop uses char 'i' as both loop variable and index into s, causing invalid array access. (2) The loop prints from a to b inclusive, but the spec requires printing only characters between a and b (exclusive of endpoints). The reference program prints a+1 to b-1.]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}