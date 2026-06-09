#include <stdio.h>
#include <ctype.h>

// (num0 + )num1 # num2 ...
// # : + or - | num0 += num1, num1 = +/- num2
// # : * or / | num1 *= or /= num2
// # : = | output = num0 + num1
void readNum(int *num);

int main()
{
    int output, num[3] = {0, 0, 0};
    char op = '+';
    scanf("%d", &num[1]);
    while (scanf("%c", &op) != EOF)
    {
        switch (op)
        {
        case '+':
            num[0] += num[1];
            readNum(num + 1);
            break;
        case '-':
            num[0] += num[1];
            readNum(num + 1);
            num[1] = -num[1];
            break;
        case '*':
            readNum(num + 2);
            num[1] *= num[2];
            break;
        case '/':
            readNum(num + 2);
            num[1] /= num[2];
            break;
        case '=':
            output = num[0] + num[1];
            break;
        }
        if (op == '=') break;
    }
    printf("%d", output);
    return 0;
}

void readNum(int *num)
{
    scanf("%d", num);
    return;
}


