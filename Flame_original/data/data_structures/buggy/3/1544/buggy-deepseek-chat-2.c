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
    if ((point_pos == -1)||((input[0]!='0')&&(point_pos == 1))) { // @@ 错误：当输入为整数（无小数点）或形如"a.b"（a非0且只有一位整数）时，直接输出原数加"e0"，但题目要求科学计数法必须将数字标准化，例如输入"12.34"应输出"1.234e1"，此处逻辑错误
        printf("%se0\n", input);
    } else if(input[0]=='0') {
        for(int j=2; input[j] != '\0'; j++) { // @@ 错误：当输入为"0.xxx"时，从索引2开始查找第一个非零数字，但若输入为"0.0"或"0.00"等，循环可能找不到非零数字，导致dian未初始化，且未处理输入为"0"的情况
            if(input[j]!='0') {
                dian=j;
                break;
            }
        }
        printf("%c",input[dian]); // @@ 错误：如果输入为"0.0"或"0.00"，dian可能未初始化，导致未定义行为；且若输入为"0"，程序会直接访问未初始化的dian
        if(dian<strlen(input)-1) printf("."); // @@ 错误：当dian为最后一个字符时，不应输出小数点，但此处条件判断可能错误，例如输入"0.5"时dian=2，strlen=3，条件成立正确；但若输入"0.05"，dian=3，strlen=4，条件成立，但输出应为".5"？实际应为"5e-2"，此处逻辑不完整
        zhishu=dian-1;
        for(int k=dian+1; input[k] != '\0'; k++) {
            printf("%c",input[k]);
        }
        printf("e-%d",zhishu);
    } else {
        printf("%c.",input[0]); // @@ 错误：当输入形如"12.34"时，point_pos=2，此处输出第一位数字和小数点，但未处理小数点后的数字，且后续循环从l=1开始跳过小数点，但输出中缺少了小数点后的数字，导致输出不完整
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) { // @@ 错误：此循环只输出到小数点前，但小数点后的数字未被输出，且输出格式应为"1.234e1"，此处缺少小数点后的数字
            printf("%c",input[l]);
        }
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}