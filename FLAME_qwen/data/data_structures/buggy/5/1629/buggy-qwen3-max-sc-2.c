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
    printf("Enter the second polynomial:\n"); // @@ [This output is not in the expected format and may interfere with automated judging which expects only the result of multiplication without extra prompts]
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
    printf("\n"); // @@ [The problem states that a space after the last exponent is optional, but a newline is not mentioned in the output format. Automated judges often expect no extra newline or only specific formatting. However, this is less likely to cause a compilation error. The actual compilation error indicated in the test case is "gcc: not found", which is an environment issue, not a code issue. But since the instruction says to find errors in the program based on failed test cases and expected behavior, the real logical issues are: (1) extra prompt in main(), (2) potential memory leak if input has zero-coefficient terms (but input guarantees non-zero coefficients), (3) more critically, the program does not handle the case where the result polynomial is zero (all terms cancel out). In that case, it would print nothing followed by a newline, but should print nothing at all or possibly nothing with no newline. However, the most concrete error affecting correctness is the extra printf in main().]
}