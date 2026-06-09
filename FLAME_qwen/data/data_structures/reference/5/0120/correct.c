#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node1
{
 long long number;
 long long index;
 struct node1 *next;
};
typedef struct node1 *Nodeptr;
typedef struct node1 Node;
Nodeptr insertNode(Nodeptr head, long long number, long long index)
{
 Nodeptr p = head, q = NULL, r = NULL;
 r = (Nodeptr)malloc(sizeof(Node));
 r->number = number;
 r->index = index;
 r->next = NULL;
 if (head == NULL)
  return r;
 for (p = head; p != NULL && p->index > index; q = p, p = p->next)
  ;
 if (p != NULL && p->index == index)
 {
  p->number += number;
 }
 else if (p == head)
 {
  r->next = p;
  return r;
 }
 else
 {
  q->next = r;
  r->next = p;
 }
 return head;
}
int printNode(Nodeptr head)
{
 if (head == NULL)
  return 0;
 Nodeptr p;
 for (p = head; p != NULL; p = p->next)
 {
  if (p->number != 0)
  {
   printf("%lld ", p->number);
   printf("%lld ", p->index);
  }
 }
 return 1;
}
int main()
{
 Nodeptr line = NULL, ans = NULL;
 long long number, index, tmp = 20000000000;
 while ((scanf("%lld%lld", &number, &index)) != EOF)
 {
  if (tmp <= index)
  {
   Nodeptr p = NULL;
   for (p = line; p != NULL; p = p->next)
   {
    ans = insertNode(ans, (p->number) * number, (p->index) + index);
   }
   break;
  }
  line = insertNode(line, number, index);
  tmp = index;
 }
 while ((scanf("%lld%lld", &number, &index)) != EOF)
 {
  Nodeptr q = NULL;
  for (q = line; q != NULL; q = q->next)
  {
   ans = insertNode(ans, number * q->number, index + q->index);
  }
 }
 printNode(ans);
 return 0;
}
/*
 */



