#include <stdio.h>
#include <string.h>
void squeez(char c[]) {
    int i, j;
    for (i = 0, j = 0; c[i] != '='; i++) {
        if (c[i] != ' ') c[j++] = c[i];
    }
    c[j] = '\0';
    return;
}
int findSign(char c[], int a[], char b[]) {
    int i = 0, j, k, count = 0;
    for (i = j = k = 0; i == 0 || c[i - 1] != '\0'; i++) {
        if (c[i] >= '0' && c[i] <= '9')
            count = count * 10 + c[i] - '0';
        else {
            a[j++] = count;
            count = 0;
            b[k++] = c[i];
        }
    }
    return j;
}
int count(int a[], char s[], int n) {
    int i, j, cou, res, num[10001];
    for (i = j = 0; i < n; i++) {
        cou = a[i];
        while (s[i] == '*' || s[i] == '/') {
            if (s[i] == '*')
                cou *= a[++i];
            else
                cou /= a[++i];
        }
        num[j++] = cou;
    }
    res = num[0];
    for (i = 0, j = 1; i < n; i++) {
        if (s[i] == '+')
            res += num[j++];
        else if (s[i] == '-')
            res -= num[j++];
    }
    return res;
}
int main() {
    char in[10001], sign[10001];
    int num[10001], res, n, i;
    gets(in);
    squeez(in);
    n = findSign(in, num, sign);
    res = count(num, sign, n);
    printf("%d", res);
    return 0;
}


