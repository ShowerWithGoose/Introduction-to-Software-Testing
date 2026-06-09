#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000]; // @@ Unused array; shadows later int y, but not directly causing error.

int main() {
    gets(w);
    int len_w = strlen(w);
    int y = 0, g = -1;
    for (int i = 0; i < len_w; i++) {
        if (w[i] != '.') {
            h[y] = w[i];
            y++;
        } else if (w[i] == '.') {
            g = i;
            g = g - 1; // @@ Error: For numbers with leading zero (e.g., "0.9"), this computes g = 0, but correct exponent should be -1. This incorrect value is used in the else branch, contributing to wrong output.
        }
    }
    if (h[1] == '0') { // @@ Error: Condition should check first digit (h[0] == '0') to correctly handle numbers less than 1 like "0.9". Current condition misses "0.9" because h[1] = '9', so it goes to else branch, producing incorrect output "0.9e0".
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) {
            flag++;
        }
        while (h[i] != '\0') {
            printf("%c", h[i]);
            i++;
        }
        printf("e-");
        printf("%d", flag);
//完成了收个数为0的情况
    } else {
        printf("%c", h[0]);
        printf(".");
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g);
    }
}