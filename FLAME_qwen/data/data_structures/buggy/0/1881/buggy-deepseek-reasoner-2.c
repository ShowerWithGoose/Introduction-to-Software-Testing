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
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ Logical error: condition does not properly restrict to same character type and range; also out-of-bounds access when i is near end.
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ Compilation error: assigning char to char* (incompatible types) and comparing pointer with integer.
            {
                printf("%c", p); // @@ Semantic error: p is a pointer, but %c expects a char; should be *p.
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}