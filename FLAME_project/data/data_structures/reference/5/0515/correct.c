#include<stdio.h>
struct num{
		int coefficient;
		int index;
		struct num *before;
		struct num *next;
	} raw_1[100],raw_2[100],ans[100],*p,*s;
int main()
{
	int i=0,j=0,k,num_1,num_2,num_ans,coefficient,index;
	char ch;
	while(1)
	{
		scanf("%d%d",&raw_1[i].coefficient,&raw_1[i].index);
		i++;
		ch=getchar();
		if(ch=='\n')
		{
			break;
		}
	}
	num_1=i;
	while(1)
	{
		scanf("%d%d",&raw_2[j].coefficient,&raw_2[j].index);
		j++;
		ch=getchar();
		if(ch=='\n')
		{
			break;
		}
	}
	num_2=j;               //读入已查，没有问题 
	ans[0].coefficient=raw_1[0].coefficient*raw_2[0].coefficient;
	ans[0].index=raw_1[0].index+raw_2[0].index;
	num_ans=1;
	s=&ans[0];
	p=s;
	for(i=0;i<num_1;i++)
	{
		if(i==0)
		{
			j=1;
		}
		else
		{
			j=0;
		}
		for(;j<num_2;j++)
		{
			coefficient=raw_1[i].coefficient*raw_2[j].coefficient;
			index=raw_1[i].index+raw_2[j].index;
			p=s;
			for(k=0;k<num_ans;k++,p=p->next)
			{
				if(index>p->index)
				{
					if(p->before==NULL)
					{
						ans[num_ans].coefficient=coefficient;
						ans[num_ans].index=index;
						ans[num_ans].next=p;
						p->before=&ans[num_ans];
						s=&ans[num_ans];
						num_ans++;
						break;
					}
					else
					{
						ans[num_ans].coefficient=coefficient;
						ans[num_ans].index=index;
						ans[num_ans].next=p;
						ans[num_ans].before=p->before;
						(p->before)->next=&ans[num_ans];
						p->before=&ans[num_ans];
						num_ans++;
						break;
					}
				}
				else if(index<p->index)
				{
					if(p->next!=NULL)
					{
						continue;
					}
					else
					{
						ans[num_ans].coefficient=coefficient;
						ans[num_ans].index=index;
						ans[num_ans].before=p;
						p->next=&ans[num_ans];
						num_ans++;
						break;
					}
				}
				else if(index==p->index)
				{
					p->coefficient+=coefficient;
					break;
				}
			}
		}
	}
	for(i=0,p=s;i<num_ans;i++,p=p->next)
	{
		printf("%d %d ",p->coefficient,p->index);
	}
	return 0;
}

