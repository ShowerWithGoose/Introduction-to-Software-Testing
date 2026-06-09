#include <stdio.h>
#include <string.h>
int l = 0;
void dele0(char *);
int trans(char *);
int main()
{
    char a[1000];
    gets(a);
    dele0(a);
    int n = strlen(a);
    int num[1000];
    char sym[1000];
    int i = 0, j1 = 0, j2 = 0, j3 = 0; /*j1为数字个数，j2为符号个数  */
    if (a[0] == '-')
    {
        for (i = n - 1; i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
        a[0] = '0';
    }
    i = 0;
    while (i < n) //数字和符号分别存入不同数组
    {
        if (a[i] <= '9' && a[i] >= '0')
        {
            num[j1] = trans(a + l);
            j1 += 1;
            i = l;
        }
        else
        {
            sym[j2] = a[l];
            l += 1;
            j2 += 1;
            i = l;
        }
    }
    if (sym[0] == '+' || sym[0] == '-')
    {
        j3 = 1;
    }
    for (i = 0; i < j2; i++) //运算，先乘除后加减
    {
        if (sym[i] == '*')
        {
            num[j3] *= num[i + 1];
        }
        else if (sym[i] == '/')
        {
            num[j3] = num[j3] / num[i + 1];
        }
        if (sym[i + 1] == '-' || sym[i + 1] == '+')
        {
            j3 = i + 2;
        }
    }
    for (i = j2 - 1; i >= 0; i--)
    {
        if (sym[i] == '+')
        {
            num[0] += num[i + 1];
        }
        else if (sym[i] == '-')
        {
            num[0] -= num[i + 1];
        }
    }
    printf("%d", num[0]);
    return 0;
}
void dele0(char *a)
{
    int n0 = strlen(a), i, j = 0;
    for (i = 0; i < n0; i++)
    {
        if (a[i] != ' ')
        {
            a[j] = a[i];
            j += 1;
        }
    }
    a[j] = '\0';
}
int trans(char *a)
{
    int i = 0, num = 0;
    while (*(a + i) >= '0' && *(a + i) <= '9')
    {
        num = num * 10 + *(a + i) - '0';
        i += 1;
    }
    l += i;
    return num;
}


