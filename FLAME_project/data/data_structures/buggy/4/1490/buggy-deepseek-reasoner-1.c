#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];  // @@ Arrays are intended for words, but used to store lines; not suitable for word frequency count.
    fgets(c, 99, file);   // @@ Only reads the first line; should read the entire file and extract words until EOF.
    puts(c);              // @@ Prints raw input line instead of word frequencies; adds extra newline because c already contains newline from fgets.
    fgets(d, 99, file);   // @@ Only reads the second line; missing reading of remaining lines.
    puts(d);              // @@ Same as above; prints second line instead of word frequencies.

    return 0;
}