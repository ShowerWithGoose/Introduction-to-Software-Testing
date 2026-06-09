#include<stdio.h>
int main() {
    int n;
    while (scanf("%d", &n)==1) {
        printf("%d ", n); // @@ [The program simply prints every input integer as it reads it, without implementing any stack logic. It does not differentiate between operation codes (1, 0, -1) and data values, nor does it simulate push/pop operations or handle stack underflow/overflow. For the input "1 567 0 -1", it outputs all four numbers instead of only the popped value "567".]
    }
    return 0;
}