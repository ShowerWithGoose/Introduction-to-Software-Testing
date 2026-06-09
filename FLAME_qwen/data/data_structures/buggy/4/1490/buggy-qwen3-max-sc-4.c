#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r"); // @@ [If the file does not exist or cannot be opened, the program proceeds without checking for NULL, leading to undefined behavior when calling fgets on a NULL pointer.]
    char c[100], d[100];
    fgets(c, 99, file); // @@ [Using fgets on a potentially NULL file pointer causes undefined behavior. Also, the problem requires reading all words from the file, not just two lines.]
    puts(c);
    fgets(d, 99, file); // @@ [Same issue as above: assumes at least two lines exist and doesn't handle general word frequency counting.]
    puts(d);

    return 0;
}