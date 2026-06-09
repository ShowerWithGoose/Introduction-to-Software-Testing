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
            return a / b; // @@ [Problem requires integer division, but this performs floating-point division]
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
        } else if (expr[i] == '(') { // @@ [Problem states expression does not contain parentheses, but code handles them; however, more critically, input may not have parentheses but the logic assumes they might, which is unnecessary but not directly causing error. The real issue is below.]
            operators[++top_operator] = expr[i];
            i++;
        } else if (expr[i] == ')') { // @@ [Same as above: handling parentheses not needed per problem, but not the core bug. Core issue is integer division and final cast.]
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

    printf("%d", operands[0]); // @@ [Casting a double result to int via %d is undefined behavior; also, because division was done in floating point, e.g., 5/3 becomes ~1.666, then cast to int gives 1 — which matches expected, BUT intermediate results may accumulate floating point errors. However, the bigger issue is that the problem requires integer arithmetic throughout, not floating-point. Also, using %d to print a double value is incorrect and causes undefined behavior.]

    return 0;
}