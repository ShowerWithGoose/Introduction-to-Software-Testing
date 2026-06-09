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
                key[i] = key[j] + key[i]; // @@ [This logic incorrectly assumes segments can only be extended forward; it fails to handle cases where a segment should be prepended to an existing chain, and the update of endpoints may break continuity]
                key[j] = -1;
                x2[i] = x2[j];
                y2[i] = y2[j];
                printf("%d\n", key[i]); // @@ [Unnecessary debug print that alters expected output format]
            } else if (x1[i] == x2[j] && y1[i] == y2[j] && key[j] != -1) {
                key[i] = key[j] + key[i]; // @@ [Same issue: merging logic is flawed because it modifies the current segment's start point but doesn't correctly maintain the full chain's start point for maximum-length tracking]
                key[j] = -1;
                x1[i] = x1[j];
                y1[i] = y1[j];
                printf("%d\n", key[i]); // @@ [Unnecessary debug print that alters expected output format]
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
    printf("%d %d %d", ans, x1[ans1], y1[ans1]); // @@ [May output incorrect starting point because x1[ans1] might have been overwritten during merging in a way that doesn't preserve the true leftmost start of the continuous segment]
    return 0;
}