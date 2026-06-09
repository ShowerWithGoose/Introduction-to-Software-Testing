#include <stdio.h>
#include <string.h>


int main() {
    char s[1025] = {0};

    gets(s);
    if (s[0] == '0' && strlen(s) == 1) {
        printf("0e0");
        return 0;
    }
    int i = 0;
    while (s[i] != '.') {
        if (i == strlen(s) - 1) {
            i++;
            break;
        }
        i++;

    }//统计小数点前面有几个数字
    if (i == 1) {//如果小于十
        if (s[0] == '0') {
            i++;
            int sum = 0;
            while (s[i] == '0') {
                sum++;
                i++;
            }
            printf("%c", s[i]);
            i++;
            if (i < strlen(s)) {
                printf(".");
            }
            while (i < strlen(s)) {

                printf("%c", s[i]);
                i++;
            }
            printf("e-%d", sum + 1);
        }//这里是小数和小于十的
        if (s[0] != '0') { // @@ 这里缺少 else，导致当 s[0] == '0' 时也会执行这个分支，输出错误
            printf("%se0", s);
        }
    } else {

        printf("%c", s[0]);
        int op = 1;
        for (int jud = 1; jud < strlen(s); jud++) {
            if (s[jud] != '0') {
                op = 0;

            }
        }
        //防止没有小数点的情况
        if (op == 0) { // @@ 这里条件判断错误，当 op == 0 时表示有非零数字，却输出 ".\n1"，逻辑反了
            printf(".\n1");
        }
        int w = 1;
        int y = strlen(s);//处理类似于100010的情况
        while (s[y - 1] == '0') {
            y--;
        }

        while (w < y) {
            if (s[w] == '.') {
                w++;
            }
            printf("%c", s[w]);
            w++;
        }
        printf("e%d", i - 1);
    }
    return 0;
}