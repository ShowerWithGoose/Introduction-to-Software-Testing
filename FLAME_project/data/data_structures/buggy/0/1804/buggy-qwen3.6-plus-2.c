#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Logical error: condition 'b >= 'z'' should be 'b <= 'z''. Also, this block is redundant as the next else-if handles the correct lowercase range.
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
    gets_s(s); // @@ Compilation Error: 'gets_s' is not standard in many GCC environments and causes linker errors. Should use 'scanf("%s", s)' or 'fgets'.
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Logical Error: Variable shadowing. Declaring 'char i' here shadows the loop counter 'int i', causing undefined behavior or infinite loops when 'i' is used in the for-loop initialization and condition below.
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Logical Error: Uses the shadowed variable 'i'. Also, logic prints the start character again if not handled carefully, but the primary issue is the variable shadowing breaking the outer loop.
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}