#include <stdio.h>
#include <string.h>
int main(void)
{
    char c; // @@ [c should be declared as int to correctly store the return value of getchar() and compare with EOF]
    while ((c=getchar())!=EOF) // @@ [Using char for c may cause incorrect comparison with EOF if char is unsigned, leading to infinite loop or logic error]
        printf("%c",c); // @@ [The program only echoes input and completely lacks the logic to parse and multiply polynomials as required by the problem]
}