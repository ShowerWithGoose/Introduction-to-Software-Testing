#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10]; // @@ [Buffer size too small; input may exceed 10 characters causing overflow]
int main()
{
    int i;
    char* p; // @@ [Misuse of char pointer as loop variable for character iteration]
    gets(str); // @@ [Use of unsafe function 'gets' which can cause buffer overflow; also deprecated]
    int len = strlen(str);
    for (i = 0; i <= (strlen(str) - 1); i++) // @@ [Loop condition may cause out-of-bounds access when checking str[i+1] and str[i+2]]
        if (str[i + 1] == '-' && str[i + 2] - str[i] <= 25 && str[i + 2] - str[i]>0 && str[i+2]-'A'<=26) // @@ [Incorrect logic: only checks uppercase range with 'A', ignores lowercase and digits; also accesses str[i+2] without ensuring it's within bounds]
        {
            for (p = str[i]; p < str[i + 2]; p++) // @@ [Assigning char value to char pointer; should use char variable instead]
            {
                printf("%c", p); // @@ [Printing pointer address as char instead of character value]
            }
        }
        else if(str[i]!='-')
        {
            printf("%c", str[i]);
        }
}