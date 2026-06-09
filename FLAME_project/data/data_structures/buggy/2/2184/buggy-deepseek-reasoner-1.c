#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// 定义运算符的优先级
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 计算两个操作数的结果
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

int main() {
    char expr[MAX_SIZE];
    double operands[MAX_SIZE];
    char operators[MAX_SIZE];
    int top_operand = -1;
    int top_operator = -1;

    fgets(expr, sizeof(expr), stdin);

    int i = 0;
    while (expr[i] != '=') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit(expr[i])) {
            double num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            if (expr[i] == '.') {
                i++;
                double fraction = 0.1;
                while (isdigit(expr[i])) {
                    num += (expr[i] - '0') * fraction;
                    fraction *= 0.1;
                    i++;
                }
            }
            operands[++top_operand] = num;
        } else if (expr[i] == '(') {
            operators[++top_operator] = expr[i];
            i++;
        } else if (expr[i] == ')') {
            while (top_operator != -1 && operators[top_operator] != '(') {
                double b = operands[top_operand--];
                double a = operands[top_operand--];
                char op = operators[top_operator--];
                operands[++top_operand] = applyOp(a, b, op);
            }
            top_operator--; // 弹出左括号
            i++;
        } else {
            while (top_operator != -1 && precedence(operators[top_operator]) >= precedence(expr[i])) {
                double b = operands[top_operand--];
                double a = operands[top_operand--];
                char op = operators[top_operator--];
                operands[++top_operand] = applyOp(a, b, op);
            }
            operators[++top_operator] = expr[i];
            i++;
        }
    }

    while (top_operator != -1) {
        double b = operands[top_operand--];
        double a = operands[top_operand--];
        char op = operators[top_operator--];
        operands[++top_operand] = applyOp(a, b, op);
    }

    printf("%d", operands[0]); // @@ Format specifier %d expects int, but operands[0] is double; undefined behavior causes incorrect output. Use %f or cast to int.

    return 0;
}