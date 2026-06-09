#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef int ElemType;//改数据类型
//顺序栈
typedef struct
{
   ElemType *base;//栈底指针
   ElemType *top;//栈顶指针
   int stackSize;
}sqStack;
void initStack(sqStack *s)//创建栈
{
    s->base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));//MAXSIZE改变改这里
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stackSize=MAXSIZE;
}
void Push(sqStack *s,ElemType e)//入栈
{
   *(s->top)=e;
   s->top++;
}
void Pop(sqStack* s,ElemType *e)//出栈
{
    if(s->top==s->base) return;
    *e=*--(s->top);
}
int main()
{
    sqStack s;
    initStack(&s);
    int i=0;
    int a[200]={0};
    char ch;
    int e;
    scanf("%d",&a[i]);
    ch=getchar();
    while(ch!='\n')
    {
        i++;
        scanf("%d",&a[i]);
        ch=getchar();
    }
    i=0;
    while(1)
    {
        if(a[i]==1)
        {
            if(s.top-s.base==s.stackSize)
            printf("error ");
            else
            Push(&s,a[i+1]);
            i+=2;
            continue;
        }
        else if(a[i]==0)
        {
            if(s.base==s.top)
            printf("error ");
            else 
            {
                Pop(&s,&e);
                printf("%d ",e);
            }
            i++; 
        } 
        else if(a[i]==-1)
        break;
    }
    return 0;
}

