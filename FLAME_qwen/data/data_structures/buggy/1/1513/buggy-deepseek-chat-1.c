#include <stdio.h>
void f(int[], int[], int, int);





int mark[100] = {0}, pl[100] = {0};

int main() {
    int num;
    scanf("%d", &num);
    f(pl, mark, num, num);
    return 0;
}

void f(int pl[], int mark[], int num, int n) {
    if (n == 0) {
        for (int i = 0; i < num; i++) {
            printf("%d", pl[i]); // @@ Missing space between numbers in output; should be "%d " to match expected format.
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < num; i++) { // @@ Loop should iterate from 1 to num (i.e., i = 1; i <= num) to generate permutations of numbers 1..N, not indices 0..num-1.
        if (mark[i] == 0) {
            mark[i] = 1;
            pl[num - n] = i + 1;
            f(pl, mark, num, n - 1);
            mark[i] = 0;
        }
    }

}