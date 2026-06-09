#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ [The function `gets` is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and leads to undefined behavior. Use `fgets` instead. Additionally, the compilation error in the test environment suggests that the compiler or build tools may not be available, but the primary code issue is the use of `gets`.]
    return 0;
}