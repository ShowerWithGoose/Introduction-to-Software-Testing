#include<stdio.h>
int main()
{
    char s; // @@ [Error: 's' is declared as a single char, but gets() expects a char pointer (string buffer). This causes undefined behavior and likely a segmentation fault (Runtime Error) because gets tries to write to an invalid or insufficient memory location.]
    gets(s); // @@ [Error: Passing a char variable instead of a char array/pointer to gets. Additionally, gets is deprecated and unsafe, but the type mismatch is the immediate cause of the runtime error.]
    puts(s); // @@ [Error: Passing a char variable instead of a char pointer to puts. This will also cause undefined behavior/crash.]
    return 0;
}