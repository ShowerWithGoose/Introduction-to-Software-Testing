#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [The program immediately outputs the input without any conversion to scientific notation, completely ignoring the problem requirements.]
    puts(sz1); // @@ [This line just prints the original input (e.g., "0.9") instead of converting it to scientific notation (e.g., "9e-1").]
    return 0;
}