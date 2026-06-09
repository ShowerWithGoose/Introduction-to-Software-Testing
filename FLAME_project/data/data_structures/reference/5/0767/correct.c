#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct anxn{
	int xishu;
	int zhishu;
	struct anxn* next;
}AnXn; 
int main()
{
	//¶ÁÈëÊý¾Ý
	char c=' ';
	AnXn *first1=NULL,*first2=NULL;
	AnXn *p=(AnXn*)malloc(sizeof(AnXn));
	while(c!='\n')
	{
		if(first1==NULL)
		{
			scanf("%d%d",&p->xishu,&p->zhishu);
			first1=p;
			p->next=NULL;
		}
		else
		{
			AnXn *q=(AnXn*)malloc(sizeof(AnXn));
			scanf("%d%d",&q->xishu,&q->zhishu);
			p->next=q;
			q->next=NULL;
			p=q;
		}
		c=getchar();
	} 
	c=' ';
	AnXn *p2=(AnXn*)malloc(sizeof(AnXn));
	while(c!='\n')
	{
		if(first2==NULL)
		{
			scanf("%d%d",&p2->xishu,&p2->zhishu);
			first2=p2;
			p2->next=NULL;
		}
		else
		{
			AnXn *q2=(AnXn*)malloc(sizeof(AnXn));
			scanf("%d%d",&q2->xishu,&q2->zhishu);
			p2->next=q2;
			q2->next=NULL;
			p2=q2;
		}
		c=getchar();
	} 
	
	AnXn *k1,*k2;
	AnXn *first3=NULL;
	AnXn *p3=(AnXn*)malloc(sizeof(AnXn));
	for(k1=first1;k1;k1=k1->next)
	{
		for(k2=first2;k2;k2=k2->next)
		{
			if(first3==NULL)
			{
				p3->xishu=k1->xishu*k2->xishu;
				p3->zhishu=k1->zhishu+k2->zhishu;
				first3=p3;
				p3->next=NULL;
			}
			else
			{
				AnXn *q3=(AnXn*)malloc(sizeof(AnXn));
				q3->xishu=k1->xishu*k2->xishu;
				q3->zhishu=k1->zhishu+k2->zhishu;
				q3->next=NULL;
			//	printf("%d %d\n",q3->xishu,q3->zhishu);
				AnXn *k3=first3;
				for(k3=first3;k3->next!=NULL;k3=k3->next)
				{
					if((k3->next->zhishu)>(q3->zhishu))
					continue;
					else
					{
						if(k3->next->zhishu==q3->zhishu)
						{
							k3->next->xishu=(k3->next->xishu)+(q3->xishu);
							q3->next=k3->next;
						//	printf("%d\n",k3->next->xishu);
							break;
						}
						else
						{
							q3->next=k3->next;
							k3->next=q3;
							break;
						}
					}
				}
				if(k3->next==NULL)
				{
					if(k3->zhishu==q3->zhishu)
					{
						k3->xishu+=q3->xishu;
						k3->next=NULL;
					//	printf("%d\n",k3->xishu);
					}
					else
					{
						k3->next=q3;
						q3->next=NULL;
					}
				}
				
				
				
			}
		}
	}
	AnXn* cnt;
	for(cnt=first3;cnt;cnt=cnt->next)
	printf("%d %d ",cnt->xishu,cnt->zhishu);
	printf("\n");
	
	return 0;
}

