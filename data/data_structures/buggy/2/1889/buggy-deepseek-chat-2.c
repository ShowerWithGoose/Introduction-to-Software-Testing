#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'}; // @@ The array is initialized with only one element, but the rest are zero-initialized. However, pnt[1] is not explicitly set, so it may be '\0', causing the first scanf to read into pnt[1] correctly, but the initial pnt[1] is not '+' as intended. The reference program uses f1='+' before the loop, but here pnt[1] is not set to '+', so the first iteration may behave incorrectly.
    scanf("%d %c", &num[1], &pnt[1]); // @@ The array indices start at 1, but the arrays are size 5, so indices 0-4 are valid. Using index 1 is okay but wastes index 0. More critically, the first scanf reads into num[1] and pnt[1], but pnt[1] was not initialized to '+', so the loop condition pnt[1] != '=' may fail if the first operator is not '='. However, the main issue is that the initial pnt[1] is not set to '+', so the first operation (addition or subtraction) will not be performed correctly because the if-else checks pnt[1] which is not '+' initially.
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ This reads the next number and operator, but the first number and operator were already read before the loop. This pattern is different from the reference program, which reads inside the loop. Here, the first read is outside, then inside the loop it reads again, which may skip or misread input. The reference program reads s2 and f2 inside the outer while loop, but here the first read is outside, causing the loop to process the first pair incorrectly.
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