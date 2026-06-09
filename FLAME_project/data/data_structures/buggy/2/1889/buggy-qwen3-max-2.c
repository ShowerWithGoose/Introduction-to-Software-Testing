#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]); // @@ [Initial parsing assumes first token is number followed by operator, but doesn't handle leading spaces or initial state correctly for complex expressions]
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ [This reads next number and operator unconditionally, which skips handling of consecutive * or / at the very beginning of the expression after the first term]
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

    printf("%d", num[1]); // @@ [The final result is stored in num[1], but the algorithm fails to correctly accumulate results when multiple high-precedence operations occur after a low-precedence operator due to incorrect grouping and left-to-right evaluation without proper precedence handling across entire expression]
    return 0;
}