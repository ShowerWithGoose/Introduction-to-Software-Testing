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
                printf("%d\n", key[i]);
            } else if (x1[i] == x2[j] && y1[i] == y2[j] && key[j] != -1) {
                key[i] = key[j] + key[i];
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
    printf("%d %d %d", ans, x1[ans1], y1[ans1]); // @@ [The program outputs the count 'ans' directly, but it should output the number of segments in the continuous line. However, 'key[i]' already stores the count of merged segments, so this is correct in logic. The real issue is that the merging logic only checks backward (j < i) and assumes segments are processed in an order that allows chaining, but the input order may not support forward chaining correctly. Also, the algorithm fails to consider that a segment might extend a chain in both directions or that multiple merges may be needed. Specifically, in the test case, the first segment (12,12)-(13,13) is at index 0 and the second (13,13)-(50,76) is at index 1. When i=1, j=0: x1[1]=13,y1[1]=13 matches x2[0]=13,y2[0]=13, so the else-if triggers. It sets key[1] = 1+1=2, marks key[0]=-1, and updates x1[1]=x1[0]=12, y1[1]=y1[0]=12. So x1[ans1]=12,y1[ans1]=12 and ans=2, which matches expected output. However, the debug printf inside the loop causes extra output ("2\n") before the final answer, leading to wrong output format. The problem requires only one line of output, but the program prints intermediate values.]
    return 0;
}