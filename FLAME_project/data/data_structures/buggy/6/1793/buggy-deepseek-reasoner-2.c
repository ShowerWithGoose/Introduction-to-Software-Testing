#include<stdio.h>
int main()
{
    char s; // @@ Declares a single character, but needs a buffer to hold the input string.
    gets(s); // @@ Using gets on a single character is incorrect and can cause buffer overflow. Also, input is a sequence of integers, need to parse.
    puts(s); // @@ Outputs a character but expects a string; does not produce the required output format.
    return 0;
}