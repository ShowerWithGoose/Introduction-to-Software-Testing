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
            for (p = str[i]; p < str[i + 2]; p++) // @@ [Compilation error: 'p' is declared as a char pointer, but 'str[i]' is a char. Assigning a char to a pointer without a cast causes a type mismatch error. Additionally, comparing a pointer with a char in the loop condition is invalid.]
            {
                printf("%c", p); // @@ [Compilation error/warning: 'p' is a pointer, but the '%c' format specifier expects a character value. It should print '*p' or 'p' should be declared as a char type.]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}