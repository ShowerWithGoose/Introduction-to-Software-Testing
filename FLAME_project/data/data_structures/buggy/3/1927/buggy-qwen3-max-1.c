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
        if (s[0] != '0') {
            printf("%se0", s); // @@ [This prints the entire original string including the decimal point, but scientific notation for numbers >=1 and <10 should just be the number itself without exponent adjustment; however, more critically, this branch doesn't handle trailing zeros or proper formatting. But the main bug is in the else branch below.]
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
            printf(".\n1"); // @@ [This prints a newline and "1", which is completely wrong. It should print a '.' followed by the remaining significant digits (excluding the decimal point), not a newline and hardcoded '1'. This causes the output to have an unexpected line break and incorrect digit sequence.]
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
            printf("%c", s[w]); // @@ [This loop prints digits after the first one, skipping the decimal point, but because of the earlier erroneous printf(".\n1"), the output is already corrupted. Also, this loop runs even when op==0 was true, leading to duplicate/misplaced digits.]
            w++;
        }
        printf("e%d", i - 1);
    }
    return 0;
}