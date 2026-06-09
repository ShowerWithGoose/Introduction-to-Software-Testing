#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

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
            g = g - 1; // @@ [This incorrectly adjusts the decimal position; it should record the index of '.' without subtracting 1. For "0.9", g becomes 0, but the correct exponent calculation requires knowing the original position of the decimal point.]
        }
    }
    if (h[1] == '0') { // @@ [This condition is flawed: it assumes that if the second digit in h is '0', then the number starts with zero(s). However, for input "0.9", h becomes "09", so h[1] is '9', not '0', causing this branch to be skipped incorrectly. The logic should find the first non-zero digit instead.]
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
        printf("%d", g); // @@ [The exponent 'g' is incorrectly computed. For "0.9", after removing '.', h = "09", and g = 0 (from i=1 for '.' then g = 1-1=0). But the correct scientific notation is 9e-1, meaning the exponent should be -1. The logic fails to handle leading zeros before the first significant digit.]
    }
}