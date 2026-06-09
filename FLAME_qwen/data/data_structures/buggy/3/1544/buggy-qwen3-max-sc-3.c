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
    if ((point_pos == -1)||((input[0]!='0')&&(point_pos == 1))) { @@ [逻辑错误：当输入为整数（无小数点）或形如 "5.0"（但题目保证无尾随零）时直接输出原样加"e0"，但未处理如 "123" 应转为 "1.23e2" 的情况；此外，条件 (input[0]!='0')&&(point_pos == 1) 错误地将如 "5.123" 视为无需转换，而实际上应转换为科学计数法]
        printf("%se0\n", input);
    } else if(input[0]=='0') {
        for(int j=2; input[j] != '\0'; j++) { @@ [潜在未初始化使用：若输入为 "0.0"（但题目说无尾随零，所以最小是 "0.1"），但若输入为 "0."（非法但可能），则 dian 未被赋值就使用]
            if(input[j]!='0') {
                dian=j;
                break;
            }
        }
        printf("%c",input[dian]); @@ [错误：dian 可能未初始化，若输入为 "0."（虽然题目说有数字在小数点后），但程序未确保找到非零数字]
        if(dian<strlen(input)-1) printf(".");
        zhishu=dian-1;
        for(int k=dian+1; input[k] != '\0'; k++) {
            printf("%c",input[k]);
        }
        printf("e-%d",zhishu);
    } else {
        printf("%c.",input[0]);
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) { @@ [错误：此循环会输出所有小数点前的剩余数字，但科学计数法要求只保留一位整数部分，其余应作为小数部分；例如 "123.45" 应输出 "1.2345e2"，但此代码输出 "1.23e2" —— 实际上这里输出了 "1.23" 而不是 "1.2345"，因为循环在遇到 '.' 停止，但未继续输出小数部分]
            printf("%c",input[l]);
        }
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}