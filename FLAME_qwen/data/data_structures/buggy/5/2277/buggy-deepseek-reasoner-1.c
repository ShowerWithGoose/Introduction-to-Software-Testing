#include <stdio.h>
#include <string.h>
int main(void)
{
    char c;
    while ((c=getchar())!=EOF) // @@ [c should be int to correctly compare with EOF; comparing char with EOF may cause compilation warnings or errors depending on the compiler settings]
        printf("%c",c);
}