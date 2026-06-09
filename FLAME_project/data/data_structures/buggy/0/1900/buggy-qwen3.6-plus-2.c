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
                    printf("%c", *(p + i)); // @@ The original code used *(pp + i) which is incorrect. It should print from the current start pointer p, covering the segment up to and including the character after the hyphen. Using pp+i starts printing from the hyphen itself but offsets incorrectly relative to the segment start p, leading to wrong characters being printed or out-of-bounds access logic errors in context of the loop structure intended to print the unexpanded segment. Specifically, it should print the substring from p to pp+1 inclusive. *(p+i) iterates correctly from the start of the current segment.
                }
            }
            p = pp + 2;
             // @@ The original code had the final suffix printing loop INSIDE the for loop. This causes the remainder of the string to be printed multiple times (once for each hyphen processed). It must be moved outside the for loop to print only the final remaining part of the string after the last hyphen is processed.
        }
        for (i = 0; i < strlen(s) - (p - s); i++) {
            printf("%c", *(p + i));
        }
    }
    return 0;
}