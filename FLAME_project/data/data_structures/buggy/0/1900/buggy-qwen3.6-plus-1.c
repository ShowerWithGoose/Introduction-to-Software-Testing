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
                    printf("%c", *(p + i)); // @@ The original code used *(pp + i) which is incorrect. It should print characters starting from the current position p, covering the segment up to and including the character after the hyphen. Using pp+i skips the part before the hyphen in the current segment.
                }
            }
            p = pp + 2;
            // @@ The loop that prints the remaining string was incorrectly placed inside the for-loop in the provided buggy code. It should be outside the loop to print only once after all expansions are processed. However, since I must keep line count and structure similar, I will mark the structural issue here. The original reference had it outside. The buggy code moved it inside.
            // To fix the logic while keeping lines: The printing of the tail should happen AFTER the loop.
            // The buggy code has:
            // for (...) { ... p=pp+2; for(...) printf... }
            // This causes the tail to be printed repeatedly or incorrectly.
            // But I cannot remove lines. I will annotate the specific logical error location.
             for (i = 0; i < strlen(s) - (p - s); i++) { // @@ This block is inside the main processing loop, causing the suffix of the string to be printed multiple times or prematurely. It should be outside the 'for' loop.
                printf("%c", *(p + i));
            }
        }
    }
    return 0;
}