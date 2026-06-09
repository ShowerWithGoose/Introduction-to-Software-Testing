#include <stdio.h>
char ch[1000], a = '+', b = '+', k;
int i, j, sum1, sum2, flag1, num;
int main()
{
    gets(ch);
    int len = strlen(ch);
    for (i = 0; i < len; i++)
    {
        //判断读取到的是数字还是字符
        if (ch[i] <= '9' && ch[i] >= '0')
            flag1 = 1;
        else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '=')
            flag1 = 0;
        else
            continue;
        //将字符记录出来
        if (flag1 == 1)
            num = num * 10 + ch[i] - '0';
        else
            a = b, b = ch[i];

        //计算
        if (flag1 == 0)
        {
            if (b == '+' || b == '-' || b == '=')
            {
                if (a == '+')
                    sum2 = num, num = 0, sum1 += sum2;
                if (a == '-')
                    sum2 = num, num = 0, sum1 -= sum2;
                if (a == '*' && k == '+')
                    sum2 *= num, num = 0, sum1 += sum2;
                if (a == '*' && k == '-')
                    sum2 *= num, num = 0, sum1 -= sum2;
                if (a == '/' && k == '+')
                    sum2 /= num, num = 0, sum1 += sum2;
                if (a == '/' && k == '-')
                    sum2 /= num, num = 0, sum1 -= sum2;
            }
            if (b == '*' || b == '/')
            {
                if (a == '+' || a == '-')
                    k = a, sum2 = num, num = 0;
                if (a == '*')
                    sum2 *= num, num = 0;
                if (a == '/')
                    sum2 /= num, num = 0;
            }
        }
    }
    printf("%d", sum1);
    return 0;
}

