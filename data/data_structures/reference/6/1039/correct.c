#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0, stack[105] = {0};
    long int temp;
    char in[1000];
    gets(in);

    char* pc = in;
    for (;;) {
        temp = strtol(pc, &pc, 0);
        *pc++;
        switch (temp) {
            case 1:
                if (n <= 100) {
                    stack[n] = (int)strtol(pc, &pc, 0);
                    n++;
                }  //
                else {
                    strtol(pc, &pc, 0);
                    printf("error ");
                }
                *pc++;
                break;
            case 0:
                if (n > 0) {
                    printf("%d ", stack[n - 1]);
                    n--;
                }  //
                else {
                    printf("error ");
                }
                break;
            case -1:
                return 0;
        }
    }
}
