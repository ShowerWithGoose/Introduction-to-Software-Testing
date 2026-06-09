#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
bool used[15]; @@ // error: unknown type name ‘bool’ because <stdbool.h> is not included
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
        if (used[num]==false) { @@ // error: ‘false’ undeclared because <stdbool.h> is not included
            used[num] = true; @@ // error: ‘true’ undeclared because <stdbool.h> is not included
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
        used[i] = false; @@ // error: ‘false’ undeclared because <stdbool.h> is not included
        pailie[i] = 0;
    }
    ans(0, N);

    return 0;
}