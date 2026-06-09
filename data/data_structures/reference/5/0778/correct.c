#include <stdio.h>
#include <stdlib.h> 
struct link{
	long long a;
	long long n;
	struct link* next;
};
long long a1[50005],a2[50005],n1[50005],n2[50005];
int main()
{
	int t1=0,t2=0;
	char eat;
	while(1)
	{
		scanf("%lld %lld%c",&a1[t1],&n1[t1],&eat);
		t1++;
		if(eat=='\n')
		break;
	}
	while(1)
	{
		scanf("%lld %lld%c",&a2[t2],&n2[t2],&eat);
		t2++;
		if(eat=='\n')
		break;
	}
		
	
	//for(int i=0;i<t2;i++)
	//printf("~%lld ",a2[i]);

	struct link *first=NULL,*p,*q;//q是最后一个，p是新建的 
	
	for(int i=0;i<t1;i++)
	{
		for(int j=0;j<t2;j++)
		{
			q=(struct link *)malloc(sizeof(struct link));
			q->a=a1[i]*a2[j];
			q->n=n1[i]+n2[j];
			q->next=NULL;
			if(first==NULL)
			first=p=q;
			else//查找然后放入 
			{
				struct link *wow=first;//查找需要插入的位置  
				while(1)
				{
					if(q->n==wow->n)
					{
						(wow->a)=(wow->a)+(q->a);
						break;
					}
					else if(q->n>first->n)//放在first前 
					{
						q->next=first;
						first=q;//()
						break;
					}
					else if(wow->n>q->n&&wow->next==NULL)//在这时search就在链表末端，在search后面建立新的链接点 
					{
						p->next=q;
						p=p->next;
						break;
					}
					else if((wow->n>q->n&&wow->next->n<q->n))//在search后插入一个节点 
					{
						q->next=wow->next;
						wow->next=q; 
						break;
					}
					wow=wow->next;
				}
			}
		}
	}
	while(first!=NULL)
	{
		if(first->a!=0)
		printf("%d %d ",first->a,first->n);
		first=first->next;
	}
	return 0;
}

