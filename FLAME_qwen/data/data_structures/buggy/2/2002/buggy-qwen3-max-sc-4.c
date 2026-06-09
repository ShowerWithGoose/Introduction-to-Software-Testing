#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*思路：计算两个加减之间乘除的个数，先算乘除再算加减*/
void chu_kong_ge(char* expression, char* result);//除空格
long long ji_suan(long long a, long long b, char op);//计算加减乘除

int main() {
    char expression[1000], temp[1000] = "\0";
    gets(expression); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. However, the immediate error is that the program never handles expressions that start with a number without any preceding operator, and more critically, the logic for parsing and evaluating the expression is flawed—especially when the expression starts with a number or contains only multiplication/division. Additionally, the variable `jie_guo` is initialized to 0, so if the first token is a multi-digit number, it accumulates correctly in the `else` block, but if the expression begins with an operator (which it shouldn't per problem statement), it would fail. However, the core issue causing incorrect evaluation is that the program does not correctly parse numbers before the first operator. But the compilation error mentioned in the test case ("gcc: not found") is environmental, not code-related. However, the actual logical errors include: (1) The program assumes that encountering '+' or '-' triggers processing of the next segment, but if the expression starts with a number (e.g., "5 - 1..."), the initial number is read in the final `else` clause, which is correct. However, the bigger flaw is in the handling of pure multiplication/division expressions (e.g., "2*3/2="). In such cases, the first `if` (for '+'/'-') is skipped, and it goes to `else if (* or /)`. Inside that block, when parsing the first number, it uses `for (j = 0; ...)` which re-parses from the beginning of the string every time, leading to incorrect number extraction. This causes wrong results. Also, the index `i` is modified inside loops in complex ways, leading to skipped characters or infinite loops. But since the problem states the error type is "Compilation Error", yet the provided output is "/bin/sh: 1: gcc: not found", which is not a code error but a missing compiler, we must assume the real issue is logical. However, per instructions, we mark lines with logical/semantic errors that cause wrong output. The critical error is in the `else if (temp[i] == '*' || temp[i] == '/')` block where it tries to parse the first number from index 0 regardless of current position, which is wrong.]
    chu_kong_ge(expression, temp);//已经除去空格

    int len = strlen(temp);
    long long jishu = 0; char op[1000] = "\0";
    long long jie_guo = 0;
    long long number_before = 0, number_after = 0;//乘除符号左右两边的数

    for (int i = 0; i < len; i++) {
        if (temp[i] == '+' || temp[i] == '-') {
            op[i] = temp[i];
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i + 1; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            if (jishu == 0)//连加或连减
            {
                int j;
                number_before = jie_guo;
                for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                jie_guo = ji_suan(number_before, number_after, op[i]);

                i = j - 1;//i在这里变了
                number_after = 0;
            }

            else if (jishu)//中间有乘除
            {
                long long j, count = jishu, cheng_chu_result = 0, k = i;

                while (jishu--) //乘除内运算
                {
                    if (jishu == count - 1) //第一次需要先对num_before赋值
                    {
                        for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                            number_before = number_before * 10 + temp[j] - '0';
                        }
                    }
                    i = j;//i在这里变了,为了更新op[i]
                    op[i] = temp[j];
                    for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                        number_after = number_after * 10 + temp[j] - '0';
                    }
                    cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                    i = j;
                    op[i] = temp[j];

                    number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                    number_after = 0;
                }

                jie_guo = ji_suan(jie_guo, number_before, op[k]);
                i = j - 1;
                number_before = 0;

            }
        }

        else if (temp[i] == '*' || temp[i] == '/') {
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            long long j, count = jishu, cheng_chu_result = 0, k = i;

            while (jishu--) //乘除内运算
            {
                if (jishu == count - 1) //第一次需要先对num_before赋值
                {
                    for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) { // @@ [This loop always starts from index 0, which is incorrect. It should start from the current parsing position (e.g., after the last processed number), not the beginning of the string. This causes the program to re-read the entire expression from the start when processing multiplication/division at the beginning, leading to wrong number extraction and incorrect results.]
                        number_before = number_before * 10 + temp[j] - '0';
                    }
                }
                i = j;//i在这里变了,为了更新op[i]
                op[i] = temp[j];
                for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                i = j;
                op[i] = temp[j];

                number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                number_after = 0;
            }

            jie_guo = number_before;
            i = j - 1;
            number_before = 0;
        }
        else if (temp[i] == '=') {
            printf("%lld", jie_guo);
        }
        else //出现数字
        {
            jie_guo = jie_guo * 10 + temp[i] - '0';
        }
    }
    return 0;
}

void chu_kong_ge(char* expression, char* result) {
    long long i = 0;
    long long j = 0;
    while (expression[i]) {
        if (expression[i] != ' ') {
            result[j++] = expression[i];
        }
        i++;
    }
    result[j] = '\0';
}

long long ji_suan(long long a, long long b, char op) {
    long long result = 0;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}