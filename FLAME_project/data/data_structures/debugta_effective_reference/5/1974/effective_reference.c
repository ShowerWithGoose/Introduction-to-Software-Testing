#include<stdio.h>
#include<stdlib.h>
#define MAXN 20000
typedef struct linknode
{
	int factor;//xishu
	int exponent;//zhishu
	struct linknode *next;
}linknode,*linklist;
typedef struct
{
	int f;
	int e;
}number;
linklist cheng,cheng1;
number result[MAXN];
void input(linklist head)
{
	int a,n;
	linklist tmp,rear;
	rear=head;
	while(1)
	{
		scanf("%d",&a);
		getchar();
		scanf("%d",&n);
		tmp=(linklist)malloc(sizeof(linknode));
		tmp->factor=a;
		tmp->exponent=n;
		rear->next=tmp;
		rear=tmp;
		if((getchar())=='\n')
			break;
	}
	//printf("test");
	rear->next=NULL;
}
int multi()
{
	linklist tmp1=cheng->next,tmp2=cheng1->next;
	int c=0,i;
	int delta=1;
	while(tmp1!=NULL)
	{
		tmp2=cheng1->next;
		while(tmp2!=NULL)
		{
			delta=1;
			for(i=0;i<c;i++)
			{
				if(result[i].e==tmp1->exponent+tmp2->exponent)
				{
					delta=0;
					break;
				}
			}
			if(delta==1)
			{
				result[c].f=tmp1->factor*tmp2->factor;
				result[c].e=tmp1->exponent+tmp2->exponent;
				c++;
			}
			else
				result[i].f+=tmp1->factor*tmp2->factor;
			tmp2=tmp2->next;
		}
		tmp1=tmp1->next;
	}
	return c;
}
int compare(const void *a,const void *b)
{
	number m=*((number *)a);
	number n=*((number *)b);
	if(m.e>n.e)
		return -1;
	else
		return 1;
}
int main()
{
	int d,c;
	cheng=(linklist)malloc(sizeof(linknode));
	cheng1=(linklist)malloc(sizeof(linknode));
	input(cheng);
	scanf("\n");
	input(cheng1);
	scanf("\n");
	d=multi();
	qsort(result,d,sizeof(result[0]),compare);
	//printf("%d",d);
	for(c=1;c<=d;c++)
		printf("%d %d ",result[c-1].f,result[c-1].e);
	return 0;
} 

