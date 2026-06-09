#include <stdio.h>
#include <stdlib.h>

// 定义多项式项的结构体
struct Term {
    int coefficient; // 系数
    int exponent;    // 指数
    struct Term *next; // 指向下一个项的指针
};

// 声明辅助函数，用于快速排序
int partition(struct Term *arr[], int low, int high);

// 快速排序函数
void quickSort(struct Term *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 辅助函数，用于快速排序
int partition(struct Term *arr[], int low, int high) {
    int pivot = arr[low]->exponent;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j]->exponent > pivot) {
            i++;
            struct Term *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct Term *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
} // @@ [The partition function incorrectly uses `arr[high]` as part of the loop that runs `j < high`, but then swaps `arr[i+1]` with `arr[high]`. However, the pivot was taken from `arr[low]`, not `arr[high]`, so this is a classic Lomuto vs Hoare confusion. This leads to incorrect sorting.]

// 多项式相乘函数
struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    
    // 遍历第一个多项式的每一项
    for (struct Term *ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        // 遍历第二个多项式的每一项
        for (struct Term *ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            // 计算相乘的系数和指数
            int coefficient = ptr1->coefficient * ptr2->coefficient;
            int exponent = ptr1->exponent + ptr2->exponent;
            
            // 查找结果多项式中是否已存在该指数的项
            struct Term *ptr = result;
            while (ptr != NULL && ptr->exponent != exponent) {
                ptr = ptr->next;
            }
            
            // 如果已存在该指数的项，则将系数相加
            if (ptr != NULL) {
                ptr->coefficient += coefficient;
            } else { // 否则创建新的项并插入到结果多项式中
                struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
                newTerm->coefficient = coefficient;
                newTerm->exponent = exponent;
                newTerm->next = result;
                result = newTerm;
            }
        }
    }
    
    return result;
}

// 输出多项式函数
void printPolynomial(struct Term *poly) {
    struct Term *ptr = poly;
    while (ptr != NULL) {
        printf("%d %d ", ptr->coefficient, ptr->exponent);
        ptr = ptr->next;
    }
    printf("\n");
}

// 释放多项式内存函数
void freePolynomial(struct Term *poly) {
    struct Term *ptr = poly;
    while (ptr != NULL) {
        struct Term *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main() {
    // 读取第一个多项式
    struct Term *poly1 = NULL;
    int coefficient, exponent;
    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = poly1;
        poly1 = newTerm;

        // 检查是否遇到空行，如果遇到则停止读取
        if (getchar() == '\n')
            break;
    }

    // 读取第二个多项式
    struct Term *poly2 = NULL;
    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = poly2;
        poly2 = newTerm;
    } // @@ [This reading loop does not check for newline termination like the first one, which may cause issues if input has trailing spaces or multiple lines, but in this specific test case it works. However, the real issue is elsewhere.]

    // 计算两个多项式的乘积
    struct Term *result = multiplyPolynomials(poly1, poly2);

    // 将结果多项式转换为数组以进行排序
    int numTerms = 0;
    struct Term *ptr = result;
    while (ptr != NULL) {
        numTerms++;
        ptr = ptr->next;
    }
    struct Term *terms[numTerms];
    ptr = result;
    for (int i = 0; i < numTerms; i++) {
        terms[i] = ptr;
        ptr = ptr->next;
    }

    // 对结果多项式项按指数从高到低进行排序
    quickSort(terms, 0, numTerms - 1); // @@ [Due to the bug in `partition`, the sorting order is incorrect, leading to wrong output order.]

    // 输出结果多项式
    for (int i = 0; i < numTerms; i++) {
        printf("%d %d ", terms[i]->coefficient, terms[i]->exponent);
    }
    printf("\n");

    // 释放内存
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}