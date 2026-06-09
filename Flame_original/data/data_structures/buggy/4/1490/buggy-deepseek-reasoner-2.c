#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];
    fgets(c, 99, file); // @@ Error: This reads a line, not individual words. Does not handle case conversion or frequency counting.
    puts(c); // @@ Error: Prints the raw line, not the required word frequency output in lexicographic order.
    fgets(d, 99, file); // @@ Error: Same as above; only processes two lines, ignoring rest of file and word splitting.
    puts(d); // @@ Error: Same issue.

    return 0;
}