#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
    gets(w); // @@ 'gets' is removed in the C11 standard, causing a compilation error in modern environments; use fgets instead.
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
    } // @@ Missing null-termination for string h (h[y] = '\0';), leading to undefined behavior in subsequent string operations.
    if (h[1] == '0') { // @@ Logical error: incorrectly determines if the number is less than 1; should check if w[0] == '0'.
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) { // @@ Reads uninitialized memory due to missing null-terminator in h.
            flag++;
        }
        while (h[i] != '\0') { // @@ Reads past array bounds due to missing null-terminator in h.
            printf("%c", h[i]); // @@ Logical error: fails to output a decimal point after the first significant digit for numbers < 1.
            i++;
        }
        printf("e-");
        printf("%d", flag);
//完成了收个数为0的情况
    } else {
        printf("%c", h[0]);
        printf(".");
        int t = 1;
        while (h[t] != '\0') { // @@ Reads past array bounds due to missing null-terminator in h.
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g);
    }
}