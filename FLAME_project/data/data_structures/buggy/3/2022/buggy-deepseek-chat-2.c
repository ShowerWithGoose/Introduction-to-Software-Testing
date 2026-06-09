#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [gets() is unsafe and does not handle the conversion to scientific notation; the program simply outputs the input unchanged, failing to implement the required logic]
    puts(sz1); // @@ [This line outputs the original input string instead of converting it to scientific notation as specified]
    return 0;
}