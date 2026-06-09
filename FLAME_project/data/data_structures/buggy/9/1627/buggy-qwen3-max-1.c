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
                key[i] = key[j] + key[i]; // @@ This condition checks if segment i ends where segment j starts, but the logic is reversed: it should check if segment j ends where segment i starts to extend forward.
                key[j] = -1;
                x2[i] = x2[j];
                y2[i] = y2[j];
                printf("%d\n", key[i]);
            } else if (x1[i] == x2[j] && y1[i] == y2[j] && key[j] != -1) {
                key[i] = key[j] + key[i]; // @@ This correctly handles extending segment i backward by attaching segment j in front, but the loop order (i from 1 to n-1, j from 0 to i-1) may miss chains that require multiple passes or proper topological order.
                key[j] = -1;
                x1[i] = x1[j];
                y1[i] = y1[j];
                printf("%d\n", key[i]);
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
    printf("%d %d %d", ans, x1[ans1], y1[ans1]); // @@ The output format is correct, but due to incorrect chaining logic above, 'ans' may not represent the true maximum chain length. Also, the initial value of 'ans1' is uninitialized if all key[i] <= 0, though constraints likely prevent this.
    return 0;
}