#include <stdio.h>
#include <string.h>
int main(void)
{
    char c;
    while ((c=getchar())!=EOF)
        printf("%c",c); // @@ [The program simply echoes input characters without parsing or multiplying polynomials. It completely ignores the problem requirements and does not implement polynomial multiplication logic.]
}