#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ The loop condition should be i < len. Using i <= len causes the loop to process the null terminator '\0' at index len, which results in printing an extra empty character or garbage at the end of the output. Additionally, accessing line[i+1] when i is len-1 (the last valid character) would access out of bounds if not handled, but the primary issue here causing the WA vs Expected difference (extra null/garbage) is the inclusion of the null terminator in the print loop. More critically, the logic inside fails to check the requirements: "Only process characters within ranges... same type... char after > char before". The current code expands ANY '-' regardless of validity.
    {
        if (line[i] == '-') // @@ This block lacks the validation checks required by the problem statement. It should verify that line[i-1] and line[i+1] are valid, of the same type (both lowercase, both uppercase, or both digits), and that line[i-1] < line[i+1]. Without these checks, invalid expansions like 'a-R' or '0-b' would be incorrectly expanded, and valid non-expansion cases are not handled correctly.
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ This expansion loop runs without verifying if expansion is allowed. If the characters are not of the same type or the start is not less than the end, this loop might run incorrectly or produce wrong output. Also, if line[i-1] >= line[i+1], this loop won't execute, which is correct for that specific sub-case, but the surrounding logic is missing the "else print original" behavior for invalid '-' cases.
            {
                printf("%c", k);
            }
        }
        else // @@ This else branch prints the current character. However, if line[i] is a '-', and it's an invalid expansion case, the code currently does nothing inside the if block (if the loop doesn't run) and doesn't print the '-'. The '-' itself is skipped. The logic needs to explicitly print the '-' if expansion conditions are not met.
            printf("%c", line[i]);
    }
    return 0;
}