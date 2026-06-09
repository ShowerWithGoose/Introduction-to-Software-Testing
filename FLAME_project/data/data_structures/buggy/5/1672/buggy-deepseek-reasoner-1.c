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
      s = listc; // @@ Initializing s to the dummy head node, which has uninitialized exponent, causing incorrect comparisons with real exponents.
      while (s->link != NULL)
      {
        if (e == s->e) // @@ Comparing e with uninitialized exponent of dummy head; may incorrectly match (e.g., if dummy->e is 0) and add to dummy instead of creating a new node, causing term to be lost.
        {
          s->a += a;
          break;
        }
        else if (e > s->link->e)
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
        if (e == s->e) // @@ When the list is empty (first term), s remains the dummy head; this comparison uses the dummy's uninitialized exponent and may cause incorrect addition or prevent creation of a new node.
        {
          s->a += a;
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