#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cL while (getchar() != '\n')  // clear line
#define fi(x) for (i = 0; i < x; i++)
#define fj(x) for (j = 0; j < x; j++)
#define FOR(a, b, c) for (int(a) = (b); (b) < (c) ? (a) <= (c) : (a) >= (c); (b) < (c) ? (a)++ : (a)--)
#define LL long long
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)
#define pf printf
#define sf scanf

char c[2000];
int readnum(int* i);
void squeez(char s[], char c);
int main() {
    int ans = 0, now = 0, sgn = 1;
    fgets(c, 1999, stdin);
    squeez(c, ' ');
    int l = strlen(c);
    FOR(i, 0, l - 1) {
        if (c[i] == '-')
            ans += now * sgn, now = 0, sgn = -1;
        else if (c[i] == '+' || c[i] == '=')
            ans += now * sgn, now = 0, sgn = 1;
        else if (c[i] == '*')
            i++,now *= readnum(&i);
        else if (c[i] == '/')
            i++,now /= readnum(&i);
        else if (c[i] >= '0' && c[i] <= '9')
            now = readnum(&i);
    }
    printf("%d",ans);
    return 0;
}
void squeez(char s[], char x) {
    int i, j;
    for (i = j = 0; s[i] != 0; i++)
        if (s[i] != x)
            s[j++] = s[i];
    s[j] = '\0';
}
int readnum(int* i) {
    int n = 0;
    while (c[*i] <= '9' && c[*i] >= '0') {
        n *= 10;
        n += c[*i] - '0';
        *i+=1;
    }
    *i-=1;
    return n;
}


