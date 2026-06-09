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
    char operator= '+'; @@ [Using 'operator' as a variable name is invalid in C because 'operator' is a reserved keyword in C++ and may cause issues with some compilers or coding standards, though strictly in C it's allowed. However, the real issue lies elsewhere.]
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
                operand[i + 1] = '\0'; @@ [Assigning '\0' to an integer array element is incorrect. This should be handled by adjusting array bounds logically, not by null-terminating integers.]
                operator1[i] = '\0'; @@ [Same issue: operator1 is a char array used to store operators, but after shifting, setting a char to '\0' may interfere with later logic that expects valid operators or proper loop termination. More critically, the loop control variable 'i' is being modified inside the loop, which can cause skipping or infinite loops.]
                k--;
                i = flag - 1;
            }
        }
        if (operand[1] == '\0') @@ [Comparing an integer array element to '\0' (which is 0) is misleading. It should check if there's only one operand (e.g., k == 0), not whether operand[1] is zero, because zero is a valid number in expressions.]
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
    gets(expression); @@ [The function 'gets' is unsafe and has been removed from modern C standards (since C11). Using 'gets' can lead to buffer overflow and is likely the cause of compilation errors on systems where it's not available (e.g., newer GCC versions). Replace with 'fgets'.]
    printf("%d", calculateExpression(expression));
    return 0;
}