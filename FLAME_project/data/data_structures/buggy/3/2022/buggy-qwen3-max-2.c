#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); @@ [The program reads the input but does not process it to convert into scientific notation.]
    puts(sz1); @@ [The program directly outputs the input without any conversion, which is why "0.9" is printed instead of "9e-1".]
    return 0;
}