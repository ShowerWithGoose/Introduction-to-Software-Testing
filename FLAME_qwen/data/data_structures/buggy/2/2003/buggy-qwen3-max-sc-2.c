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
    char operator= '+'; // @@ [Variable name 'operator' conflicts with C++ keyword; while valid in C, some compilers or strict modes may issue warnings or errors. However, the real issue is using 'gets' which is unsafe and removed in newer standards, but the immediate compilation error likely stems from missing support for 'gets'.]
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
                operand[i] = result;
                while (i <= k - 2)
                {
                    operand[i + 1] = operand[i + 2];
                    operator1[i] = operator1[i + 1];
                    i++;
                }
                operand[i + 1] = '\0'; // @@ [Assigning '\0' to an integer array element is incorrect; should not null-terminate integer arrays. This causes type inconsistency and potential logic errors.]
                operator1[i] = '\0';
                k--;
                i = flag - 1;
            }
        }
        if (operand[1] == '\0') // @@ [Comparing integer array element with '\0' is invalid; operand[1] is an int, not a char. This leads to incorrect condition evaluation.]
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
    gets(expression); // @@ [The function 'gets' is dangerous and has been removed from the C standard library since C11. Compilers like GCC may not include it by default, causing a compilation error: "implicit declaration of function ‘gets’". Use 'fgets' instead.]
    printf("%d", calculateExpression(expression));
    return 0;
}