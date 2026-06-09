#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
bool used[15]; // @@ 'bool' type and 'true'/'false' macros are not defined in standard C without including <stdbool.h>
int pailie[15]; 
void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", pailie[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
void ans(int pos, int n) {
    if (pos == n) {
        print(n);
        return;
    }
    for (int num = 1; num <= n; num++) {
        if (used[num]==false) {
            used[num] = true; 
            pailie[pos] = num; 
            ans(pos + 1, n);
            used[num] = false;
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
        used[i] = false;
        pailie[i] = 0;
    }
    ans(0, N);

    return 0;
}