#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
bool used[15]; // @@ [Error: 'bool' type requires #include <stdbool.h>. Missing header causes compilation error.]
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
        if (used[num]==false) { // @@ [Error: 'false' undeclared due to missing <stdbool.h>.]
            used[num] = true; // @@ [Error: 'true' undeclared due to missing <stdbool.h>.]
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
        used[i] = false; // @@ [Error: 'false' undeclared due to missing <stdbool.h>.]
        pailie[i] = 0;
    }
    ans(0, N);

    return 0;
}