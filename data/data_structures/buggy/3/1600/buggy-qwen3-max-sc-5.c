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

        int nonzero = dot + 1;
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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", the exponent should be -(nonzero - dot - 1), but here it's computed as dot - nonzero, which gives a positive value instead of negative. Also, the logic assumes input always starts with '0', but problem allows numbers like "123.45".]
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function incorrectly removes the decimal point but also has a bug: it skips copying the character at index 1 unconditionally (if i != 1), which corrupts the digit sequence. For example, in "12.34", it would skip '2' because i=1 when processing '2'.]
        putchar(s[nonzero]); // @@ [nonzero is still 0 from initialization, so this prints s[0], but after removeChar(), the string is modified and may not have the original digits in expected positions.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1;
            while (i < length && s[i] != '\0') {
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ [After removeChar(), the string length and digit positions are altered, so using original 'dot' to compute exponent is invalid. Also, if there was no decimal point (dot == length), this would print e(length-1), but the logic doesn't handle pure integers correctly per problem spec.]
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}