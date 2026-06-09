#include<stdio.h>
int main()
{
    char s; // @@ [Error: 's' is declared as a single char, but gets() expects a char* (string buffer). This causes undefined behavior/runtime error as gets will write to invalid memory.]
    gets(s); // @@ [Error: Passing a char variable instead of a char array pointer to gets. Additionally, gets is deprecated/unsafe, but the type mismatch is the immediate runtime error cause.]
    puts(s); // @@ [Error: Passing a char variable instead of a char array pointer to puts.]
    return 0;
}