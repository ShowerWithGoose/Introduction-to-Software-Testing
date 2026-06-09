#include <stdio.h>
#include <string.h>


int main() {
    char s[1025] = {0};

    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
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
            printf("%se0", s); // @@ [This prints the entire original string followed by 'e0', which violates the scientific notation format requirement. For example, input "5.3" would output "5.3e0", but correct output should be "5.3e0" only if it matches the required base format — however, more critically, if input is "7", it outputs "7e0", which is acceptable, but if input is "12.3", this branch won't trigger. However, the real issue here is that this branch assumes any non-zero single-digit before decimal is already in normalized form, but it doesn't remove trailing zeros or ensure exactly one digit before decimal. But the immediate compilation error is due to 'gets'.]
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
            printf(".\n1"); // @@ [This prints a newline and '1', which is completely incorrect. It should print a '.' followed by significant digits, not a newline and hardcoded '1'. This will produce malformed output like "1.\n1e2" instead of "1.23e2". However, this is a logic error, not a compilation error. The primary compilation error remains 'gets'.]
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