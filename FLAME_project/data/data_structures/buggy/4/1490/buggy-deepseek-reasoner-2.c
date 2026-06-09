#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];
    fgets(c, 99, file); // @@ Only reads the first line; the program must read all words from the entire file.
    puts(c); // @@ Prints the raw line instead of counting word frequencies; output should be words with counts.
    fgets(d, 99, file); // @@ Only reads the second line; ignores remaining content.
    puts(d); // @@ Prints the raw line instead of word frequencies; output should be lexicographically sorted word counts.

    return 0;
}