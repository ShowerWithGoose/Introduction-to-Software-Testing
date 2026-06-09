#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145]; // @@ [The program does not read input or evaluate the arithmetic expression as required. It declares a buffer but does nothing with it, leading to incorrect output (always returns 0). Additionally, using `gets` is unsafe and may be unavailable, but the real issue here is missing logic for parsing and evaluating the expression according to operator precedence and integer division.]
    return 0;
}