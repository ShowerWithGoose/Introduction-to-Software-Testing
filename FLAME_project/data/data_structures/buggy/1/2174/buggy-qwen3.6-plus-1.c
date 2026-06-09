#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < p; j++) { // @@ The loop bound should be p (the number of elements in the permutation), not 10. Using 10 prints garbage or extra characters when p < 10, and fails to print correctly if p > 10 (though p<=10 here). Specifically for N=1, it prints 1 followed by 9 null/empty chars or previous memory content depending on initialization, but logically it must only print p characters.
            printf("%c", pailie[j]);
        }
        printf("\n");
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