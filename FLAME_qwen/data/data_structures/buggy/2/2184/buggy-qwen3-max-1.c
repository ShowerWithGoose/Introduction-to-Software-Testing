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

    printf("%d", operands[0]); // @@ [The program uses floating-point arithmetic throughout but casts the final result to int via %d. However, the problem requires integer division (truncating), but intermediate calculations use double which may cause precision issues. More critically, the problem states the expression contains no parentheses, yet the code handles parentheses, which is unnecessary but not wrong. The real error is that division is done in double and then truncated only at print time, but the problem requires integer division at each / operation. For example, 5/3 must be 1, but 5.0/3.0 ≈ 1.666... becomes 1 when cast to int — this works for positive numbers, but fails for negative (e.g., -5/3 should be -1 in truncation toward zero, but C double division then cast also gives -1). However, the bigger issue is that the problem says "integer division", meaning each / must truncate immediately. But the main visible bug is that the code supports parentheses (not needed) and more importantly, the test input likely has no decimal points, yet the code parses floats. But the critical flaw causing wrong output is: the problem requires integer arithmetic with truncating division at each step, but this code does floating-point division and only truncates at the end. This can lead to incorrect results due to floating point precision or order of operations. However, the most direct error is that the problem says "perform integer division", but applyOp uses double division. Also, the output uses %d on a double value (operands[0] is double), which is undefined behavior — this is a severe error.]

    return 0;
}