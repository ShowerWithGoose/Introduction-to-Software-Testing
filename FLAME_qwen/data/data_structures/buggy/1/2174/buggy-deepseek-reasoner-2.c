#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) { // @@ Should iterate up to p (the permutation length) and include spaces between numbers.
            printf("%c", pailie[j]);
        }
        printf("\n"); // @@ Missing return; function should stop here.
    }
    for (int i = 1; i <= p; i++) {
        if (flag[i] == 0) {
            flag[i] = 1;
            pailie[m] = '0' + i;
            quan(m + 1, n - 1);
            flag[i] = 0;
        }
    }
    return ;
}

int main() {
    scanf("%d", &p);
    quan(0, p);
    return 0;
}