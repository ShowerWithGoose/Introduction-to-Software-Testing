#include<stdio.h>
#include<stdlib.h>
struct zhan{
 int data;
 struct zhan* link;
} s;
struct zhan stack;
typedef struct zhan* Nodeptr;
struct zhan* Top;
void push(int m)
{
 Nodeptr p;
 if((p=(Nodeptr)malloc(sizeof(s)))==NULL)
 {
  printf("error ");
 }
 else
 p->data=m;
 p->link=Top;
 Top=p;
}
void pop()
{
 Nodeptr p;
 int item;
 if(isEmpty())
 printf("error ");
 else
 {
  p=Top;
  item=Top->data;
  Top=Top->link;
  free(p);
  printf("%d ",item);
 }
}
int isEmpty()
{
 return Top==NULL;
}
void initStack()
{
 Top=NULL;
}
int main()
{
 int flag;
 int num;
 initStack;
 while(1)
 {
     scanf("%d",&flag);
     if(flag==1)
     {
      scanf("%d",&num);
      push(num);
  }
  else if(flag==0)
  {
   pop();
  }
  else if(flag==-1)
  {
   break;
  }
 }
 return 0;
}

