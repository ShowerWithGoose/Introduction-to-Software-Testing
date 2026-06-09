#include<stdio.h>
#include<stdlib.h>
struct zhan
{
	int data;
	struct zhan *link;
};
typedef struct zhan *Zhanptr;
typedef struct zhan Zhan;
Zhanptr top=NULL;
void inzhan(int a)
{
	Zhanptr p;
	p=(Zhanptr)malloc(sizeof(Zhan));
	p->data=a;
	p->link=top;
	top=p;
}
int outzhan()
{
	Zhanptr p;
	p=top;
	int item=top->data;
	top=top->link;
	free(p);
	return item;
}
int isEmp()
{
	return top==NULL;
}
int main()
{
	int num,numzhan=0;
	while(scanf("%d",&num)&&num!=-1)
	{
		if(num==1&&numzhan<=99)
		{
			scanf("%d",&num);
			inzhan(num);
			numzhan++;
		}
		else if(num==0&&!isEmp())
		{
			printf("%d ",outzhan());
			numzhan--;
		}
		else printf("error ");
	}
	return 0;
}

