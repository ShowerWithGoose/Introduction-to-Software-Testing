#include<stdio.h>
#include<stdlib.h>
#define maxsize 101
//¶¨ÒåÕ»
typedef struct
{
 int data[maxsize];
 int top;
}sqstack,*sqslink;
 
//ÉèÖÃÕ»¿Õ
void Clearstack(sqslink s)
{
 s->top=-1;
}
 
 
//ÅÐ¶ÏÕ»¿Õ
int Emptystack(sqslink s)
{
 if (s->top<0)
 {
 	 return 1;
 }
 else
 {
 	return 0;
 }
}
//½øÕ»
int Push(sqslink s, int x)
{
 if (s->top>=maxsize-1)
  return 0;
 else
 {
  s->top++;
  s->data[s->top]=x;
  return 1;
 }
}
// ³öÕ»
int Popstack(sqslink s)
{
 int n;
 if (Emptystack(s)>0)
  return NULL;
 else
 {
  n=s->data[s->top];
  s->top--;
  return n;
 }
}
void main()
{
 sqslink s1;
 int gj[200]={0};
	int cz[99]={0};
	int sj[99]={0};
	int i=1;
	int t=0;
	int n=0;
	int ans=0;
 s1 =(sqslink)malloc(sizeof(sqstack));
 Clearstack(s1);
 while(scanf("%d",&cz[i]))
	{
		if(cz[i]==1)
		{
			scanf("%d",&sj[t]);
			Push(s1,sj[t]);
		}
		if(cz[i]==0&&Emptystack(s1)>0)
		{
			printf("error ");
		}
		if(cz[i]==0&&Emptystack(s1)==0)
		{
			ans=Popstack(s1);
			printf("%d ",ans);
		}
		if(cz[i]==-1)
		{
			break;
		}
		i++;
}
return 0;
}

