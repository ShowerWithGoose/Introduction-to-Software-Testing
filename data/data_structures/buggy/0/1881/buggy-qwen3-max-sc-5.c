#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [buffer too small; input may exceed 10 characters causing overflow]
int main()
{
    int i;
    char* p; // @@ [using char* as loop counter for characters is incorrect; should use char or int]
    gets(str); // @@ [gets() is unsafe and deprecated; also, no check for input length vs buffer size]
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++)
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [logic flawed: only checks uppercase range with 'A', ignores digits and lowercase; also accesses str[i+2] without ensuring i+2 < len]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [invalid pointer arithmetic: assigning char value to char* and comparing/iterating incorrectly]
            {
                printf("%c", p); // @@ [printing pointer value as char is undefined behavior]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}