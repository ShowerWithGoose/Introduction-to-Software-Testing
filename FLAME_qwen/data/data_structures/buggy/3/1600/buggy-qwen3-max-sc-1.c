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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect: for numbers like "0.00123", dot=1, nonzero=4, so dot - nonzero = -3, but it should be -(nonzero - dot) = -3; however, the sign is wrong because it prints e-3 as e-3 but here it prints e-3 as e-3 with a negative number without '-' sign. Actually, the expression dot - nonzero is negative, so it prints e-3 correctly in value but the logic is confusing and inconsistent with cases where first digit is after decimal. However, more critically, if the input is "0.1", then dot=1, nonzero=2, dot-nonzero=-1, so output is e-1 which is correct. But the real issue is that this branch assumes s[0]=='0' implies the number is less than 1, which is true per problem constraints, but the exponent formula is dot - nonzero, which equals -(nonzero - dot), and since nonzero > dot, this is negative, so printing e%d will show e-1 etc., which is correct format. So maybe not the main bug.]

    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function modifies the original string by removing '.', but also has a bug: it skips copying the character at index 1 if it's not '.', due to 'if (i != 1)'. This corrupts the string. For example, input "123.45" becomes "1345" instead of "12345".]

        putchar(s[nonzero]); // @@ [nonzero is initialized to 0 earlier, but after removeChar(), s may be corrupted. Also, if the original number was "100.0", but per problem there are no trailing zeros, so maybe not an issue, but the use of 'nonzero' variable here is misleading—it's always 0, so it prints s[0], which might be correct only if removeChar() worked properly.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1; // @@ [Again, using 'nonzero' (which is 0) so i=1, but after removeChar(), the string is corrupted, so s[1] may not correspond to the correct digit.]
            while (i < length && s[i] != '\0') {
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ [This exponent is correct for numbers >=1: e.g., "123.45" -> dot=3, exponent=2, which is correct (1.2345e2). But due to corruption from removeChar(), the base part is wrong.]
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}