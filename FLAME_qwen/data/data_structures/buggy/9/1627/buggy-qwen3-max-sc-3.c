#include <stdio.h>

int main() {
    int x1[105] = {0}, y1[105] = {0}, x2[105] = {0}, y2[105] = {0}, key[105];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        key[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (x2[i] == x1[j] && y2[i] == y1[j] && key[j] != -1) {
                key[i] = key[j] + key[i];
                key[j] = -1;
                x2[i] = x2[j];
                y2[i] = y2[j];
                printf("%d\n", key[i]); // @@ [Unnecessary debug print causes incorrect output format]
            } else if (x1[i] == x2[j] && y1[i] == y2[j] && key[j] != -1) {
                key[i] = key[j] + key[i];
                key[j] = -1;
                x1[i] = x1[j];
                y1[i] = y1[j];
                printf("%d\n", key[i]); // @@ [Unnecessary debug print causes incorrect output format]
            }
        }
    }
    int ans = 0, ans1;
    for (int i = 0; i < n; i++) {
        if (key[i] > ans) {
            ans = key[i];
            ans1 = i;
        }
    }
    printf("%d %d %d", ans, x1[ans1], y1[ans1]); // @@ [Missing newline at end of output may cause presentation error in some judges]
    return 0;
}