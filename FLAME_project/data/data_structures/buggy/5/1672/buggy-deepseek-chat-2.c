#include <stdio.h>
#include <stdlib.h>
typedef struct multi
{
  int e;
  int a;
  struct multi *link;
} multi;
multi *lista, *listb, *listc; // lista,listb为输入的两个多项式,listc储存结果
void multi1();
int main()
{
  lista = (multi *)malloc(sizeof(multi));
  listb = (multi *)malloc(sizeof(multi));
  listc = (multi *)malloc(sizeof(multi));
  multi *q = lista; // q用于输入数据并将节点链接到链表中
  listc->link = NULL;
  multi *p; // p生成节点
  char d = '0';
  while (d != '\n')
  {
    p = (multi *)malloc(sizeof(multi));
    scanf("%d", &p->a);
    scanf("%d%c", &p->e, &d);
    q->link = p;
    q = p;
  }
  q->link = NULL;
  q = listb;
  d = '0';
  while (d != '\n')
  {
    p = (multi *)malloc(sizeof(multi));
    scanf("%d", &p->a);
    scanf("%d%c", &p->e, &d);
    q->link = p;
    q = p;
  }
  q->link = NULL;
  multi1();
  q = listc->link;
  while (q != NULL)
  {
    if (q->a != 0)
    {
      printf("%d %d ", q->a, q->e);
    }
    q = q->link;
  }
}
void multi1()
{
  multi *p = lista->link; // p为lista的指针
  multi *q = listb;       // q为listb的指针
  multi *s;               // s为listc的指针
  int e, a;               // e为指数，a为系数
  while (p != NULL)
  {
    q = listb->link;
    while (q != NULL)
    {
      a = p->a * q->a;
      e = p->e + q->e;
      s = listc;
      while (s->link != NULL)
      {
        if (e == s->e) // 判断是否已经有该系数的节点
        {
          s->a += a;
          break;
        }
        else if (e > s->link->e) // 判断是否该节点是否大于了下一个节点的指数，若大于则插入
        {
          multi *temp = (multi *)malloc(sizeof(multi));
          temp->a = a;
          temp->e = e;
          temp->link = s->link;
          s->link = temp;
          break;
        }
        s = s->link;
      }
      if (s->link == NULL)
      {
        if (e == s->e)
        {
          s->a += a; // @@ 错误：当s->link为NULL且e等于s->e时，应该合并到s节点，但这里s是listc头节点（指数为0），而实际应该检查的是最后一个节点的指数，但逻辑上s已经指向了最后一个节点，所以这里合并正确，但问题在于前面的while循环中，当e等于s->e时，s可能不是最后一个节点，但这里s->link==NULL时，s是最后一个节点，所以合并正确。然而，更严重的问题是：当e不等于s->e时，应该创建新节点并链接到s之后，但这里没有处理e小于s->e的情况（即应该插入到s之后），实际上这个else分支只处理了s->link==NULL的情况，但e可能小于s->e，此时应该插入到s之后，但代码中直接创建新节点并链接，这是正确的，因为s是最后一个节点。但主要错误在于前面的while循环中，当e等于s->e时，s->a += a，但s可能是listc头节点（指数为0），而listc头节点是哨兵节点，不应该存储实际数据，这会导致错误地将系数累加到哨兵节点上。
        }
        else
        {
          multi *temp = (multi *)malloc(sizeof(multi));
          temp->a = a;
          temp->e = e;
          s->link = temp;
          temp->link = NULL;
        }
      }
      q = q->link;
    }
    p = p->link;
  }
}