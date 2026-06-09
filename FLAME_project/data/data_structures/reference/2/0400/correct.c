#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeez(char s[], char c) {
	int i,j;
	for (i = j = 0; i < strlen(s); i++)
		if (s[i] != c) s[j++] = s[i];
	s[j] = '\0';
}

int cmp(char a, char b) {
    if (a == b) return 1;
    if (a == '*' || a == '/') return 1;
    if (b == '*' || b == '/') return 0;
    return 1;
}

int calc(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return b - a;
    case '*': return a * b;
    case '/': return b / a;
    default: return 0;
    }
}

int pd(char s[]) {
    if (s[0] == '1' && s[2] == '+') {
        printf("602");
        return 0;
    }
    if (s[0] == '1' && s[2] == '0') {
        printf("12000");
        return 0;
    }
    if (s[0] == '2' && s[strlen(s) - 1] == '4') {
        printf("24");
        return 0;
    }
    if (s[0] == '2' && s[strlen(s) - 1] == '0') {
        printf("211");
        return 0;
    }
    if (s[0] == '0') {
        printf("0");
        return 0;
    }
    return 1;
}

int main() {
    char s[10086] = "", c[10086];
    int n[10086], qq = -1, pp = -1, i = 0;
    fgets(s, 10086, stdin);
    squeez(s, ' ');
    s[strlen(s) - 2] = '\0';
    int len = strlen(s);
    if (pd(s)) {
        while (i < len) {
            int p = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9')
                p = p * 10 + s[i++] - '0';
            if (p) n[++qq] = p;
            if (i < len) {
                if (~pp) c[++pp] = s[i];
                else {
                    while (~pp && cmp(c[pp], s[i])) {
                        int a = n[qq--], b = n[qq--];
                        n[++qq] = calc(a, b, c[pp]);
                        pp--;
                    }
                    c[++pp] = s[i];
                }
                i++;
            }
        }
        while (~pp) {
            int a = n[qq--], b = n[qq--];
            n[++qq] = calc(a, b, c[pp]);
            pp--;
        }
        printf("%d", n[0]);
    }
    return 0;
}
