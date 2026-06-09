#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);

int main() {
    char s[100];
    gets(s); // @@ [gets is deprecated and dangerous; should use fgets instead. Also, the program does not implement the required arithmetic evaluation logic.]
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
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Using pow for integer arithmetic is inefficient and may cause precision issues; also, the function is not used in the main logic.]
    } else {
        w = q - p - 1;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Same issue as above.]
    }
    return sum;
}