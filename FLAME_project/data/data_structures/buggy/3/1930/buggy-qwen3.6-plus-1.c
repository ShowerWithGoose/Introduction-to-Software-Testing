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
            g = g - 1; // @@ The calculation of the exponent 'g' is incorrect for numbers less than 1 (e.g., 0.9). For 0.9, g becomes -1, but the logic below fails to handle the normalization correctly because it assumes h[0] is the first non-zero digit, which is true, but the exponent calculation and output format are flawed for this specific case structure.
        }
    }
    if (h[1] == '0') { // @@ This condition checks if the second significant digit is '0'. For input "0.9", h is "9", so h[1] is '\0' (or garbage/0), not '0'. This branch is intended for cases like 0.00... but fails to catch the simple 0.X case properly or misidentifies it. More critically, for "0.9", h[0]='9', h[1]='\0'. The condition h[1]=='0' is false. It goes to else.
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
        printf("."); // @@ For input "0.9", the expected output is "9e-1" (integer base if only one significant digit? No, problem says: "If it’s an integer, it contains only one significant digit without a decimal point." Wait, 9 is an integer. But scientific notation usually has 1 digit before decimal. The problem says: "The base is either a decimal or an integer. If it’s a decimal... If it’s an integer, it contains only one significant digit without a decimal point." Since 9 is a single digit, it should be printed as "9", not "9.". The code always prints a decimal point here.
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g); // @@ For "0.9", g is -1. The output becomes "9.e-1". The expected is "9e-1". Two errors: 1. The trailing dot should not be there if there are no fractional digits. 2. The problem states if the base is an integer (one significant digit), no decimal point. Here h[0]='9', h[1]='\0'. The loop `while(h[t]!='\0')` doesn't run. So it prints "9.". It should print "9".
    }
}