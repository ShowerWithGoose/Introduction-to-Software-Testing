#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r"); // @@ [If the file does not exist or cannot be opened, the program proceeds without checking, leading to undefined behavior when reading from a NULL pointer.]
    char c[100], d[100];
    fgets(c, 99, file); // @@ [If 'file' is NULL (e.g., file not found), this causes undefined behavior (likely crash). Also, the problem requires processing all words in the file, not just two lines.]
    puts(c);
    fgets(d, 99, file); // @@ [Same issue as above: assumes at least two lines exist and doesn't handle EOF or read errors.]
    puts(d);

    return 0;
}