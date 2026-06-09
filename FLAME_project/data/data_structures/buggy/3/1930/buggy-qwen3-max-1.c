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
            g = g - 1; // @@ [This adjustment of g is incorrect. For "0.9", g becomes 0-1 = -1, but the exponent should be -1, and the base should be '9'. The logic for computing exponent and extracting significant digits is flawed.]
        }
    }
    if (h[1] == '0') { // @@ [This condition checks if the second digit in h is '0', which is not the right way to detect leading zeros. For input "0.9", h becomes "09", so h[1] is '9', not '0', so this block is skipped incorrectly.]
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
        printf("%c", h[0]); // @@ [For "0.9", h[0] is '0', so it prints '0' as the first digit, which violates scientific notation rules (leading digit must be non-zero).]
        printf(".");
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g); // @@ [g was set to -1 for "0.9", so this prints "e-1", but because the base is printed as "0.9", the whole output becomes "0.9e-1" or similar — but actually due to earlier logic, it prints "0.9e-1" only if g=-1, but in reality the code prints "0.9e-1" only if the else branch runs, which it does, but with wrong base. However, in this specific run, since h[1] is '9', it goes to else, prints h[0]='0', then '.', then '9', then e and g=-1 → "0.9e-1", but expected is "9e-1". So the core issue is not skipping leading zeros properly and not normalizing the mantissa correctly.]
    }
}