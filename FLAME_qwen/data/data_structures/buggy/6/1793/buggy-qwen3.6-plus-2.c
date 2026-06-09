#include<stdio.h>
int main()
{
    char s;
    gets(s); // @@ 'gets' expects a 'char *' argument, but 's' is a single 'char', causing a type mismatch compilation error.
    puts(s); // @@ 'puts' expects a 'char *' argument, but 's' is a single 'char', causing a type mismatch compilation error.
    return 0;
}