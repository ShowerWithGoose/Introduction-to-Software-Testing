#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ array size too small for general inputs; may cause buffer overflow
int main()
{
    int i;
    char* p;
    gets(str);
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++) // @@ loop accesses str[i+1] and str[i+2] which may be out of bounds when i is near the end of the string
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ condition incorrectly uses 'A' for all character types, fails for lowercase and digit ranges; also does not check that both characters are in the same category
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ pointer arithmetic is used to iterate over alphabet; p++ moves to next memory address, not next character value
            {
                printf("%c", p); // @@ p is a pointer, should be *p to print the character value; printing address produces undefined behavior
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}