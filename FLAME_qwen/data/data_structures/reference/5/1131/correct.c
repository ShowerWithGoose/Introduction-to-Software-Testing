#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2) {
    int* a = (int*)p1;
    int* b = (int*)p2;
    return b[0]-a[0];
}
int main() {
    int n = 1, k = 0, m = 1, i, j;
    char ch;
    int a[100][2], b[100][2], c[1000][2];
    scanf("%d%d%c", &a[0][0], &a[0][1], &ch);
    for (i = 1;ch != '\n';i++) {
        scanf("%d%d%c", &a[i][0], &a[i][1], &ch);
        n++;
    }
    scanf("%d%d%c", &b[0][0], &b[0][1], &ch);
    for (i = 1;ch != '\n';i++) {
        scanf("%d%d%c", &b[i][0], &b[i][1], &ch);
        m++;
    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            c[k][1] = a[i][0] * b[j][0];
            c[k][0] = a[i][1] + b[j][1];
            k++;
        }
    }

    qsort(c, k, sizeof(int) * 2, cmp);
    for (i = 1;i < k;i++) {
        if (c[i][0] == c[i - 1][0]) {
            c[i - 1][0] = 0;
            c[i][1] += c[i - 1][1];
            c[i - 1][1] = 0;
        }
    }
    qsort(c, k, sizeof(int) * 2, cmp);
    for (i = 0;i < k;i++) {
        if (c[i][1] != 0) {
            printf("%d %d ", c[i][1], c[i][0]);
        }
    }
    return 0;
}

