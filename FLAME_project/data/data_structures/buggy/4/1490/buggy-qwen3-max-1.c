#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];
    fgets(c, 99, file); @@ [Only reads the first line of the file, ignoring the rest. The problem requires processing the entire file.]
    puts(c); @@ [Outputs the raw input line including punctuation and mixed case, instead of counting word frequencies in lowercase and ignoring non-letter characters.]
    fgets(d, 99, file); @@ [Only reads the second line, still ignoring the rest of the file if it has more than two lines. Also does not process words correctly.]
    puts(d); @@ [Same issue as above: outputs raw line instead of processed word counts.]

    return 0;
}