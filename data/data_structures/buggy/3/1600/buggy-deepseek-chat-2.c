#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void removeChar(char str[]) {
    int length = strlen(str);
    int i, j = 0;

    // 遍历原始字符串
    for (i = 0; i < length; i++) {
        // 如果当前字符不是要删除的字符，则将其保留在新字符串中
        if (str[i] != '.') {
            if (i != 1)
                str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void notation(char s[]) {
    int length = strlen(s);
    int i = 0;
    int dot = 0;
    int nonzero = 0;
    if (s[0] == '0') {
        //小数
        while (s[i] != '.') {
            dot++;
            i++;
        }

        int nonzero = dot + 1; // @@ 重新声明了局部变量 nonzero，隐藏了外部的 nonzero，导致外部的 nonzero 始终为 0
        while (s[nonzero] == '0') {
            nonzero++;
        }
        printf("%c", s[nonzero]);
        i = nonzero + 1;

        putchar('.');
        while (s[i] != '\0') {

            putchar(s[i]);
            i++;
        }
        printf("e%d\n", dot - nonzero ); // @@ 这里 dot - nonzero 计算的是小数点位置与第一个非零数字位置的差值，但符号错误，应为 nonzero - dot
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ 调用 removeChar 后，s 被修改，小数点被移除，但后续代码仍依赖原字符串中的小数点位置
        putchar(s[nonzero]); // @@ nonzero 始终为 0，这里输出的是 s[0]，但 removeChar 后 s[0] 可能不是正确的第一个数字

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1; // @@ 同样 nonzero 为 0，且 removeChar 后字符串已改变，循环逻辑错误
            while (i < length && s[i] != '\0') {
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ 指数计算错误，应为 dot - 1 但未考虑 removeChar 后的影响
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}