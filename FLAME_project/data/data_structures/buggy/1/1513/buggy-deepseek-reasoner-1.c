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
            printf("%d", pl[i]); // @@ [The print statement does not include spaces between numbers. The expected output requires spaces between integers, e.g., "1 2" instead of "12".]
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < num; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            pl[num - n] = i + 1;
            f(pl, mark, num, n - 1);
            mark[i] = 0;
        }
    }

}