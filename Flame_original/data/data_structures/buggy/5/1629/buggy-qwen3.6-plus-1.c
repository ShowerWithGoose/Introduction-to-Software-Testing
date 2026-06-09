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
    printf("Enter the second polynomial:\n"); // @@ The problem specification does not require any prompt output. Printing extra text will cause format mismatch or Wrong Answer on automated judges.
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
        
        if(getchar() == '\n') break; // @@ Mixing scanf and getchar is unreliable; getchar() may read a space character if trailing spaces exist before the newline, causing incorrect loop termination or program hanging.
    }
    return head;
}

Polynomial multiplyPoly(Polynomial p1, Polynomial p2) {
    Polynomial result = (Polynomial)malloc(sizeof(PolyNode)); // 创建头节点
    result->next = NULL;
    
    for (Polynomial i = p1; i != NULL; i = i->next) { // @@ C89 standard does not allow variable declaration inside for-loop initialization, which may cause compilation error on strict compilers.
        for (Polynomial j = p2; j != NULL; j = j->next) { // @@ Same as above.
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
    printf("\n");
}