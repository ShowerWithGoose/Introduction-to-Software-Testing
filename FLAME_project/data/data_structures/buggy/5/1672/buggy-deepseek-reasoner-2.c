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
      s = listc; // @@ 错误：s 指向了头节点（哑元），其 e 成员未初始化，导致后续判断可能错误地将乘积项添加到哑元上。
      while (s->link != NULL)
      {
        if (e == s->e) // @@ 错误：当 s 为哑元时，e 与未初始化的 s->e 比较，若相等则会错误地修改哑元系数，且后续不再插入新节点，造成指数丢失。
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