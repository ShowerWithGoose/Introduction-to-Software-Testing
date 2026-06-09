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
    if ((point_pos == -1)||((input[0]!='0')&&(point_pos == 1))) {
        printf("%se0\n", input);
    } else if(input[0]=='0') {
        for(int j=2; input[j] != '\0'; j++) {
            if(input[j]!='0') {
                dian=j;
                break;
            }
        }
        printf("%c",input[dian]); // @@ [未初始化'dian'变量可能导致未定义行为：如果输入是"0.0"或类似全零小数部分，循环不会执行，'dian'保持未初始化]
        if(dian<strlen(input)-1) printf("."); // @@ [同上，使用未初始化的'dian'会导致错误]
        zhishu=dian-1; // @@ [同上，'dian'可能未初始化]
        for(int k=dian+1; input[k] != '\0'; k++) {
            printf("%c",input[k]);
        }
        printf("e-%d",zhishu);
    } else {
        printf("%c.",input[0]);
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) {
            printf("%c",input[l]);
        }
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}