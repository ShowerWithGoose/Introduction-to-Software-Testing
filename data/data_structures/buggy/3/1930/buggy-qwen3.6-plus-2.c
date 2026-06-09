#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
    gets(w); // @@ gets() has been removed from the C11 standard and will cause a compilation error on modern compilers; use fgets() instead.
    int len_w = strlen(w);
    int y = 0, g = -1; // @@ 'y' is already declared as a global array 'char y[1000]', causing a redefinition/conflict compilation error.
    for (int i = 0; i < len_w; i++) {
        if (w[i] != '.') {
            h[y] = w[i];
            y++;
        } else if (w[i] == '.') {
            g = i;
            g = g - 1;
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
        printf("%d", g);
    }
}