#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

char s[N], ans[N], ch;
int id, size[N], t, tr[N][26], l;

void ins(char *c) {
    int u = 0;
    for (int i = 0; c[i]; i++) {
        int h = c[i] - 'a';
        if (!tr[u][h]) tr[u][h] = ++id;
        u = tr[u][h];
    } size[u]++;
}

void dfs(int u) {
    if (size[u]) {
        for (int i = 0; i < t; i++) putchar(ans[i] + 'a');
        printf(" %d\n", size[u]);
    }
    for (int i = 0; i < 26; i++)
        if (tr[u][i]) {
            ans[t++] = i;
            dfs(tr[u][i]);
            t--;
        }
}

int main() {
    FILE *in;
    in = fopen("article.txt", "r");
    while (~fscanf(in, "%c", &ch)) {
        if (isalpha(ch)) s[l++] = tolower(ch);
        else if (l) {
            s[l] = '\0';
            ins(s);
            l = 0;
        }
    }
    dfs(0);
    fclose(in);
    return 0;
}

