#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char input[101]; // 输入字符串，最多100个字符
    fgets(input, sizeof(input), stdin); // 从标准输入读取一行

    // 去除输入字符串末尾的换行符
    input[strcspn(input, "\n")] = 0;

    int point_pos = -1; // 小数点的位置
    int i;
    int dian,zhishu;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            point_pos = i;
            break;
        }
    }
    if ((point_pos == -1)||((input[0]!='0')&&(point_pos == 1))) { // @@ 错误：条件 (point_pos == 1) 错误地处理了形如 "8.7899" 的情况，导致直接输出原字符串而不进行科学计数法转换。正确逻辑应处理所有非零开头且小数点不在第一位的情况，但这里错误地排除了小数点后有多位的情况。
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
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) { // @@ 错误：循环条件 (input[l] != '.') 导致遇到小数点就停止，但小数点后的数字没有被输出。正确做法是跳过小数点，继续输出小数点后的所有数字。
            printf("%c",input[l]);
        }
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}