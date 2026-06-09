#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [Buffer too small; may cause overflow for typical input]
int main()
{
    int i;
    char* p;
    gets(str);
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++)
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [Incorrect condition: does not properly check same type (lowercase/uppercase/digit) and may access out-of-bounds; also logic for digit expansion is wrong]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [Error: assigning char to pointer (p = str[i]) is invalid; p should be a char variable, not pointer]
            {
                printf("%c", p); // @@ [Error: printing pointer as char; should print the loop variable if corrected]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}