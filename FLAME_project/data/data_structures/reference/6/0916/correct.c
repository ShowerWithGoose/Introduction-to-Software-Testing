#include<stdio.h>
#include<stdlib.h>
struct Z{
	int a;
	struct Z* L;
} c;
struct Z S;
typedef struct Z* N;
struct Z* t;
int E()
{
	return t==NULL;
}
void B()
{
	t=NULL;
}
void P()
{
	N p;
	int d;
	if(E())
	printf("error ");
	else
	{
		p=t;
		d=t->a;
		t=t->L;
		free(p);
		printf("%d ",d);
	}
}
void A(int b)
{
	N p;
	if((p=(N)malloc(sizeof(c)))==NULL)
	{
		printf("error ");
	}
	else
	p->a=b;
	p->L=t;
	t=p;
}
int main()
{
	int f;
	int n;
	B;
	while(1)
	{
	    scanf("%d",&f);
	    if(f==1)
	    {
	    	scanf("%d",&n);
	    	A(n);
		}
		else if(f==0)
		{
			P();
		}
		else if(f==-1)
		{
			break;
		}
	}
	return 0;
}




