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
            g = g - 1;
        }
    }
    if (h[1] == '0') { // @@ Error: Condition should check h[0] == '0' to correctly identify numbers with leading zero before decimal point (e.g., "0.1" incorrectly goes to else branch).
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) {
            flag++;
        }
        while (h[i] != '\0') {
            printf("%c", h[i]); // @@ Error: Missing decimal point after the first significant digit. Should print the first digit, then '.' if there are more digits, then the rest (e.g., for "0.00123" outputs "123" instead of "1.23").
            i++;
        }
        printf("e-");
        printf("%d", flag);
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