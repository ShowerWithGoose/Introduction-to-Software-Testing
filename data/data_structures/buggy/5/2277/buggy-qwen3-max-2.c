#include <stdio.h>
#include <string.h>
int main(void)
{
    char c;
    while ((c=getchar())!=EOF)
        printf("%c",c);
}