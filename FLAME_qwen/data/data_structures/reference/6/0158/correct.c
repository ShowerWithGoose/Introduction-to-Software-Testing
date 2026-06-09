#include<stdio.h>
struct stack
{int data[105];
 int num;
}s;
typedef struct stack stack;
void intstack(stack *s)
{s->num=-1;
}
int isempty(stack *s)
{if(s->num==-1) return 1;
 else return 0;
}
int isfull(stack *s)
{if(s->num==101) return 1;
 else return 0;
}
int indata(stack *s,int a)
{if(isfull(s)) 
{printf("error "); 
 return 0;
}
 else
 {
 s->data[++s->num]=a;
 return 1;
 }
}
int outdata(stack *s)
{if(isempty(s))
{printf("error ");
return 0;
}
else
{
printf("%d ",s->data[s->num--]);
}
}
int main()
{intstack(&s);
 int a,b;
 while(1)
 {scanf("%d",&a);
 if(a==-1) break;
 if(a==0) outdata(&s);
 if(a==1)
 {scanf("%d",&b);
  indata(&s,b);
 }
 }
}

