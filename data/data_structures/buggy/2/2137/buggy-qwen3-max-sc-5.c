#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);

int main() {
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. More critically, the program does not process the expression or handle the '=' terminator, so it just prints the raw input instead of computing the result.]
    puts(s); // @@ [This outputs the unprocessed input string instead of the computed arithmetic result, violating the problem's output requirement.]


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
            sum += (s[q - 1 - i] - '0' ) * pow(10, i);
    } else {
        w = q - p - 1;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i);
    }
    return sum;
}