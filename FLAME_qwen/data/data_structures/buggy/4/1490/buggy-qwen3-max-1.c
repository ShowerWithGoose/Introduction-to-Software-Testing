#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r"); // @@ [If the file does not exist or cannot be opened, the program will proceed with a NULL pointer, leading to undefined behavior when used in fgets. The program should check if file is NULL before reading.]
    char c[100], d[100];
    fgets(c, 99, file); // @@ [Using fgets on a potentially NULL file pointer causes undefined behavior. Additionally, the problem requires processing all words in the file, not just two lines.]
    puts(c);
    fgets(d, 99, file); // @@ [Same issue as above: assumes exactly two lines exist and ignores the rest of the file. Also fails if file has fewer than two lines.]
    puts(d);

    return 0;
}