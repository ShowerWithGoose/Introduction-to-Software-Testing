#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1);
    puts(sz1); // @@ [Error: outputs the input as-is without converting to scientific notation; for input "0.9", expected output is "9e-1".]
    return 0;
}