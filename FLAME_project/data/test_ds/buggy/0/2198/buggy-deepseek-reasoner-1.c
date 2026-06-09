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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ [Multiple errors: 1) Invalid range checks: conditions like (str[i-1] >= 'a' && str[i+1] <= 'z') do not ensure both characters are lowercase letters; they also allow cross-type expansions. 2) The condition (str[i-1] < str[i+1]) is evaluated before checking i>0, causing out-of-bounds access when i=0. 3) The condition (i-1)!=0 is incorrect; it should be i>0. This causes the first expansion (at i=1) to be skipped, as i-1=0 fails the condition.]
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