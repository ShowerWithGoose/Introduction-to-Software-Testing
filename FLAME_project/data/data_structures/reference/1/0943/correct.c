#include <stdio.h>

int n;
int stack[10];

void print_stack();
void dfs(int len);
int find_in_stack(int key, int len);

int main() {
    scanf("%d", &n);
    dfs(0);
    // 没错我的代码可以很潇洒
    return 0;
}

void dfs(int len) {
    if (len == n) {
        print_stack();
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!find_in_stack(i, len)) {
            stack[len] = i;
            dfs(len + 1);
        }
}

void print_stack() {
    for (int i = 0; i < n; i++)
        printf("%d ", stack[i]);
    puts("");
}

int find_in_stack(int key, int len) {
    for(int i = 0; i < len; i++)
        if (key == stack[i])
            return 1;
    return 0;
}
