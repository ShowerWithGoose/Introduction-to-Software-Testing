#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]);
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]);
        while (pnt[2] == '*' || pnt[2] == '/') {
            scanf("%d %c", &num[3], &pnt[3]);
            if (pnt[2] == '*') {
                num[2] = num[2] * num[3];
            } else if (pnt[2] == '/') {
                num[2] = num[2] / num[3];
            }
            pnt[2] = pnt[3];
        }
        if (pnt[1] == '+') { // @@ The code only handles '+' and '-' here, but the operator could be '*' or '/', which should be processed as part of the multiplication/division chain. The correct logic should also apply '*' and '/' to combine num[1] and num[2], treating them similarly to how the inner while handles consecutive multiplications/divisions.
            num[1] = num[1] + num[2];
        } else if (pnt[1] == '-') { // @@ Same issue: missing handling for '*' and '/'. These cases must be included to correctly evaluate expressions like "1 * 2 =". In such cases, the code currently skips the operation and prints the first number unchanged.
            num[1] = num[1] - num[2];
        }
        pnt[1] = pnt[2];
    }

    printf("%d", num[1]);
    return 0;
}