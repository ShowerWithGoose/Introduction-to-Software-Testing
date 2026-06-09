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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect: for numbers like "0.00123", dot=1, nonzero=4, so dot - nonzero = -3, but it should be -(nonzero - dot - 1) = -3, however the sign is wrong because it prints e-3 as e3 due to missing minus sign. Also, the formula itself is flawed.]
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function modifies the original string by removing '.', but also incorrectly skips copying the character at index 1 (due to 'if (i != 1)'), which corrupts the number. For example, "12.34" becomes "134" instead of "1234".]
        putchar(s[nonzero]); // @@ [nonzero is always 0 here, but after removeChar(), s[0] may still be correct, however the logic assumes nonzero=0 but doesn't ensure that. Also, if the number has more than one digit before decimal, we should only output the first digit followed by '.' and others, but this code doesn't handle that correctly.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1;
            while (i < length && s[i] != '\0') { // @@ [After removeChar(), the string length and content are changed, but 'length' still holds the original length, leading to reading beyond the modified string or including garbage. Also, the loop condition should use the new length.]
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ [For input like "123.45", dot=3, so exponent=2 which is correct, but if the input is "1.23", dot=1, exponent=0, which is correct. However, if the input has no decimal point, dot=length, so exponent=length-1, which is correct. BUT: the removeChar() corruption may have already broken the string, making this unreliable. Also, the problem requires no trailing zeros, but this code doesn't remove them.]
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}