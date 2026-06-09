#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);

int main() {
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the program does not process the arithmetic expression as required—it only reads and prints the input.]
    puts(s); // @@ [The program outputs the raw input instead of computing and outputting the result of the arithmetic expression.]


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
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Using pow() from math.h for integer powers is inefficient and may introduce floating-point inaccuracies; also, this function is never used in main().]
    } else {
        w = q - p - 1;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Same issue with pow(); additionally, the logic for extracting numbers is overly complex and unused.]
    }
    return sum;
}