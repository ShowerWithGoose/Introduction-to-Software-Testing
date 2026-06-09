#include <stdio.h>
int num[3];
char op[3];
char opread()
{
    char op;
    while (1)
    {
        scanf("%c", &op);
        if (op != ' ')
            break;
    }
    return op;
}
int numread()
{
    if (op[0] == '=')
        return 0;
    int num = 0;
    while (scanf("%d", &num) != EOF)
    {
        if (num != 0)
            ;
        break;
    }
    return num;
}
int main()
{

    num[0] = numread();
    op[0] = opread();
    num[1] = numread();
    while (op[0] == '*' || op[0] == '/')
    {
        if (op[0] == '*')
            num[0] = num[0] * num[1];
        else
            num[0] = num[0] / num[1];
        op[0] = opread();
        num[1] = numread();
    }
    if (op[0] == '=')
    {
        printf("%d", num[0]);
        return 0;
    }
    else
    {
        op[1] = opread();
        while (1)
        {
            while (op[1] == '*' || op[1] == '/')
            {
                scanf("%d", &num[2]);
                if (op[1] == '*')
                {
                    num[1] = num[1] * num[2];
                    num[2] = 0;
                }
                else if (op[1] == '/')
                {
                    num[1] = num[1] / num[2];
                    num[2] = 0;
                }
                op[1] = opread();
            }
            if (op[0] == '*')
                num[0] = num[0] * num[1];
            else if (op[0] == '/')
                num[0] = num[0] / num[1];
            if (op[0] == '+')
                num[0] = num[0] + num[1];
            else if (op[0] == '-')
                num[0] = num[0] - num[1];
            if (op[1] == '=')
                break;
            op[0] = op[1];
            num[1] = numread();
            op[1] = opread();
        }
        printf("%d", num[0]);
    }
}



