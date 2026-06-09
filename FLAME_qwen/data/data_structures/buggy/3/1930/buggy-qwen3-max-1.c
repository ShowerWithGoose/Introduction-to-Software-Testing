#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
    gets(w); @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    int len_w = strlen(w);
    int y = 0, g = -1; @@ [Variable 'y' shadows global array 'y'; causes type conflict when using 'y' as integer index]
    for (int i = 0; i < len_w; i++) {
        if (w[i] != '.') {
            h[y] = w[i];
            y++;
        } else if (w[i] == '.') {
            g = i;
            g = g - 1;
        }
    }
    if (h[1] == '0') { @@ [Incorrect condition: should check if the first non-zero digit is after leading zeros, not just h[1]; also fails when input starts with non-zero]
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) { @@ [If h[0] is not '0', this loop doesn't run, but condition above assumes h[1]=='0' which is unreliable]
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
        printf("%d", g); @@ [Exponent calculation is incorrect; 'g' is set to (position of '.' - 1), but doesn't account for leading zeros or proper normalization]
    }
}