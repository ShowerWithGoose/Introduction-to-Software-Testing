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

        int nonzero = dot + 1; // @@ [Variable 'nonzero' is redeclared in the same scope, causing a compilation error in C (shadowing not allowed in C89/C90 and may cause issues in strict C standards). Also, this hides the outer 'nonzero' variable which remains uninitialized.]
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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect: for input like "0.00123", dot=1, nonzero=4, so dot - nonzero = -3, but it should be -3, however due to logic errors earlier, this may not align. More critically, the format expects no '+' for non-negative, but negative must have '-', yet this prints e-3 as e-3 which is okay, but the value itself is wrong because dot - nonzero = 1 - 4 = -3, which is correct numerically, but the bigger issue is that the base printing assumes there are digits after the first non-zero, but if input ends right after, it may print extra '.' or nothing. However, the primary compilation error is the variable redeclaration above.]
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s);
        putchar(s[nonzero]); // @@ ['nonzero' was initialized to 0 at function start, but in this branch (s[0]!='0'), we never set 'nonzero' to a meaningful value. It remains 0, so this prints s[0], which might be okay, but the logic is flawed because 'nonzero' is unused correctly. Also, removeChar modifies the string by removing '.', but also skips copying the character at index 1 if it's not '.', which corrupts the number.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1; // @@ ['nonzero' is still 0, so i=1, but after removeChar, the string structure is broken, so accessing s[i] is unreliable.]
            while (i < length && s[i] != '\0') {
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1);
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}