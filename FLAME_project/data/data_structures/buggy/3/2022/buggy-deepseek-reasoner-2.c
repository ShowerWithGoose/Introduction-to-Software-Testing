#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1);
    puts(sz1); // @@ Error: This prints the original input, but the program should convert it to scientific notation and output that instead.
    return 0;
}