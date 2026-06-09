#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [Array size too small; input may exceed 9 characters, causing buffer overflow]
int main()
{
    int i;
    char* p;
    gets(str);
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++) // @@ [Accesses str[i+1] and str[i+2] which can be out of bounds when i reaches end of string]
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [Condition does not correctly check same type and left<right; e.g., fails for lowercase letters]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [Assigns char to pointer incorrectly; comparing pointer to char is wrong; should iterate over character values]
            {
                printf("%c", p); // @@ [Prints pointer address as character instead of *p; undefined behavior]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}