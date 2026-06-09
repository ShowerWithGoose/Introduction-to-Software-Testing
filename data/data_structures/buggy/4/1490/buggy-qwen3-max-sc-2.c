#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("article.txt", "r");
    char c[100], d[100];
    fgets(c, 99, file); // @@ [Potential runtime error: if file is NULL (e.g., file not found), fgets will cause undefined behavior. Also, the program does not check if fopen succeeded.]
    puts(c);
    fgets(d, 99, file); // @@ [Same issue: no check for file == NULL before reading; also, if the file has less than two lines, this may read invalid data or cause unexpected behavior.]
    puts(d);

    return 0;
}