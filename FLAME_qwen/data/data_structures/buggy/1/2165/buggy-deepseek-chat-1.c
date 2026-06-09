#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
bool used[15]; // @@ Error: In C, 'bool' is not a standard type. Use '_Bool' or include <stdbool.h> and use 'bool' correctly, or use 'int' instead.
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
        if (used[num]==false) { // @@ Error: 'used' is declared as 'bool' which is not standard C without <stdbool.h>. Also, 'false' is not defined.
            used[num] = true; // @@ Error: 'true' is not defined in standard C without <stdbool.h>.
            pailie[pos] = num; 
            ans(pos + 1, n);
            used[num] = false; // @@ Error: 'false' is not defined.
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
        used[i] = false; // @@ Error: 'false' is not defined.
        pailie[i] = 0;
    }
    ans(0, N);

    return 0;
}