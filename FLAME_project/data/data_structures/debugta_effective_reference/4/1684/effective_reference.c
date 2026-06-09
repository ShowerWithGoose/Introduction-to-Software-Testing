#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

char s[N], ans[N], ch;
int cnt, size[N], u, tr[N][26], n;

void ins(char *c) {
    int u = 0;
    for (int i = 0; c[i]; i++) {
        int h = c[i] - 'a';
        if (!tr[u][h]) tr[u][h] = ++cnt;
        u = tr[u][h];
    } size[u]++;
}

void dfs(int u) {
    if (size[u]) {
        for (int i = 0; i < u; i++) putchar(ans[i] + 'a');
        printf(" %d\n", size[u]);
    }
    for (int i = 0; i < 26; i++)
        if (tr[u][i]) {
            ans[u++] = i;
            dfs(tr[u][i]);
            u--;
        }
}

int main() {
    FILE *in;
    in = fopen("article.txt", "r");
    while (~fscanf(in, "%c", &ch)) {
        if (isalpha(ch)) s[n++] = tolower(ch);
        else if (n) {
            s[n] = '\0';
            ins(s);
            n = 0;
        }
    }
    dfs(0);
    fclose(in);
    return 0;
}

