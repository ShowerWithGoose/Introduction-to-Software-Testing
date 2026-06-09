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
  multi *q = listb;       // q为listb的指针 @@ [q should point to listb->link, not listb itself, because listb is a dummy head node and its 'e' and 'a' fields are uninitialized. Using q = listb leads to accessing garbage values in comparisons like 'e == s->e' where s starts at listc (also a dummy head).]
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
        if (e == s->e) // 判断是否已经有该系数的节点 @@ [This compares the new exponent 'e' with the exponent of the current node 's', but 's' starts at the dummy head 'listc', which has an uninitialized 'e'. This leads to undefined behavior. The comparison should be with s->link->e when checking existing terms.]
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
        if (e == s->e) // @@ [Again, comparing 'e' with 's->e' where 's' may be the dummy head (listc) or last real node. If s is the dummy head and no real nodes exist, s->e is uninitialized, causing undefined behavior. Also, after insertion loop, s points to last node, but if list was empty, s is dummy head with garbage 'e'.]
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