#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
char a[1000];
int cal(char ope, int num1, int num2);
int numscan(int start, char *a, int *num1);
int main(int argc, const char *argv[])
{
    int num1, num2, num3, ans;
    char op1, op2;
    gets(a);
    int i = 0, j = 0;
    for (i = 0, j = 0; i < strlen(a); ++i)
    {
        if (a[i] != ' ')
            a[j++] = a[i];
    }
    a[j] = '\0';
    int start = 0;
    start += numscan(start, a, &num1);
    op1 = a[start++];
    if (op1 == '=')
    {
        ans = num1;
    }
    else
    {
        start += numscan(start, a, &num2);
        op2 = a[start++];
        if (op2 == '=')
        {
            ans = cal(op1, num1, num2);
        }
        else
        {
            start += numscan(start, a, &num3);
            while (op2 != '=')
            {
                if (op2 == '*' || op2 == '/')
                {
                    if (op1 == '*' || op1 == '/')
                    {
                        num1 = cal(op1, num1, num2);
                        op1 = op2;
                        num2 = num3;
                        op2 = a[start++]; //****

                        start += numscan(start, a, &num3);
                    }
                    else
                    
                    {
                        num2 = cal(op2, num2, num3);
                        op2 = a[start++];
                        start += numscan(start, a, &num3);
                    }
                }
                else
                {
                    num1 = cal(op1, num1, num2);
                    op1 = op2;
                    num2 = num3;
                    op2 = a[start++]; //****

                    start += numscan(start, a, &num3);
                }
            }
            ans = cal(op1, num1, num2);
        }
    }
    printf("%d\n", ans);
    return 0;
}

int cal(char ope, int num1, int num2)
{
    switch (ope)
    {
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    default:
        break;
    }
}
int numscan(int start, char *a, int *num1)
{
    int ret = 0, k;
    for (k = start; a[k] != '\0' && isdigit(a[k]); ++k)
    {
        ret = ret * 10 + a[k] - '0';
    }
    *num1 = ret;
    return k - start;
}

