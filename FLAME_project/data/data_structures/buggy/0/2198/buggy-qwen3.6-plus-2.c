#include <stdio.h>
#include <string.h>
#define len 200
int main()
{
    char c;
    int i;
    char str[len];
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ [The condition checks if start and end chars are in the same broad category range (e.g., both <= 'z'), but fails to ensure they are of the *same specific type* (both lowercase, both uppercase, or both digits). For example, 'a' (lowercase) and 'B' (uppercase) might pass some checks incorrectly or fail others, but specifically 'a' and 'u' are both lowercase. The logic `(str[i - 1] >= 'a' && str[i + 1] <= 'z')` is flawed because it doesn't check if `str[i-1]` is also `<= 'z'` (though implied by >= 'a') and crucially doesn't check if `str[i+1]` is `>= 'a'`. Wait, `str[i+1] <= 'z'` allows uppercase if we aren't careful? No, 'A' is not <= 'z' in ASCII? Yes it is. 'A' (65) <= 'z' (122). So `str[i-1] >= 'a'` ensures start is lowercase. But `str[i+1] <= 'z'` allows end to be uppercase or lowercase. This mixes types. It should be `(str[i-1] >= 'a' && str[i-1] <= 'z' && str[i+1] >= 'a' && str[i+1] <= 'z')` etc.]
        {
            for (int j = 1; j < (str[i + 1] - str[i - 1]); j++)
            {
                printf("%c", str[i - 1] + j);
            }
        }
        else
            printf("%c", str[i]);
    }
    return 0;
}