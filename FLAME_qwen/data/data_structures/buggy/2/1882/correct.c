#include <stdio.h>

int readNumber() {
    int num;
    scanf("%d", &num);
    return num;
}

char readOperator() {
    char op;
    do {
        scanf(" %c", &op);
    } while (op == ' ');
    return op;
}

int checkPriority(char op1, char op2) {
    if (op1 == '*' || op1 == '/') {
        return 0;
    } else if (op2 == '*' || op2 == '/') {
        return 1;
    }
    return 0;
}

int calculate(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; 
    }
}

int main() {
    int firstNum, secondNum, thirdNum;
    char firstOp, secondOp;

    firstNum = readNumber();
    firstOp = readOperator();
    if (firstOp == '=') {
        printf("%d\n", firstNum);
    } else {
        secondNum = readNumber();
        secondOp = readOperator();

        while (secondOp != '=') {
            thirdNum = readNumber();
            if (checkPriority(firstOp, secondOp) == 0) {
                firstNum = calculate(firstNum, firstOp, secondNum);
                secondNum = thirdNum;
                firstOp = secondOp;
            } else {
                secondNum = calculate(secondNum, secondOp, thirdNum);
            }
            secondOp = readOperator();
        }
        printf("%d\n", calculate(firstNum, firstOp, secondNum));
    }

    return 0;
}


