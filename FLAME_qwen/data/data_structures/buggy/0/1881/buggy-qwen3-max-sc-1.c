#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [buffer size too small; input may exceed 10 characters causing overflow]
int main()
{
    int i;
    char* p; // @@ [using char* as loop counter for characters is incorrect; should use char or int]
    gets(str); // @@ [gets() is unsafe and deprecated; also, no bounds checking with small buffer]
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++)
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [logic flawed: only checks uppercase range via 'A', ignores digits and lowercase; condition str[i+2]-'A'<=26 is incorrect for general cases]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [assigning char value to char* pointer causes undefined behavior; p should not be a pointer here]
            {
                printf("%c", p); // @@ [printing pointer p as char is invalid; should print *p if p were valid, but logic is fundamentally wrong]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}