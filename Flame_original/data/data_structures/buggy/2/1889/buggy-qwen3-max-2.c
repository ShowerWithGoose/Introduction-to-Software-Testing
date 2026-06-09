#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]); @@ [The initial input reads into num[1] and pnt[1], but if the first token is negative (e.g., "-5 + 3 ="), this fails because scanf expects a number first. Also, the logic assumes the expression starts with a number, but doesn't handle leading operators correctly. However, more critically, the program structure mismatches operator precedence handling compared to the reference: it uses fixed array indices which break when multiple * or / operations occur in sequence beyond one level.]
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); @@ [This assumes that after the first number and operator, every next token is a number followed by an operator. However, if the expression ends immediately after a number (before '='), this scanf will wait for extra input or fail. Also, using fixed indices like num[2], num[3] prevents handling arbitrary-length expressions with multiple * or / chains.]
        while (pnt[2] == '*' || pnt[2] == '/') {
            scanf("%d %c", &num[3], &pnt[3]); @@ [This only allows one level of nested multiplication/division. If there are more than two operands in a * or / chain (e.g., 2*3*4), it fails because num[3] and pnt[3] are overwritten without looping properly through all terms. The reference program uses a loop that continues until the next operator is not * or /, but this version only handles one extra operand.]
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