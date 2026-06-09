#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]); // @@ [The initial input reads the first number and operator, but if the expression starts with a negative number or has leading spaces, this may fail. However, the main issue is that the loop condition checks pnt[1] != '=' before any '=' is read, and the structure doesn't handle the final '=' correctly as in the reference program. Also, unlike the reference, this code does not initialize the first operator properly for accumulation.]
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ [This assumes there's always another number and operator after the first, which fails when the next token is '='. For example, in "5 =", after reading 5 and '=', pnt[1] becomes '=', so the loop wouldn't run—but here, the first read already consumes the '=' into pnt[1], yet the logic mismatches the reference. More critically, if the expression ends right after a term (e.g., "5 ="), this second scanf tries to read beyond the '=' and causes undefined behavior.]
        while (pnt[2] == '*' || pnt[2] == '/') {
            scanf("%d %c", &num[3], &pnt[3]);
            if (pnt[2] == '*') {
                num[2] = num[2] * num[3];
            } else if (pnt[2] == '/') {
                num[2] = num[2] / num[3];
            }
            pnt[2] = pnt[3];
        }
        if (pnt[1] == '+') {
            num[1] = num[1] + num[2];
        } else if (pnt[1] == '-') {
            num[1] = num[1] - num[2];
        }
        pnt[1] = pnt[2];
    }

    printf("%d", num[1]);
    return 0;
}