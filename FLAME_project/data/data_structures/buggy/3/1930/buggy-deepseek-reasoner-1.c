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
            g = g - 1; // @@ [exponent computation wrong for numbers <1; gives 0 for "0.9" but should be -1]
        }
    }
    if (h[1] == '0') { // @@ [condition too narrow; fails for numbers like "0.9" where h[1] is not '0' but number is still <1]
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) {
            flag++;
        }
        while (h[i] != '\0') { // @@ [should insert decimal point after first non-zero digit when multiple digits remain]
            printf("%c", h[i]);
            i++;
        }
        printf("e-");
        printf("%d", flag);
//完成了收个数为0的情况
    } else {
        printf("%c", h[0]); // @@ [prints leading zero for numbers <1, e.g., "0.9" outputs '0']
        printf("."); // @@ [unnecessary decimal point when base should be integer, e.g., "0.9" should output "9"]
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g); // @@ [exponent wrong for numbers <1; gives 0 instead of -1 for "0.9"]
    }
}