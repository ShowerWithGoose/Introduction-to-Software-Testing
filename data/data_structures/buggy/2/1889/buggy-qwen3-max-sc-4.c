#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]); // @@ [Initial input reads the first number and operator, but if the expression starts with a negative number or has leading spaces, this may fail; more critically, the logic does not handle the final '=' correctly because it expects an operator after every number, including the last one before '=', which violates input format assumptions.]
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ [This assumes that after the first token, every number is followed by an operator or '=', but if the expression ends right after a number (e.g., "5 ="), this read will attempt to read beyond the '=' or fail to parse correctly. Also, the use of fixed indices like num[2], num[3] limits the expression length and breaks on longer expressions.]
        while (pnt[2] == '*' || pnt[2] == '/') {
            scanf("%d %c", &num[3], &pnt[3]); // @@ [Same issue: hardcoded index num[3] cannot handle multiple consecutive * or / operations beyond one level; also, if the next token after a * or / is '=', this reads past the end or misinterprets '=' as an operator.]
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