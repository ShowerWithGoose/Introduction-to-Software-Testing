#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [The program only reads and prints the input without performing any conversion to scientific notation. It fails to handle the case where the input is "0.9" and should output "9e-1".]
    puts(sz1); // @@ [This line simply outputs the original input string, which is incorrect for the required scientific notation output.]
    return 0;
}