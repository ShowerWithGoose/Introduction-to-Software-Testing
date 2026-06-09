#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100]; // @@ In C89/C90 standard, variable declarations must be placed at the beginning of a block before any executable statements. Declaring variables after 'fopen' causes a compilation error.
    fgets(c, 99, file);
    puts(c);
    fgets(d, 99, file);
    puts(d);

    return 0;
}