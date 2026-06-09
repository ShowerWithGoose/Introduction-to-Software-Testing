#include<stdio.h>
int main()
{
    char s; // @@ [s should be a character array to hold input string, otherwise gets() expects a pointer to buffer]
    gets(s); // @@ [gets(s) is invalid because s is a char, not a char array; should be gets(s) with s as array, or use fgets]
    puts(s);
    return 0;
}