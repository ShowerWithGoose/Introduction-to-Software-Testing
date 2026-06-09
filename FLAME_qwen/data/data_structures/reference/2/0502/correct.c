//2. 表达式计算（支持空格，连乘，连除）

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

//void delete_blank(char *s);
int compute(int num1, int num2, char op);
char get_op();
int order(char op1, char op2);

int main()
{
    int n1, n2, n3;
    char op12, op23;
    scanf("%d", &n1);
    op12 = get_op();
    if (op12 == '=')
    {
        printf("%d", n1);
        return 0;
    }
    scanf("%d", &n2);
    op23 = get_op();
    if (op23 == '=')
    {
        printf("%d", compute(n1, n2, op12));
        return 0;
    }
    while (op23 != '=')
    {
        scanf("%d", &n3);
        if (order(op12, op23) == 1)
        {
            n1 = compute(n1, n2, op12);
            n2 = n3;
            op12 = op23;
        }
        else
        {
            n2=compute(n2,n3,op23);
        }
        op23 = get_op();
    }
    printf("%d", compute(n1, n2, op12));
    return 0;
}

/*void delete_blank(char *s)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
}*/

int compute(int num1, int num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    default:
        return 0;
        break;
    }
}

char get_op()
{
    char op;
    while (!ispunct(op = getchar()))
    {

    }
    return op;
}

//op1 first: return 1
//op2 first: return 2
int order(char op1, char op2)
{
    if (op1 == '+' || op1 == '-')
    {
        if (op2 == '+' || op2 == '-')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}


