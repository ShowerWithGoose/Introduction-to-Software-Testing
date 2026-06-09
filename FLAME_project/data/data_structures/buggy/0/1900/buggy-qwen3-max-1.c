#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int f(char a, char b) {
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b - a > 0) {
        return 1;
    } else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && b - a > 0) {
        return 1;
    } else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && b - a > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char s[1001];
    char *p = NULL, *pp = NULL;
    int i, j;
    gets(s);
    p = strchr(s, '-');
    if (p == NULL) {
        puts(s);
    } else {
        for (p = s; (pp = strchr(p, '-')) != NULL && (pp + 1) != NULL;) {
            if (f(*(pp - 1), *(pp + 1)) == 1) {
                for (i = 0; i < pp - p; i++) {
                    printf("%c", *(p + i));
                }
                for (i = 1; i <= *(pp + 1) - * (pp - 1); i++) {
                    printf("%c", *(pp - 1) + i);
                }
            } else {
                for (i = 0; i < pp - p + 2; i++) {
                    printf("%c", *(p + i)); // @@ [In the else block, it should print from p, not from pp. The original code incorrectly uses *(pp + i) which starts printing from the '-' character instead of the beginning of the current segment.]
                }
            }
            p = pp + 2;
            for (i = 0; i < strlen(s) - (p - s); i++) {
                printf("%c", *(p + i)); // @@ [This loop is inside the for-loop and executes after every expansion or non-expansion, causing repeated output of the remaining string. It should be outside the for-loop to only print the leftover part once at the end.]
            }
        }
    }
    return 0;
}