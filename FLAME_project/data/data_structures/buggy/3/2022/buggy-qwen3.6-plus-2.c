#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ The program simply reads the input and prints it back, failing to implement the logic for converting to scientific notation. It should parse the number, determine the exponent, and format the output as required.
    puts(sz1); // @@ This line outputs the original decimal string instead of the calculated scientific notation.
    return 0;
}