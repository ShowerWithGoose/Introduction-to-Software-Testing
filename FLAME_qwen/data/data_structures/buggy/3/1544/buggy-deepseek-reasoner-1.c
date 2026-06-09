#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char input[101]; // 输入字符串，最多100个字符
    fgets(input, sizeof(input), stdin); // 从标准输入读取一行

    // 去除输入字符串末尾的换行符
    input[strcspn(input, "\n")] = 0;

    int point_pos = -1; // 小数点的位置
    int i; // used in for loop
    int dian,zhishu;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            point_pos = i;
            break;
        }
    }
    if ((point_pos == -1)||((input[0]!='0')&&(point_pos == 1))) {
        printf("%se0\n", input);
    } else if(input[0]=='0') {
        for(int j=2; input[j] != '\0'; j++) {
            if(input[j]!='0') {
                dian=j;
                break;
            }
        }
        printf("%c",input[dian]);
        if(dian<strlen(input)-1) printf(".");
        zhishu=dian-1;
        for(int k=dian+1; input[k] != '\0'; k++) {
            printf("%c",input[k]);
        }
        printf("e-%d",zhishu);
    } else {
        printf("%c.",input[0]);
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) { // @@ This loop stops at the decimal point, missing the fractional digits. It should continue through the decimal point to include all digits after the first.
            printf("%c",input[l]);
        } // @@ Missing code to print the fractional digits (those after the decimal point) after this loop. Currently only digits before the decimal point are output.
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}