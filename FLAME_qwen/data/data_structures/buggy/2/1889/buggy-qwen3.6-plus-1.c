#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'}; // @@ The initialization only sets pnt[0] to '+', leaving pnt[1] (which acts as the pending operator f1) as '\0'. It should initialize pnt[1] to '+'.
    scanf("%d %c", &num[1], &pnt[1]); // @@ This reads the first operator into pnt[1], overwriting the initial '+'. It causes the program to fail when the first operator is '*' or '/', as the if-else block only handles '+' and '-'. The first number should be read into num[2] inside the loop to match the reference logic.
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