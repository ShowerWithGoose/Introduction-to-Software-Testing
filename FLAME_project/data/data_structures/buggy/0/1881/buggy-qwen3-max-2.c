#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [Buffer size is too small; input like "a-uB-F" requires more than 10 characters after expansion]
int main()
{
    int i;
    char* p;
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow, especially with small str size]
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++) // @@ [Loop condition recalculates strlen each time; also, accessing str[i+2] can go out of bounds]
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [Incorrect condition: mixes uppercase/lowercase/digits; doesn't check character types match; 'A' offset invalid for lowercase/digits]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [p is char*, but assigned char value str[i]; should be integer loop or use char index]
            {
                printf("%c", p); // @@ [Printing pointer value as char is undefined behavior; should print generated chars from range]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}