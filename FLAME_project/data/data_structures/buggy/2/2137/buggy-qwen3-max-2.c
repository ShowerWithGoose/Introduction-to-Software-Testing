#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);

int main() {
    char s[100];
    gets(s); // @@ [The `gets` function is unsafe and deprecated; it was removed in C11. Use `fgets` instead. Also causes implicit declaration warning if headers don't declare it, though here it's more about linking and safety.]
    puts(s);


    return 0;
}


char *blank(char s[]) {
    char *newStr;
    int i, j = 0;

    newStr = (char *)malloc(strlen(s) + 1);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            newStr[j++] = s[i];
        }
    }
    newStr[j] = '\0';

    return newStr;
}

int getnum(char s[], int p, int q) {

    int w, sum = 0;
    if (p == 0) {
        w = q;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Using `pow` from math.h requires linking with `-lm`, otherwise causes undefined reference to `pow` during linking. Also inefficient for integer powers of 10.]
    } else {
        w = q - p - 1;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Same issue: undefined reference to `pow` due to missing math library linking, leading to compilation/linking error.]
    }
    return sum;
}