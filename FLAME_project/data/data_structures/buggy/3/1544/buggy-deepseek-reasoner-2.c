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
        printf("%c",input[dian]);
        if(dian<strlen(input)-1) printf(".");
        zhishu=dian-1;
        for(int k=dian+1; input[k] != '\0'; k++) {
            printf("%c",input[k]);
        }
        printf("e-%d",zhishu);
    } else {
        printf("%c.",input[0]);
        for(int l=1; (input[l] != '\0')&&(input[l] != '.'); l++) { // @@ This loop only prints digits before the decimal point. Scientific notation base must include all digits (excluding leading zeros), so a subsequent loop to print digits after the decimal point is missing. As a result, digits after the decimal are omitted, causing the output to be truncated (e.g., "8.7899e4" instead of "8.78999999999999000999e4").
            printf("%c",input[l]);
        }
        zhishu=point_pos-1;
        printf("e%d",zhishu);
    }

    return 0;
}