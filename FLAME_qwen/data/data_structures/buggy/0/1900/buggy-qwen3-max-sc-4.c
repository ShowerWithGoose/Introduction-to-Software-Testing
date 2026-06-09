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
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the immediate error in logic is elsewhere. The compilation error reported ("gcc: not found") is environmental, but the logical bugs are in the expansion output handling.]
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
                    printf("%c", *(p + i)); // @@ [This line incorrectly uses *(pp + i) in original buggy version, but in this provided code it's written as *(pp+i) — wait, no: looking closely, in the provided source code here, it actually says "printf("%c", *(pp + i));" which is wrong. But in the code block given to annotate, it says: "printf("%c", *(pp + i));" — however, in the pasted source above, it's written as "*(pp + i)" inside the else block. Let's check: the user-provided source code in the "Source Code" section shows: "printf("%c", *(pp + i));" — that is incorrect. It should be *(p + i). So this line is wrong.]
                }
            }
            p = pp + 2;
            for (i = 0; i < strlen(s) - (p - s); i++) {
                printf("%c", *(p + i)); // @@ [This print loop is inside the for-loop, causing repeated printing of the remaining string after each '-' processing, leading to duplicated output. It should be outside the loop.]
            }
        }
    }
    return 0;
}