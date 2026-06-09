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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ [The condition checks if the start and end characters are within a broad range (e.g., start >= 'a' and end <= 'z'), but fails to ensure they are of the *same* specific type. For example, 'a' (lowercase) and 'Z' (uppercase) might pass individual bounds checks incorrectly or mix types. More critically, it doesn't enforce that both are lowercase, both uppercase, or both digits exclusively. It should check: (both lowercase) OR (both uppercase) OR (both digits). The current logic `(str[i - 1] >= 'a' && str[i + 1] <= 'z')` allows mixing if not carefully bounded, but the main issue is likely that it doesn't strictly enforce same-type category properly or the boundary checks are insufficient. However, the primary logical error here is that the condition `str[i - 1] >= 'a' && str[i + 1] <= 'z'` does not guarantee `str[i-1]` is lowercase if `str[i+1]` is lowercase, wait, actually if `str[i-1] >= 'a'` it is lowercase/digit/symbol? No, ASCII 'a' is 97. If `str[i-1]` is 'a' and `str[i+1]` is 'z', it passes. But if `str[i-1]` is 'a' and `str[i+1]` is 'B', `str[i+1] <= 'z'` is true, `str[i-1] >= 'a'` is true. This incorrectly allows expansion across types if not checked against upper bound of same type. It needs to ensure `str[i-1]` and `str[i+1]` are in the SAME category. E.g., for lowercase: `str[i-1]>='a' && str[i-1]<='z' && str[i+1]>='a' && str[i+1]<='z'`. The current code only checks lower bound for start and upper bound for end.]
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