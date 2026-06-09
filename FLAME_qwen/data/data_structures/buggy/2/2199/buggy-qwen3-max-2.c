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
}
int main()
{
    char yuan[256];
    char buffer[256] = {0};
    int i, j = 0;
    int num1 = 0, num2 = 0, num3 = 0;
    char o1 = 0, o2 = 0;
    int result = 0;
    // 读取整行表达式
    gets(yuan); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to a compilation error. Use 'fgets' instead.]
    // 去除表达式中的所有空格
    for (i = 0; yuan[i] != '\0'; i++)
    {
        if (yuan[i] != ' ')
        {
            buffer[j++] = yuan[i];
        }
    }

    // 初始化数值和运算符
    sscanf(buffer, "%d", &num1);
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
                num1 = cal(num2, num3, o2);
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