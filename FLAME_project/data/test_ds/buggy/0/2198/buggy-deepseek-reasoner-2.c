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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ [Error 1: condition (i-1)!=0 prevents expansion when left character is at index 0 (e.g., "a-u" where '-' at i=1, i-1=0, so condition false). Should be i>0. Error 2: range checks are incorrect; they should ensure both characters are within the same type range, e.g., (str[i-1]>='a' && str[i-1]<='z' && str[i+1]>='a' && str[i+1]<='z'), etc.]
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