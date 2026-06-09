#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int f(char a, char b) {
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b - a > 0) {
        return 1;
    } else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && b - a > 0) {
        return 1;
    } else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && b - a > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char s[1001];
    char *p = NULL, *pp = NULL;
    int i, j;
    gets(s);
    p = strchr(s, '-');
    if (p == NULL) {
        puts(s);
    } else {
        for (p = s; (pp = strchr(p, '-')) != NULL && (pp + 1) != NULL;) {
            if (f(*(pp - 1), *(pp + 1)) == 1) {
                for (i = 0; i < pp - p; i++) {
                    printf("%c", *(p + i));
                }
                for (i = 1; i <= *(pp + 1) - * (pp - 1); i++) {
                    printf("%c", *(pp - 1) + i);
                }
            } else {
                for (i = 0; i < pp - p + 2; i++) { // @@ 错误：应该打印从 p 开始的字符，而不是从 pp 开始，应使用 *(p + i)
                    printf("%c", *(pp + i));        // @@ 错误：同上，此处应为 *(p + i)
                }
            }
            p = pp + 2;                            // @@ 逻辑错误：在循环内提前打印剩余部分会导致重复输出，正确做法应在循环结束后统一打印
            for (i = 0; i < strlen(s) - (p - s); i++) { // @@ 逻辑错误：此段应移至 for 循环外部，否则每处理一个 '-' 都会重新打印剩余部分
                printf("%c", *(p + i));                 // @@ 逻辑错误：同上
            }
        }
    }
    return 0;
}