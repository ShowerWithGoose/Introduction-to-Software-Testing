#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
  ElemType xi;
  ElemType mi;
  struct Node *next;
} Node;
typedef struct Node *LinkList; /* 定义LinkList */

void CreateListTail(LinkList *L);
void mult(LinkList L1, LinkList L2, LinkList *L);
void BubbleSort(LinkList List);

int main()
{
  LinkList L1, L2, L;
  CreateListTail(&L1);
  CreateListTail(&L2);
  mult(L1, L2, &L);
  BubbleSort(L);
  return 0;
}

void CreateListTail(LinkList *L)
{
  LinkList p, r;                            /* 初始化随机数种子 */
  *L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
  r = *L;                              /* r为指向尾部的结点 */
  while (1)
  {
    p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
    scanf("%d %d", &p->xi, &p->mi);
    r->next = p; /* 将表尾终端结点的指针指向新结点 */
    r = p;       /* 将当前的新结点定义为表尾终端结点 */
    // printf("bingo\n");
    if (getchar() == '\n')
    {
      // printf("bingo\n");
      break;
    }
  }
  // printf("bingo\n");
  r->next = NULL; /* 表示当前链表结束 */

  // printf("bingo\n");
}

void mult(LinkList L1, LinkList L2, LinkList *L)
{
  LinkList p1, p2, p, r;
  *L = (LinkList)malloc(sizeof(Node));
  r = *L;

  for (p1 = L1->next; p1; p1 = p1->next)
  {
    for (p2 = L2->next; p2; p2 = p2->next)
    {
      p = (Node *)malloc(sizeof(Node));
      p->xi = p1->xi * p2->xi;
      p->mi = p1->mi + p2->mi;
      r->next = p; /* 将表尾终端结点的指针指向新结点 */
      // printf("bingo\n");
      r = p; /* 将当前的新结点定义为表尾终端结点 */
    }
  }
  r->next = NULL; /* 表示当前链表结束 */

  for (p1 = (*L)->next; p1; p1 = p1->next)
  {
    for (p2 = p1; p2->next; p2 = p2->next)
    {
      p = p2->next;
      if (p1->mi == p->mi)
      {
        p1->xi += p->xi;
        p2->next = p->next;
        free(p);
      }
    }
  }
  p = (*L)->next;
  // while (p)
  // {
  //   printf("%d %d\n", p->xi, p->mi);
  //   p = p->next;
  // }
  // printf("bingo\n");
}

void BubbleSort(LinkList L)
{
  Node *p, *q, *tail;

  tail = NULL;

  while ((L->next->next) != tail)
  {
    p = L;
    q = L->next;
    while (q->next != tail)
    {
      if ((q->mi) < (q->next->mi))
      {
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        q = p->next;
      }
      q = q->next;
      p = p->next;
    }
    tail = q;
  }
  p = L->next;
  while (p)
  {
    printf("%d %d ", p->xi, p->mi);
    p = p->next;
  }
}

