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
            g = g - 1; // @@ Error: g should be the index of the decimal point, but subtracting 1 makes it incorrect for exponent calculation. For input "0.9", g becomes -1, leading to wrong exponent.
        }
    }
    if (h[1] == '0') {
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
        printf("%d", g); // @@ Error: g is incorrectly computed (e.g., for "0.9", g = -1, but expected exponent is -1; however, the logic for handling leading zeros is flawed, and for non-zero first digit cases, g is also wrong because it was decremented unnecessarily.
    }
}