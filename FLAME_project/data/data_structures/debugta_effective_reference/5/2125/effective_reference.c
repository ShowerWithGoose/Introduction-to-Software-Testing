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
linklist a1,a2;
number temp[MAXN];
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
	linklist tmp1=a1->next,tmp2=a2->next;
	int i=0,j;
	int n=1;
	while(tmp1!=NULL)
	{
		tmp2=a2->next;
		while(tmp2!=NULL)
		{
			n=1;
			for(j=0;j<i;j++)
			{
				if(temp[j].e==tmp1->exponent+tmp2->exponent)
				{
					n=0;
					break;
				}
			}
			if(n==1)
			{
				temp[i].f=tmp1->factor*tmp2->factor;
				temp[i].e=tmp1->exponent+tmp2->exponent;
				i++;
			}
			else
				temp[j].f+=tmp1->factor*tmp2->factor;
			tmp2=tmp2->next;
		}
		tmp1=tmp1->next;
	}
	return i;
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
	int d,i;
	a1=(linklist)malloc(sizeof(linknode));
	a2=(linklist)malloc(sizeof(linknode));
	input(a1);
	scanf("\n");
	input(a2);
	scanf("\n");
	d=multi();
	qsort(temp,d,sizeof(temp[0]),compare);
	//printf("%d",d);
	for(i=1;i<=d;i++)
		printf("%d %d ",temp[i-1].f,temp[i-1].e);
	return 0;
} 

