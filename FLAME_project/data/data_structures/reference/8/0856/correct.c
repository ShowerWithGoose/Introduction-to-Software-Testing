#include <stdio.h>
#include <string.h>

int graph[100][100], flag1[100][100], flag2[100], del, m, count;

void graph_input() {
    int n, i, x, y;
    scanf("%d %d", &m, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }
    scanf("%d", &del);
    return;
}

void delete () {
    int i;
    for (i = 0; i <= 99; i++) graph[del][i] = graph[i][del] = 0;
    m--;
    return;
}

void reset() {
    printf("\n");
    memset(flag1, 0, sizeof(flag1));
    memset(flag2, 0, sizeof(flag2));
    count = 0;
    return;
}

void search1(int p) {
    int i;
    if (flag2[p] == 0) printf("%d ", p);
    flag2[p] = 1;
    for (i = 0; i <= 99; i++)
        if (graph[p][i] == 1 && flag1[p][i] == 0 && flag2[i] == 0) {
            flag1[p][i] = flag1[i][p] = 1;
            search1(i);
        }
    return;
}

void find(int p, int q) {
    int i;
    if (q != 0) {
        for (i = 0; i <= 99; i++)
            if (graph[p][i] == 1 && flag1[p][i] == 0) {
                flag1[p][i] = flag1[i][p] = 1;
                find(i, q - 1);
            }
    } else if (count < m && flag2[p] == 0) {
        printf("%d ", p);
        count++;
        flag2[p] = 1;
    }
    return;
}

void search2() {
    int i = 0;
    while (count < m) {
        find(0, i);
        memset(flag1, 0, sizeof(flag1));
        i++;
    }
    return;
}

int main() {
    graph_input();
    search1(0);
    reset();
    search2();
    reset();
    delete ();
    search1(0);
    reset();
    search2();
    return 0;
}
