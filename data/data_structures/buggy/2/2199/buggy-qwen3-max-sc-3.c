#include <stdio.h>
#include <string.h>
// #include <windows.h>

int cal(int x1, int x2, char op)
{
    switch (op)
    {
    case '+':
        return x1 + x2;
    case '-':
        return x1 - x2;
    case '*':
        return x1 * x2;
    case '/':
        return x1 / x2;
    default:
        return 0;
    }
}
int pan(char o)
{
    if (o == '+' || o == '-')
        return 1;
    else if (o == '*' || o == '/')
        return 2;
} // @@ [Function 'pan' is missing a return statement for invalid characters, but more critically, the logic in main assumes it returns consistent precedence values; however, the real issue is that this function returns 1 for low precedence and 2 for high, while typical precedence handling expects higher number = higher precedence — this is actually correct usage here, so not the main bug.]

int main()
{
    char yuan[256];
    char buffer[256] = {0};
    int i, j = 0;
    int num1 = 0, num2 = 0, num3 = 0;
    char o1 = 0, o2 = 0;
    int result = 0;
    // 读取整行表达式
    gets(yuan); // @@ [Use of 'gets' is dangerous and deprecated; however, the immediate error is that the program fails to handle expressions starting with a negative number, e.g., "-5 + 3 =", because sscanf reads num1 as 0 initially and parsing logic breaks. Also, 'gets' may cause compilation error in modern compilers due to removal from standard.]
    // 去除表达式中的所有空格
    for (i = 0; yuan[i] != '\0'; i++)
    {
        if (yuan[i] != ' ')
        {
            buffer[j++] = yuan[i];
        }
    }

    // 初始化数值和运算符
    sscanf(buffer, "%d", &num1); // @@ [This fails if the expression starts with '-', because buffer might be "-5+...", and %d can parse negative numbers, BUT the subsequent loop starts at i=0 and re-parses digits, leading to double consumption or misalignment. However, the bigger issue is the flawed state machine logic that only tracks up to two operators and three numbers, which cannot handle longer expressions like "1+2*3/4-5".]
    // 遍历处理每个字符
    for (i = 0; buffer[i] != '='; i++)
    {
        
        if ('0' <= buffer[i] && buffer[i] <= '9')
        {
            if (o1 == 0 && o2 == 0)
            {
                sscanf(&buffer[i], "%d", &num1);
                while (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
                    i++;
            }
            else if (pan(o1) == 2 && o2 == 0)
            {
                sscanf(&buffer[i], "%d", &num2);
                while (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
                    i++;
                num1 = cal(num1, num2, o1);
                num2 = 0;
                o1 = 0;
            }
            else if (pan(o1) == 1 && pan(o2) == 2)
            {
                sscanf(&buffer[i], "%d", &num3);
                while (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
                    i++;
                num1 = cal(num2, num3, o2); // @@ [Incorrect: should update num2 = cal(num2, num3, o2), not assign to num1. This overwrites num1 prematurely and loses the left part of the expression.]
                num3 = 0;
                o2 = 0;
            }
            else if (pan(o1) == 1 && pan(o2) == 1)
            {
                num1 = cal(num1, num2, o1);
                num2 = 0;
                o1 = o2;
                o2 = 0;
                sscanf(&buffer[i], "%d", &num2);
                while (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
                    i++;
            }
            else if (pan(o1) == 1 && o2 == 0)
            {
                sscanf(&buffer[i], "%d", &num2);
                while (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
                    i++;
            }
        }
        else
        {
            if (o1 != 0)
                o2 = buffer[i];
            else
                o1 = buffer[i];
        }
    }

    if (o1)
    {
        result = cal(num1, num2, o1);
    }
    else
    {
        result = num1;
    }
    printf("%d\n", result);
    // system("pause");
    return 0;
}