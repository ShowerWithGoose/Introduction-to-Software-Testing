#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);

int main() {
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Additionally, the program does not process the expression or output the result as required.]
    puts(s); // @@ [This outputs the input string instead of the computed result of the arithmetic expression.]


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
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Using pow() from math.h for integer powers is inefficient and may introduce floating-point inaccuracies; also, logic for extracting number between p and q is flawed because when p > 0, it ignores s[p+1] to s[q-1] correctly? Actually, the indexing assumes digits are between p+1 and q-1 but the loop uses q-1-i which may go before p+1.]
    } else {
        w = q - p - 1;
        for (int i = 0; i < w; i++)
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ [Same issue with pow() and incorrect digit extraction logic; for example, if p=2, q=5, it should extract s[3], s[4], but this accesses s[4], s[3] then multiplies by 10^0, 10^1 — which is correct order, BUT only if the substring is exactly from p+1 to q-1. However, the function is never even called in main, so the whole logic is unused.]
    }
    return sum;
}