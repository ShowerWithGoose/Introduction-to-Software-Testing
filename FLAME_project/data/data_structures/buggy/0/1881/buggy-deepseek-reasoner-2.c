#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ Buffer size too small; long input may cause buffer overflow.
int main()
{
    int i;
    char* p;
    gets(str);
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++)
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ Condition incorrectly excludes lowercase expansions (e.g., 'u' - 'A' > 26) and does not ensure both characters are of the same type.
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ Wrong: assigns integer (ASCII value) to pointer; should use a char variable and loop up to inclusive end.
            {
                printf("%c", p); // @@ Wrong: prints pointer instead of the character; should be a char variable.
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}