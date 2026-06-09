#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    /* data */
    int coef;
    int exp;
    struct node *link;
} PNode, *PLinkList;
//函数作用构成新节点，
void ATTACH(int co, int ex, PLinkList *r)
{
    // co，ex 分别为多项式中系数和指数，r为链表c末尾节点的指针
    PLinkList w;
    w = (PLinkList)malloc(sizeof(PNode));
    w->exp = ex;
    w->coef = co;
    w->link = NULL;
    (*r)->link=w; 
    *r=w;
}
//函数：创建链表储存两个函数
PLinkList LinkListCreate()
{
    PLinkList p, r, list = NULL;
    int a, b; // element type
    
    while (scanf("%d%d", &a, &b) != EOF && getchar() != '\n')
    {
        p = (PLinkList)malloc(sizeof(PNode));
        p->coef = a;
        p->exp = b;
        p->link = NULL;
        if (list == NULL)
            list = p;
        else
            r->link = p;
        r = p;
    }
    
    p = (PLinkList)malloc(sizeof(PNode));
        p->coef = a;
        p->exp = b;
        p->link = NULL;
        if (list == NULL)
            list = p;
        else
            r->link = p;
        r = p;
    return (list);
}
//函数，两个多项式相乘
PLinkList multiply(PLinkList A, PLinkList B)
{
    PLinkList C, p1, p2, rear, temp;
    int xi, zhi;
    p1 = A;
    p2 = B;
    //申请节点
    C = (PLinkList)malloc(sizeof(PNode));
    C->link = NULL;
    rear = C;
    //用A的第一项乘以B
    while (p2)
    {
        ATTACH(p1->coef * p2->coef, p1->exp + p2->exp, &rear);
        p2 = p2->link;
    }
    p1 = p1->link; // A的余下项乘以B的每一项
    while (p1)
    {
        p2 = B;   //指向多项式B的头
        rear = C; //指向C
        while (p2)
        {
            xi = p1->coef * p2->coef;
            zhi = p1->exp + p2->exp;
            //寻找位置插入
            while (rear->link && rear->link->exp > zhi)
                rear = rear->link;
            if (rear->link && rear->link->exp == zhi)
            {                              //下一个恰好为对应指数
                if (rear->link->coef + xi) //系数不为0
                    rear->link->coef += xi;
                else //系数为0，删除节点
                {
                    temp = rear->link;
                    rear->link = temp->link;
                    free(temp);
                }
            }
            else//下一项系数小于要插入的
            {
                temp=(PLinkList)malloc(sizeof(PNode));
                temp->coef=xi;
                temp->exp=zhi;
                temp->link=rear->link;
                rear->link=temp;
                rear=rear->link;
            }
            p2=p2->link;
        }
        p1=p1->link;
    }
    //删除空节点
    p2=C;
    C=C->link;
    free(p2);
    return C;
}
//函数，输出多项式
void printpoly(PLinkList C)
{

    if (!C)
    {
        printf("0 0");
        return;
    }
    while (C)
    {
        printf("%d %d ", C->coef, C->exp);
        C = C->link;//链表遍历
    }
}
int main()
{
    PLinkList A, B, C;
    A = LinkListCreate();
    B = LinkListCreate();
    C = multiply(A, B);
   /*  printpoly(A);
    printf("\n");
    printpoly(B);
    printf("\n"); */
    printpoly(C);
    return 0;
}

