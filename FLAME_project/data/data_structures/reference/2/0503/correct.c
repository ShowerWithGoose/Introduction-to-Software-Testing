#include<stdio.h>

void deSpace(char *str)
{
    int i,j = 0;
    for (i = 0;str[i] != '\0';i ++)
    {
        if (str[i] != ' ')
            str[j++] = str[i];
    }
    str[j] = '\0';
}

int main()
{
    char str[10000] = "\0"; //储存算式
    int num[10000] = {0}; //储存数字
    int count = 0;
    int result = 0;
    int i, j = 0;

    gets(str);
    deSpace(str);


    if (str[0] < '0')
    {
        for (i = 1;str[i] != '=';i ++) //记录数字
        {
            if (str[i] >= '0')
                num[j] = num[j]*10 + str[i]-'0';
            else j++;
        }
        if (str[0] == '-') num[0] *= -1;
    }
    else
    {
        for (i = 0;str[i] != '=';i ++) //记录数字
        {
            if (str[i] >= '0')
                num[j] = num[j]*10 + str[i]-'0';
            else j++;
        }
    }

    j = 0;

    if (str[0] >= '0')
    {
        for (i = 0;str[i] != '='; i ++) //计算乘除法
        {
            if (str[i] == '+'||str[i] == '-')
            {
                count ++;
                j = count;
            }
            else if (str[i] == '*')
            {
                count ++;
                num[j] *= num[count];
            }
            else if (str[i] == '/')
            {
                count ++;
                num[j] /= num[count];
            }
        }

        count = 0;
        result = num[0];

        for (i = 0;str[i] != '=';i ++) //计算加减法
        {
            if (str[i] == '+')
            {
                count ++;
                result += num[count];
            }
            else if (str[i] == '-')
            {
                count ++;
                result -= num[count];
            }
            else if (str[i] < '0') count ++;
        }
    }
    else
    {
        for (i = 1;str[i] != '='; i ++) //计算乘除法
        {
            if (str[i] == '+'||str[i] == '-')
            {
                count ++;
                j = count;
            }
            else if (str[i] == '*')
            {
                count ++;
                num[j] *= num[count];
            }
            else if (str[i] == '/')
            {
                count ++;
                num[j] /= num[count];
            }
        }

        count = 0;
        result = num[0];

        for (i = 1;str[i] != '=';i ++) //计算加减法
        {
            if (str[i] == '+')
            {
                count ++;
                result += num[count];
            }
            else if (str[i] == '-')
            {
                count ++;
                result -= num[count];
            }
            else if (str[i] < '0') count ++;
        }
    }


    printf("%d", result);

    return 0;
}



