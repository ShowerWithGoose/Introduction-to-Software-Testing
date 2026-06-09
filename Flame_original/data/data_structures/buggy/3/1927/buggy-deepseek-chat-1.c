#include <stdio.h>
#include <string.h>


int main() {
    char s[1025] = {0};

    gets(s); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not standard in C11. Use fgets() instead.]
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
        if (s[0] != '0') {
            printf("%se0", s); // @@ [For numbers like 0.5, this branch incorrectly prints "0.5e0" instead of "5e-1". The logic for handling numbers less than 1 but with a non-zero first digit (which is impossible since first digit is '0') is flawed.]
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
        if (op == 0) {
            printf(".\n1"); // @@ [This prints a newline and '1' incorrectly. It should not print a newline, and the logic for handling trailing zeros is wrong.]
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