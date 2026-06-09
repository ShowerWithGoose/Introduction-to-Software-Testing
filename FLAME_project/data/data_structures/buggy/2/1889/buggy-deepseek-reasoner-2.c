#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]);
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ [Error: This reads the next number and operator without first handling the case when pnt[1] is '*' or '/'. The chain of * and / should be processed immediately with the first number, not separately. This leads to incorrect left-associative evaluation.]
        while (pnt[2] == '*' || pnt[2] == '/') { // @@ [Error: The condition should be on pnt[1] to handle the chain starting from the first operator. Using pnt[2] only handles the second operator's chain, causing the first operator to be applied later without proper left-associative grouping.]
            scanf("%d %c", &num[3], &pnt[3]);
            if (pnt[2] == '*') {
                num[2] = num[2] * num[3];
            } else if (pnt[2] == '/') {
                num[2] = num[2] / num[3];
            }
            pnt[2] = pnt[3];
        }
        if (pnt[1] == '+') { // @@ [Error: Missing handling for cases when pnt[1] is '*' or '/'. As a result, those operations are never performed, leading to incorrect results.]
            num[1] = num[1] + num[2];
        } else if (pnt[1] == '-') { // @@ [Error: Same as above: missing else cases for '*' and '/'.]
            num[1] = num[1] - num[2];
        }
        pnt[1] = pnt[2];
    }

    printf("%d", num[1]);
    return 0;
}