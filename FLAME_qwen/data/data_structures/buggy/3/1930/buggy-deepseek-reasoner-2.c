#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
    gets(w);
    int len_w = strlen(w);
    int y = 0, g = -1;
    for (int i = 0; i < len_w; i++) {
        if (w[i] != '.') {
            h[y] = w[i];
            y++;
        } else if (w[i] == '.') {
            g = i;
            g = g - 1;
        }
    }
    if (h[1] == '0') { // @@ 错误：应该判断 w[0]=='0'，否则对于如 0.1 的情形会错误进入 else 分支
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) {
            flag++;
        }
        while (h[i] != '\0') { // @@ 错误：缺少小数点。应先输出第一个非零数字，若后面还有数字则输出 '.'，再输出剩余数字
            printf("%c", h[i]);
            i++;
        }
        printf("e-");
        printf("%d", flag);
//完成了收个数为0的情况
    } else {
        printf("%c", h[0]);
        printf(".");
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g);
    }
}