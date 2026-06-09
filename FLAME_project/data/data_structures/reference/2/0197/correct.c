#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//去空格
void squeeze(char[], char);
//读取数字和符号
int ReadNumber();
char ReadOperator();
//计算器
int claculate(int, int, char);
//优先级比较函数
int isprior(char, char);
//计数器(符号数目=要运算的数的数目)
/* int find(char s[])
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            n++;
    return n;
} */
//提取第k位的符号前的数
/* int PreNumber(char s[], int k)
{
    int data;
    for (int i = k - 1; i >= 0; i--)
        if (isdigit(s[i]))
            data = data + s[i] * pow(10, k - 1 - i);
    return data;
} */
//提取第k位后的数
/* int FolNumber(char s[], int k)
{
    int data = 0;
    for (int i = k; isdigit(s[i]); i++)
        data = data + s[i] * pow(10, i - k);
    return data;
} */

int pre;
char a[1005];
int main()
{

    //读取字符串
    gets(a);
    //初步处理（去掉空格）
    squeeze(a, ' ');
    int number[2];
    char operator[1];
    int nextNum;
    char nextOp;
    number[0] = ReadNumber();
    operator[0] = ReadOperator();
    if (operator[0] == '=')
    {
        printf("%d", number[0]);
        return 0;
    }
    else
        number[1] = ReadNumber();
    while (1)
    {

        if (operator[0] == '=')
        {
            printf("%d", number[0]);
            return 0;
        }
        //运算符是乘除，直接运算
        else if (operator[0] == '*' || operator[0] == '/')
        {
            number[0] = claculate(number[0], number[1], operator[0]);
            operator[0] = ReadOperator();
            number[1] = ReadNumber();
        }

        //运算符是加减
        else /* (operator[0] == '+' || operator[0] == '-') */
        {
            //判断下一个运算符优先级
            nextOp = ReadOperator();
            nextNum = ReadNumber();
            //不是=
            //下一个优先
            if (nextOp != '=' && isprior(nextOp, operator[0]))
            {
                number[1] = claculate(number[1], nextNum, nextOp);
            }
            //下一个非优先
            else if (nextOp != '=' && (!isprior(nextOp, operator[0])))
            {
                number[0] = claculate(number[0], number[1], operator[0]);
                operator[0] = nextOp;
                number[1] = nextNum;
            }
            else if(nextOp == '=')
            {
                printf("%d", claculate(number[0], number[1], operator[0]));
                return 0;
            }
        }
    }
    /* printf("%d", number[0]);
    return 0; */
}
//去空格
void squeeze(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
//读数
int ReadNumber()
{
    int n = 0;
    while (isdigit(a[pre]))
    {
        n = 10 * n + a[pre] - '0';
        pre++;
    }
    return n;
}
//读操作符
char ReadOperator()
{
    char operator;
    operator= a[pre];
    pre++;
    return operator;
}
//计算器
int claculate(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
}
//优先级比较函数,运用了ASCII码
int isprior(char current, char former)
{
    if (abs(current - ',') > abs(former - ','))
        return 1;
    else
        return 0;
}
