#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int xishu; // 系数
    int zhishu;    // 指数
    struct Node *next;
}Node;

// 多项式相乘
struct Node *multiply(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *ptr1, *ptr2, *ptr;
    for (ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        // 遍历第二个
        for (ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            int xishu = ptr1->xishu * ptr2->xishu;
            int zhishu = ptr1->zhishu + ptr2->zhishu;
            // 查找
            struct Node *temp = result;
            while (temp != NULL && temp->zhishu > zhishu)
            {
                temp = temp->next;
            }
            // 系数相加
            if (temp != NULL && temp->zhishu == zhishu)
            {
                temp->xishu += xishu;
            }
            else
            { // 创建新节点插入
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->xishu = xishu;
                newNode->zhishu = zhishu;

                if (temp == result)
                {
                    newNode->next = result;
                    result = newNode;
                }
                else
                {
                    struct Node *prev = result;
                    while (prev->next != temp)
                    {
                        prev = prev->next;
                    }
                    prev->next = newNode;
                    newNode->next = temp;
                }
            }
        }
    }

    return result;
}
void frees(struct Node *poly)
{
    struct Node *temp;
    while (poly != NULL)
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}
void print(struct Node *poly)
{
    struct Node *ptr = poly;
    while (ptr != NULL)
    {
        printf("%d %d ", ptr->xishu, ptr->zhishu);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL;
    int xishu, zhishu;
    do
    {
        scanf("%d %d", &xishu, &zhishu);
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->xishu = xishu;
            newNode->zhishu = zhishu;
            newNode->next = poly1;
            poly1 = newNode;
    }
    while (zhishu != '\n'); // @@ [Error: 'zhishu' is an integer, comparing it to '\n' (which is a character constant) is incorrect. This condition will never be true because zhishu is an integer read by scanf, not a newline character. This causes an infinite loop, leading to Time Limit Exceeded.]
    struct Node *poly2 = NULL;
    do
    {
        scanf("%d %d", &xishu, &zhishu);
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->xishu = xishu;
            newNode->zhishu = zhishu;
            newNode->next = poly2;
            poly2 = newNode;
    }
    while(zhishu!='\n'); // @@ [Error: Same issue as above. Comparing integer 'zhishu' to '\n' causes an infinite loop, leading to Time Limit Exceeded.]
    struct Node *result = multiply(poly1, poly2);
    print(result);
    frees(poly1);
    frees(poly2);
    frees(result);

    return 0;
}