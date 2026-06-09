#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char *s) {
    int n = strlen(s);
    int num = 0, stk[n], top = -1, res = 0;
    char presign = '+';
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (int) (s[i] - '0');
        }
        if ((s[i] != ' ' && !isdigit(s[i])) || i == n - 1) {
            switch (presign) {
                case '+':
                    top++;
                    stk[top] = num;
                    break;
                case '-':
                    top++;
                    stk[top] = -num;
                    break;
                case '*':
                    stk[top] *= num;
                    break;
                case '/':
                    stk[top] /= num;
                    break;
            }
            presign = s[i];
            num = 0;
        }
    }
    for (int i = 0; i <= top; i++) {
        res += stk[i];
    }
    return res;
}

int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    char s[200];
    gets(s);
    printf("%d", calculate(s));
    return 0;
}

