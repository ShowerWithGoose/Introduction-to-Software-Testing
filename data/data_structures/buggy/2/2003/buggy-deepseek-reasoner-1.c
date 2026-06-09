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
int calculate(int num1, int num2, char operator) // @@ [Error: 'operator' is a reserved keyword in C++, causing compilation failure; use a different variable name.]
{
    if (operator== '+') // @@ [Error: 'operator' is a reserved keyword in C++; this line will not compile.]
    {
        return num1 + num2;
    }
    else if (operator== '-') // @@ [Error: same reason as above]
    {
        return num1 - num2;
    }
    else if (operator== '*') // @@ [Error: same reason]
    {
        return num1 * num2;
    }
    else if (operator== '/') // @@ [Error: same reason]
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
    char operator= '+'; // @@ [Error: 'operator' is a reserved keyword in C++; use a variable name such as 'op'.]
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
        operator= expression[i]; // @@ [Error: 'operator' is a keyword; cannot be used as a variable.]
        i++;
        while (isdigit(expression[i]))
        {
            operand2 = operand2 * 10 + (expression[i] - '0');
            i++;
        }
        operator1[k++] = operator; // @@ [Error: variable 'operator' causes compilation error.]
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
                operand[i + 1] = '\0'; // @@ [Error: using '\0' sentinel on an integer array; '\0' is 0, which is a valid operand, leading to logical errors. Use a sentinel like -1 or track length separately.]
                operator1[i] = '\0'; // @@ [Error: same issue, '\0' is 0, which may be a valid operator after conversion? Actually operator1 is char array, but setting to '\0' (null character) is acceptable for string termination, but here it is used to indicate empty slot; however, the logic of checking with '\0' is flawed because the char array is not a string and the sentinel may conflict with arithmetic.]
                k--;
                i = flag - 1; // @@ [Error: manipulating loop variable i inside for loop causes undefined behavior and incorrect loop control; after setting i = flag-1, the for loop's increment makes it i = flag, but the inner while loop may have advanced i further, leading to skipped indices or out-of-bounds.]
            }
        }
        if (operand[1] == '\0') // @@ [Error: comparing int with '\0' is bad style; operand[1] could legitimately be 0, causing incorrect early return.]
            return operand[0];
        else
        {
            operand1 = operand[0];
            result = 0;
            for (int j = 0; j < k; j++)
            {
                operator= operator1[j]; // @@ [Error: 'operator' is a keyword; cannot be used as a variable.]
                operand2 = operand[j + 1];
                result = calculate(operand1, operand2, operator); // @@ [Error: 'operator' variable not declared due to previous errors.]
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