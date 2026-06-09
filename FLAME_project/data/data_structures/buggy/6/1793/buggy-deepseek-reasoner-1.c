#include<stdio.h>
int main()
{
    char s; // @@ [error: s is a single char, not a char array. gets() expects a char* (buffer), causing undefined behavior.]
    gets(s); // @@ [error: gets() writes input into char variable, causing buffer overflow and likely crash or no output.]
    puts(s);
    return 0;
}