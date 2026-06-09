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
            printf("%se0", s); // @@ [This prints the entire original string followed by "e0", which violates the scientific notation format requirement. For example, input "5.3" would output "5.3e0", but correct output should be "5.3e0" only if allowed; however, per problem description, if there's more than one digit before decimal, it must be normalized. But here, since i==1 and s[0]!='0', it implies input like "5" or "5." — but "5." should become "5e0", not "5.e0". Also, this branch doesn't handle trailing zeros or proper normalization. However, the primary compilation error stems from 'gets'.]
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
            printf(".\n1"); // @@ [This prints a newline and '1', which is clearly wrong. It should print a '.' followed by significant digits, not a newline and hardcoded '1'. This is a logical error, but not the cause of the compilation error.]
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