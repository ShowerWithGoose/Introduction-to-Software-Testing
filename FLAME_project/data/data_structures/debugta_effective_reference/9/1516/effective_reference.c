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
  ElemType x1;
  ElemType y1;
  ElemType x2;
  ElemType y2;
  struct Node *next;
  struct Node *pre;
} Node;

typedef struct Node *LinkList; /* 定义LinkList */

ElemType maxx, maxy;
int max;

Status InitList(LinkList *list);
void CreateListTail(LinkList *list, int n);
// void swap(Node *p, Node *q);
int ListTraverse(Node *list);
void copy(Node *p, Node *q); // q复制到p

int main()
{
  LinkList list, p;
  int n;
  max = 0;
  scanf("%d", &n);
  InitList(&list);
  CreateListTail(&list, n);
  p = list->next;
  while (n--)
  {
    ListTraverse(p);
    p = p->next;
  }
  // printf("bingo\n");
  printf("%d %d %d", max, maxx, maxy);

  return 0;
}

/* 初始化链式线性表 */
Status InitList(LinkList *list)
{
  *list = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
  if (!(*list))                           /* 存储分配失败 */
    return ERROR;
  (*list)->next = NULL; /* 指针域为空 */

  return OK;
}

void CreateListTail(LinkList *list, int n)
{
  LinkList p, r;
  int i;
  srand(time(0));                      /* 初始化随机数种子 */
  *list = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
  r = *list;                              /* r为指向尾部的结点 */
  for (i = 0; i < n; i++)
  {
    p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
    scanf("%d %d %d %d", &p->x1, &p->y1, &p->x2, &p->y2);
    r->next = p;
    p->pre = r; /* 将表尾终端结点的指针指向新结点 */
    r = p;      /* 将当前的新结点定义为表尾终端结点 */
  }
  p = (*list)->next;
  r->next = p; /* 表示当前链表结束 */
  p->pre = r;
}

// void swap(Node *p, Node *q)
// {
//   Node *p_pre, *q_pre, *p_next, *q_next;
//   p_pre = p->pre;
//   q_pre = q->pre;
//   p_next = p->next;
//   q_next = q->next;
//   p_pre->next = q;
//   q_pre->next = p;
//   p_next->pre = q;
//   q_next->pre = p;
//   p->pre = q_pre;
//   p->next = q_next;
//   q->pre = p_pre;
//   q->next = p_next;
// }

int ListTraverse(Node *list)
{
  LinkList p = list;
  LinkList newL, begin, end, k;
  int cnt = 1;
  int flag;
  newL = (Node *)malloc(sizeof(Node));
  copy(newL, list);
  newL->next = NULL;
  newL->pre = NULL;
  begin = newL;
  end = newL;
  while (1)
  {
    // visit(p->data);
    flag = 0;
    p = p->next;
    while (p != list)
    {
      if ((end->x2 == p->x1) && (end->y2 == p->y1))
      {
        k = (Node *)malloc(sizeof(Node));
        copy(k, p);
        end->next = k;
        k->pre = end;
        end = k;
        cnt++;
        flag = 1;
      }
      else if ((begin->x1 == p->x2) && (begin->y1 == p->y2))
      {
        k = (Node *)malloc(sizeof(Node));
        copy(k, p);
        begin->pre = k;
        k->next = begin;
        begin = k;
        cnt++;
        flag = 1;
      }
      p = p->next;
    }
    if (flag == 0)
    {
      break;
    }
  }
  // printf("\n");

  p = begin;
  // printf("\n\n\n");
  // while (p != NULL)
  // {
  //   printf("%d %d %d %d\n", p->x1, p->y1, p->x2, p->y2);
  //   p = p->next;
  // }
  // printf("\n\n\n");
  if (cnt > max)
  {
    maxy = begin->y1;
    maxx = begin->x1;
    max = cnt;
  }
  return cnt;
}

// void work(LinkList L)
// {
//   Node *head, *p;
//   head = L->next;
// }

void copy(Node *p, Node *q) // q复制到p
{
  p->x1 = q->x1;
  p->y1 = q->y1;
  p->x2 = q->x2;
  p->y2 = q->y2;
}
