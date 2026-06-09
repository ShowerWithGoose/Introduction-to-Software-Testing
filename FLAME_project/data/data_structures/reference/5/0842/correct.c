#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int coe;
    int pow; //系数coe和指数pow
    struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;

int coefficient, power; //读入的两个中间变量
char c;
Nodeptr List1 = NULL, List = NULL, p1 = NULL, p2 = NULL, q1 = NULL, q2 = NULL, prior_node = NULL;

void createList();
void multiplyList();
void printList();

int main()
{
    createList();
    multiplyList();
    printList();

    return 0;
}

void createList()
{
    while (1)
    {
        scanf("%d%d%c", &coefficient, &power, &c);
        q1 = (Nodeptr)malloc(sizeof(Node));
        q1->coe = coefficient;
        q1->pow = power;
        q1->link = NULL;
        if (List1 == NULL)
            List1 = p1 = q1;
        else
        {
            p1->link = q1;
            p1 = p1->link;
        }
        if (c == '\n')
            break;
    }
}

void multiplyList()
{
    while (1)
    {
        scanf("%d%d%c", &coefficient, &power, &c);
        for (p1 = List1; p1 != NULL; p1 = p1->link)
        {
            q2 = (Nodeptr)malloc(sizeof(Node));
            q2->coe = p1->coe * coefficient;
            q2->pow = p1->pow + power;
            q2->link = NULL;
            if (List == NULL)
                List = p2 = q2; //空链表
            else
            {
                for (p2 = List; p2 != NULL; prior_node = p2, p2 = p2->link)
                {
                    if (q2->pow > p2->pow) //指数更大，q2是生成的新结点，与当前结点p2比较排序
                    {
                        if (p2 == List)
                        {
                            q2->link = List;
                            List = q2;
                            q2->link = NULL;
                            // break;
                        } //插入到头节点前
                        else
                        {
                            q2->link = p2;
                            prior_node->link = q2;
                            break;
                        } //将q插入到p前
                    }
                    else if (q2->pow == p2->pow)
                    {
                        p2->coe += q2->coe;
                        break;
                    } //指数相等，系数相加
                }
                if (p2 == NULL)
                    prior_node->link = q2; //将q插入到尾节点后
            }
        }
        if (c == '\n')
            break;
    }
}

void printList()
{
    for (p2 = List; p2 != NULL; p2 = p2->link)
        printf("%d %d ", p2->coe, p2->pow);
    printf("\n");
}
