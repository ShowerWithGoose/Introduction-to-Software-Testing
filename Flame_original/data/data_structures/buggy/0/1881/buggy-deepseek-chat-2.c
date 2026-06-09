#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10];
int main()
{
    int i;
    char* p;
    gets(str);
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++)
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26)
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [Error: p is a char pointer, but str[i] is a char. This comparison and increment are invalid. Should use a char variable, e.g., char c, and loop c from str[i]+1 to str[i+2]-1.]
            {
                printf("%c", p); // @@ [Error: p is a pointer, not a character. Should print the character value, e.g., *p or the loop variable.]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}