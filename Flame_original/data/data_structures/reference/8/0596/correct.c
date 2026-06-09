#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MaxV 128

int gragh[MaxV][MaxV] = { {0} }, visited[MaxV];
int list[MaxV], f = 0, r = -1, flag = 0;

void init() {
    r = -1;
    f = 0;
    for (int i = 0; i < MaxV; i++) visited[i] = 0;
}

void push(int n) {
    if (r != MaxV - 1) list[++r] = n;
    else printf("error1\n");
}
int pop() {
    if (f != r + 1) return list[f++];
    else return -1;
}

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) 
        if (gragh[v][i] && !visited[i]) 
            DFS(i, n);
}

void BFS(int v, int n) {
    push(v);
    visited[v] = 1;
    while (r < n - 1 - flag) {
        for (int i = 0; i < n; i++)
            if (gragh[v][i] && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        v = pop();
    }
    for (int i = 0; i <= r; i++) printf("%d ", list[i]);
}

int main() {
    int ver_n, edge_n, front, rear, delete_ver;
    scanf("%d%d", &ver_n, &edge_n);

    for (int i = 0; i < edge_n; i++) {
        scanf("%d%d", &front, &rear);
        gragh[front][rear] = gragh[rear][front] = 1;
    }
    scanf("%d", &delete_ver);

    DFS(0, ver_n);
    printf("\n");
    init();
    BFS(0, ver_n);

    for (int i = 0; i < ver_n; i++)
        gragh[delete_ver][i] = gragh[i][delete_ver] = 0;
    flag = 1;
    printf("\n");
    init();
    visited[delete_ver] = 1;
    DFS(0, ver_n);
    printf("\n");
    init();
    visited[delete_ver] = 1;
    BFS(0, ver_n);

	return 0;
}
