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
        if (e == s->e) // 判断是否已经有该系数的节点 @@ [Logic Error: The code checks if the exponent matches the current node 's' instead of the next node 's->link'. Since 's' starts at the dummy head (which likely has uninitialized or 0 exponent), this condition is incorrect for finding existing terms in the sorted list. It should check s->link->e]
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
        if (e == s->e) // @@ [Logic Error: Similar to above, this checks against the last node 's' directly. While this might catch the case if the loop ended because s->link is NULL, the primary issue is that the term corresponding to exponent 'e' might not have been inserted or merged correctly due to the flawed logic in the while loop. Specifically, if the list is empty (s->link is NULL initially), it goes here. If s is the dummy head, s->e is garbage/0. If e is 0, it adds to dummy head. If e != 0, it appends. This part is technically handling the "append" or "merge with last" case, but the previous loop's failure to identify existing nodes means duplicates or wrong merges occur.]
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