#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];
    fgets(c, 99, file);
    puts(c); // @@ [Only reads and prints the first two lines of the file without processing words, ignoring the rest of the file and not performing any word frequency counting or lexicographical sorting.]
    fgets(d, 99, file);
    puts(d); // @@ [Fails to read the entire file, does not extract words, convert to lowercase, count frequencies, or output in lexicographical order as required.]

    return 0;
}