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

    printf("%d", operands[0]); // @@ [The program uses floating-point arithmetic but the problem requires integer division and integer output. Casting to int truncates, but more critically, division should be integer division (e.g., 5/3=1), yet applyOp performs floating-point division. Also, the expression may not contain parentheses per problem statement, but the code handles them unnecessarily, though not directly causing error here. The core issue is that division is done in floating point and then truncated, which fails for cases like 5/3 where it becomes 1.666... → 1 when cast to int — this actually matches expected behavior, BUT: the bigger issue is that intermediate results are stored as double, and for large integers or specific sequences, precision loss may occur. However, the immediate bug revealed by test cases is likely that the loop condition stops at '=', but the input includes '=' and possibly newline; fgets includes newline, so if input is "5 - 1 * 2 * 3 + 12 / 2 / 2 =\n", then expr[i] may never be '=' if newline comes first. But more critically: the problem states the expression ends with '=', but the code assumes that '=' is present and stops when it sees it. However, if the input has spaces after numbers or before '=', the digit parsing may skip non-digit correctly, but the main flaw is: the code supports parentheses, which are not in the input, but that's harmless. The real error is that the problem requires INTEGER division, but applyOp does floating-point division. For example, 5/2 gives 2.5, then cast to int gives 2 — which is correct. But consider negative? Problem says no negative. However, another critical issue: the code reads until '=', but what if the '=' is followed by newline? The loop condition is while (expr[i] != '='), so it will stop at '=', which is correct. But the actual bug is: the problem says "integer division", meaning truncation toward zero, which double division then casting to int does for positive numbers. So why failure? Look at output: it prints %d of a double. If operands[0] is 5.0, (int)5.0 is 5 — OK. But if due to floating point imprecision it's 4.999999, cast to int gives 4 — wrong. This can happen in chained divisions. Example: 12 / 2 / 2 = 3, but if computed as ((12.0 / 2.0) / 2.0) = 3.0 — OK. But consider 7/3*3: should be (7/3)=2, 2*3=6. But floating point: 7/3≈2.333, *3=7.0 → cast to 7 — wrong. So the algorithm must use integer arithmetic throughout. The use of double causes incorrect results due to premature floating-point operations instead of integer truncation after each division. Thus, the entire approach using double is flawed for integer-only semantics.]

    return 0;
}