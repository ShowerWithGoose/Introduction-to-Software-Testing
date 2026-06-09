#include <stdio.h>
#include <string.h>
#include <ctype.h>
int num[100];
char sign[100];
char a[100];
int zf = 1;
int hash1[20]; //*/ y len1
int hash2[20]; //+- yy len2
int len1, len2;
int carol = 0;
int main()
{
    int ber = 0;
    int ans;
    int i = 0, j = 0, k = 0, n, y = 0, yy = 0;
    int flag = 1; // 1是可以读负号，如果读了一个数字变0开始读数字模式，读到符号再变成1
    gets(a);
    for (i = j = 0; a[i] != '\0'; i++)
        if (!isspace(a[i]))
            a[j++] = a[i];
    a[j] = '\0';
    n = j; //长度
    i = 0, j = 0;
    while (a[i] != '\0') //读取单元
    {
        if (flag == 1 && a[i] == '-')
            zf = -1;       //读-号
        if (isdigit(a[i])) //数字
        {
            flag = 0;
            ber = ber * 10 + a[i] - '0';
        }
        if ((!isdigit(a[i])) && flag == 0) //读符号
        {
            num[k++] = ber * zf;
            zf = 1;
            sign[j++] = a[i];
            flag = 1;
            ber = 0;
            if (a[i] == '*' || a[i] == '/')
                hash1[y++] = j - 1;
            if (a[i] == '+' || a[i] == '-')
                hash2[yy++] = j - 1;
        }
        if (a[i] == '=')
        {
            len1 = y;
            len2 = yy;
            break;
        }
        i++;
    }
    for (i = 0; i < len1; i++)
    {
        if (sign[hash1[i]] == '*')
        {
            num[hash1[i]] *= num[hash1[i] + 1];
            num[hash1[i] + 1] = num[hash1[i]];
        }
        if (sign[hash1[i]] == '/')
        {
            num[hash1[i]] /= num[hash1[i] + 1];
            num[hash1[i] + 1] = num[hash1[i]];
        }
    }
    for (i = 0; i < len1; i++)
    {
        num[hash1[i]] = 100000;
    }
    ans = num[hash2[0]];
    if (ans == 100000)
    {
        j = 0;
        while (num[hash2[0] + j] == 100000)
            j++;
        ans = num[hash2[0] + j];
    }

    for (i = 0; i < len2; i++)
    {
        if (sign[hash2[i]] == '+')
        {
            j = 1;
            while (num[hash2[i] + j] == 100000)
                j++;
            ans += num[hash2[i] + j];
        }
        if (sign[hash2[i]] == '-')
        {
            j = 1;
            while (num[hash2[i] + j] == 100000)
                j++;
            ans -= num[hash2[i] + j];
        }
    }
    printf("%d", ans);
    return 0;
}

