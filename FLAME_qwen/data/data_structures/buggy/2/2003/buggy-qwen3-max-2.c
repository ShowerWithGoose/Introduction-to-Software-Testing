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
    char operator= '+'; // @@ [Variable name 'operator' is a reserved keyword in C++ and may cause issues with some compilers or coding standards, though it's technically allowed in C. However, the real issue lies elsewhere.]
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
        operator= expression[i]; // @@ [Same variable name issue as above, but more critically: after processing numbers and operators, the loop does not skip over possible non-digit/non-operator characters correctly, though input is guaranteed valid. The main bug is later.]
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
        for (int i = 0; i < k; i++) // @@ [This loop modifies 'i' inside the loop body (with 'i++' in the while loop), which interferes with the for-loop increment and causes skipping or infinite loops. Also, shifting operands/operators incorrectly alters indices.]
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
                    i++; // @@ [This inner increment of 'i' breaks the outer for-loop logic because 'i' is being modified inside the loop body, leading to incorrect indexing and potential out-of-bounds access.]
                }
                operand[i + 1] = '\0'; // @@ [Assigning '\0' to an int array is meaningless and incorrect; this should not be done. It doesn't terminate anything useful and may corrupt data.]
                operator1[i] = '\0'; // @@ [Similarly, assigning '\0' to char array at index 'i' after shifting may be off-by-one and unnecessary since 'k' tracks length.]
                k--;
                i = flag - 1; // @@ [Resetting 'i' to 'flag - 1' causes the next for-loop increment to go back to 'flag', but due to prior modifications of 'i', this logic is fragile and error-prone.]
            }
        }
        if (operand[1] == '\0') // @@ [Comparing an int array element to '\0' (which is 0) assumes that unassigned elements are zero, which may not hold if previous shifting left garbage. Also, if the first number was zero, this gives false positive. Should compare 'k == 0' or 'j == 1'.]
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
    gets(expression); // @@ [Use of 'gets' is dangerous and deprecated; it can cause buffer overflow. Should use 'fgets' instead. However, the problem states input ends with '=', and buffer size is 100, so may work for small inputs, but still a critical flaw.]
    printf("%d", calculateExpression(expression));
    return 0;
}