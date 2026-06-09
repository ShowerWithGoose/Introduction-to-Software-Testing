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
linklist head1,head2;
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
	linklist tmp1=head1->next,tmp2=head2->next;
	int i=0,r;
	int delta=1;
	while(tmp1!=NULL)
	{
		tmp2=head2->next;
		while(tmp2!=NULL)
		{
			delta=1;
			for(r=0;r<i;r++)
			{
				if(result[r].e==tmp1->exponent+tmp2->exponent)
				{
					delta=0;
					break;
				}
			}
			if(delta==1)
			{
				result[i].f=tmp1->factor*tmp2->factor;
				result[i].e=tmp1->exponent+tmp2->exponent;
				i++;
			}
			else
				result[r].f+=tmp1->factor*tmp2->factor;
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
	head1=(linklist)malloc(sizeof(linknode));
	head2=(linklist)malloc(sizeof(linknode));
	input(head1);
	scanf("\n");
	input(head2);
	scanf("\n");
	d=multi();
	qsort(result,d,sizeof(result[0]),compare);
	//printf("%d",d);
	for(i=1;i<=d;i++)
		printf("%d %d ",result[i-1].f,result[i-1].e);
	return 0;
} 

