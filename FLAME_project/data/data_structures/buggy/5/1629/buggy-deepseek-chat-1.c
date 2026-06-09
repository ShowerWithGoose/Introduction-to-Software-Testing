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
    printf("Enter the second polynomial:\n"); // @@ 错误：程序不应输出提示信息，与预期输出不符，应删除此行
    poly2 = createPoly();
    
    product = multiplyPoly(poly1, poly2);
    
   
    printPoly(product);
    
    return 0;
}

Polynomial createPoly() {
    Polynomial head = NULL, tail, temp;
    int coef, exp;
    
    while (scanf("%d %d", &coef, &exp) == 2) { // @@ 错误：输入格式要求系数和指数之间用空格分隔，但此处格式字符串中的空格会导致读取时跳过空格，但输入中可能没有空格（如"8 1000000000"），实际读取正确，但更关键的是输入结束条件：题目要求输入以换行结束，但这里使用scanf返回值判断，当输入两个整数后，如果后面有换行，getchar()会读取换行，但scanf可能因为后续字符不是整数而返回0或EOF，导致循环无法正确终止。应改为与参考程序一致，使用%c读取分隔符并判断换行
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
    printf("\n");
}