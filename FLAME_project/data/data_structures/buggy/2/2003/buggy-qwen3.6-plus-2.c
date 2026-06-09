#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void deleteSpace(char str[])
{
    int i, j, len;
    len = strlen(str);
    for (i = 0, j = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}
int calculate(int num1, int num2, char operator)
{
    if (operator== '+')
    {
        return num1 + num2;
    }
    else if (operator== '-')
    {
        return num1 - num2;
    }
    else if (operator== '*')
    {
        return num1 * num2;
    }
    else if (operator== '/')
    {
        return num1 / num2;
    }
}
int calculateExpression(char expression[])
{
    deleteSpace(expression);
    int operand1 = 0, operand2 = 0, result = 0;
    int operand[10000];
    char operator1[10000];
    char operator= '+';
    int i = 0, j = 0, k = 0;
    while (isdigit(expression[i]))
    {
        operand1 = operand1 * 10 + (expression[i] - '0');
        i++;
    }
    operand[j] = operand1;
    j++;
    while (expression[i] != '=')
    {
        operand2 = 0;
        operator= expression[i];
        i++;
        while (isdigit(expression[i]))
        {
            operand2 = operand2 * 10 + (expression[i] - '0');
            i++;
        }
        operator1[k++] = operator;
        operand[j++] = operand2;
    }
    if (k == 0)
        return operand1;
    else
    {
        for (int i = 0; i < k; i++)
        {
            int flag = i;
            if (operator1[i] == '+' || operator1[i] == '-')
            {
                continue;
            }
            else
            {
                result = calculate(operand[i], operand[i + 1], operator1[i]);
                operand[i] = result; // @@ The logic for shifting operands and operators after evaluation is flawed. When an operation like '*' or '/' is performed, the result replaces operand[i], but the subsequent shifting loop incorrectly handles the array indices and termination conditions, leading to data corruption or incorrect state for subsequent operations. Specifically, the loop `while (i <= k - 2)` modifies `i` which conflicts with the outer loop's `i`, and the assignment `operand[i+1] = '\0'` treats an integer array as a string, which is incorrect.
                while (i <= k - 2)
                {
                    operand[i + 1] = operand[i + 2];
                    operator1[i] = operator1[i + 1];
                    i++;
                }
                operand[i + 1] = '\0';
                operator1[i] = '\0';
                k--;
                i = flag - 1;
            }
        }
        if (operand[1] == '\0')
            return operand[0];
        else
        {
            operand1 = operand[0];
            result = 0;
            for (int j = 0; j < k; j++)
            {
                operator= operator1[j];
                operand2 = operand[j + 1];
                result = calculate(operand1, operand2, operator);
                operand1 = result;
            }
            return result;
        }
    }
}
int main()
{
    char expression[100];
    gets(expression);
    printf("%d", calculateExpression(expression));
    return 0;
}