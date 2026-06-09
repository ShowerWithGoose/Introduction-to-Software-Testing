#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) {
            printf("%c", pailie[j]);
        }
        printf("\n");
    } // @@ [The loop prints exactly 10 characters regardless of N, causing extra garbage output when N < 10. It should print only 'p' characters.]
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