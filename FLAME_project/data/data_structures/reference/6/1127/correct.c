#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//Õ»¶¥
	int capacity;//×ÜµÄÈÝÁ¿
}Stack;
int op,x;
int main() 
{ 
  Stack s,*p;
  p=&s;
  
  p->capacity=100;
  p->top=0;
  STDataType* temp = (STDataType* )malloc(sizeof(STDataType)* 100);
  p->a=temp;
  while(scanf("%d",&op)!=EOF)
  {
    if(op==1)
    {    
      if(p->top<=100)
      {
        scanf("%d",&x);
        p->a[p->top] = x;
	      p->top++;
      }
      else
      printf("error ");
    }
    else if(op==0)
    {
     
      if(p->top>0)
	    { 
        printf("%d ",p->a[p->top-1]);
        p->top--;
      }
      else
      printf("error ");
    }
    else if(op==-1)
    {
        break;
    }
  }
  system("pause");
  return 0; 
}


