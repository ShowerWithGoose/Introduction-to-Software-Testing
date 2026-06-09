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
    char operator= '+'; // @@ [Variable name 'operator' is a reserved keyword in C++ and may cause issues with some compilers or flags; though valid in pure C, it's poor practice and can lead to portability or compilation issues in strict environments. However, the actual critical error is elsewhere.]
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
        for (int i = 0; i < k; i++) // @@ [This loop attempts to process * and / first, but the logic for shifting operands and operators is flawed: it overwrites data incorrectly and uses '\0' to terminate integer and char arrays meant for numbers/operators, which breaks subsequent arithmetic. Also, modifying loop variable 'i' inside the loop causes skipped or repeated operations.]
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
                operand[i + 1] = '\0'; // @@ [Assigning '\0' (0) to an integer array element corrupts numeric data; should not null-terminate integer arrays. This causes later operands to become zero unexpectedly.]
                operator1[i] = '\0'; // @@ [Similarly, null-terminating operator array here is unnecessary and may interfere if later code expects valid operators up to index k-1.]
                k--;
                i = flag - 1;
            }
        }
        if (operand[1] == '\0') // @@ [Comparing operand[1] (an int) to '\0' (0) is logically incorrect; after processing, operand[1] might legitimately be zero from calculation, leading to wrong early return. Should check based on operator count 'k'.]
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
    gets(expression); // @@ [Use of 'gets' is dangerous and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. This is the primary cause of the "gcc: not found" misleading error—actually, the compiler refuses to compile due to 'gets'. Replace with fgets or similar.]
    printf("%d", calculateExpression(expression));
    return 0;
}