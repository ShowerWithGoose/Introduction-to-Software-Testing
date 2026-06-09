#include <stdio.h>
#include <stdlib.h>

// 定义多项式的节点结构
typedef struct PolyNode {
    int coef; // 系数
    int exp;  // 指数
    struct PolyNode *next; // 指向下一个节点的指针
} PolyNode, *Polynomial;

// 函数声明
Polynomial createPoly(); // 创建多项式
Polynomial multiplyPoly(Polynomial p1, Polynomial p2); // 多项式乘法
void insertTerm(Polynomial result, int coef, int exp); // 插入项
void printPoly(Polynomial p); // 打印多项式

int main() {
    Polynomial poly1, poly2, product;
   
    poly1 = createPoly();
    printf("Enter the second polynomial:\n"); // @@ [The problem does not require any prompt messages to be printed. This extra output causes mismatch with expected output format which should only contain the result of multiplication.]
    poly2 = createPoly();
    
    product = multiplyPoly(poly1, poly2);
    
   
    printPoly(product);
    
    return 0;
}

Polynomial createPoly() {
    Polynomial head = NULL, tail, temp;
    int coef, exp;
    
    while (scanf("%d %d", &coef, &exp) == 2) {
        temp = (Polynomial)malloc(sizeof(PolyNode));
        temp->coef = coef;
        temp->exp = exp;
        temp->next = NULL;
        
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        
        if(getchar() == '\n') break; // 如果输入的是换行符，则结束输入
    }
    return head;
}

Polynomial multiplyPoly(Polynomial p1, Polynomial p2) {
    Polynomial result = (Polynomial)malloc(sizeof(PolyNode)); // 创建头节点
    result->next = NULL;
    
    for (Polynomial i = p1; i != NULL; i = i->next) {
        for (Polynomial j = p2; j != NULL; j = j->next) {
            insertTerm(result, i->coef * j->coef, i->exp + j->exp);
        }
    }
    return result->next; // 返回头节点的下一个节点，即第一个有效节点
}

void insertTerm(Polynomial result, int coef, int exp) {
    Polynomial prev = result; // 初始化前驱节点为头节点
    Polynomial current = result->next; // 当前节点指向头节点的下一个节点

    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next; // 循环找到合适的插入位置
    }

    if (current != NULL && current->exp == exp) {
        // 如果存在指数相等的项，则合并系数
        current->coef += coef;
        if (current->coef == 0) {
            // 如果系数合并后为0，则删除该节点
            prev->next = current->next;
            free(current);
        }
    } else {
        // 插入新节点
        Polynomial temp = (Polynomial)malloc(sizeof(PolyNode));
        temp->coef = coef;
        temp->exp = exp;
        temp->next = current;
        prev->next = temp;
    }
}

void printPoly(Polynomial p) {
    int isFirstTerm = 1;
    while (p != NULL) {
        if (!isFirstTerm) {
            printf(" ");
        } else {
            isFirstTerm = 0;
        }
        printf("%d %d", p->coef, p->exp);
        p = p->next;
    }
    printf("\n"); // @@ [The problem states: "A space after the last exponent is optional." However, printing a newline ('\n') at the end may cause presentation error if the judge expects no trailing newline or strict space-separated output without line breaks. But more critically, the reference program does NOT output a newline. The expected output format implies only space-separated coefficient-exponent pairs, possibly ending without newline. However, in many OJ systems, a trailing newline is acceptable. BUT given that the test case shows empty expected output and the error is compilation-related, this might not be the real issue. However, the actual compilation error reported is "/bin/sh: 1: gcc: not found", which indicates environment issue, not code issue. But since we must find logical/semantic errors causing wrong output, the real bugs are: (1) extra prompt in main(), (2) potential memory leak or incorrect handling when all terms cancel out (multiplyPoly returns NULL but printPoly handles it), but most importantly: the input reading logic is flawed.]

    // @@ [Critical error: In createPoly(), the condition `if(getchar() == '\n') break;` consumes one character after each term pair. However, after the last pair, the input ends with a newline, but there may be no extra character to consume after the final `%d %d`. For example, if input is "1 2\n3 4\n", then after reading "3 4", getchar() reads '\n' and breaks — OK. But if input is just "1 0\n", then after reading "1 0", getchar() reads '\n' and breaks — OK. However, what if the input buffer has leftover whitespace? More importantly, the use of `scanf` followed by `getchar()` is fragile. But the bigger issue is: the loop condition `while (scanf(...) == 2)` will read ALL available pairs until scanf fails. Then, inside the loop, after reading a pair, it checks ONE character. If the input is "1 2 3 4\n", then first scanf reads 1,2; then getchar() reads space (not '\n'), so loop continues; next scanf reads 3,4; then getchar() reads '\n' → break. That works. BUT if input is "1 2\n", then: scanf reads 1,2 → success; then getchar() reads '\n' → break. OK. So input logic seems okay.

    // However, there's another critical flaw: when multiplying two polynomials, if the result is zero polynomial (all terms canceled), then `multiplyPoly` returns NULL (because result->next is NULL and we return it). Then `printPoly(NULL)` prints nothing and then prints "\n". But the problem says: only non-zero terms are printed. So zero polynomial should produce NO output. However, the current `printPoly` prints a newline even when p is NULL. That would output a blank line, which is wrong.

    // But the test case input is empty? The test case input section is blank. And expected output is blank. But the buggy output is a compilation error message. However, the instruction says: "based on ... test case inputs that the program failed, the program's output, and the expected output". Since the provided test case input is empty, perhaps the real issue is that the program doesn't handle empty input correctly.

    // Wait: how does createPoly handle empty input? If the first scanf fails (e.g., immediately newline), then while loop doesn't run, returns NULL. That's correct.

    // But the main issue causing wrong output in non-empty cases is the extra printf in main(). Also, the printPoly adds a newline which might be disallowed.

    // Given the problem's output format: "Print the terms ... A space after the last exponent is optional." — it does NOT say anything about newline. The reference program does NOT print newline. So printing '\n' is an error.

    // Therefore, two errors:
    // 1. Extra prompt in main()
    // 2. Trailing newline in printPoly
}