#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145]; // @@ [The program does not read input or evaluate the arithmetic expression; it declares a buffer but does nothing with it, leading to incorrect output. Also, using gets() is unsafe and may cause compilation issues in modern compilers, but here the code doesn't even attempt parsing or calculation.]
    return 0;
}