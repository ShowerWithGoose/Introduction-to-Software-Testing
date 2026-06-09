#include <stdio.h>

void arrange(int, int);

int main() {
    int n;
    scanf("%d", &n);
    arrange(n, 0);
    return 0;
}

int out[10], flag[10] = {0};
void arrange(int m, int step) {
    int i=0;
    if (step == m) {
        for (i = 0; i < m; i++) {
            printf("%d ",out[i]);
        }
        printf("\n");
        return;
    }
    for (i = 0; i < m; i++) {
        if (flag[i] == 0) {
            out[step] = i + 1;
            flag[i] = 1;
            arrange(m, step + 1);
            // printf("%d",m);
            flag[i] = 0;
        }
    }
}


