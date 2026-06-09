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
    for (i = 0; i <= (strlen(str) - 1); i++) // @@ [Loop condition uses strlen repeatedly which is inefficient, but more critically, logic doesn't handle all cases correctly]
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [Condition incorrectly checks only uppercase range with 'A', fails for lowercase and digits; also assumes fixed max diff of 25 which is arbitrary]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [p is a char*, but assigned a char value (str[i]); this causes undefined behavior. Should use char variable, not pointer]
            {
                printf("%c", p); // @@ [Printing pointer value as char is incorrect; should print the character being iterated, not the address]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}