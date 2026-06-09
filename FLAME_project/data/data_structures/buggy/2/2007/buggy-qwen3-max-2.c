#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ [The program reads the input but does not parse or evaluate the arithmetic expression. Instead, it directly outputs the input string.]
    puts(a); // @@ [This outputs the entire input expression as a string instead of computing and outputting the result of the arithmetic expression.]
    return 0;
}