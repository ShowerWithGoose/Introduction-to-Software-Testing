#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
struct Node{
	int ratio;
	int index;
	struct Node *next;
};
typedef struct Node *nodeptr,node;
nodeptr list,p,q,top,a,b;
int i,j,k,num1,num2,l,c;
char xp;
void answer(int num,int ans[i][2])
{
		for(i=0;i<num;i++)
	{
		printf("%d %d ",ans[i][0],ans[i][1]);
	}
}
int main()
{
	
	list=top=NULL;
	i=0,j=0;
	xp='a';
	while(xp!='\n')
	{
		p=(nodeptr)malloc(sizeof(node));
		scanf("%d%d%c",&p->ratio,&p->index,&xp);
		i++;
		p->next=NULL;
		if(i-1==0)
		list=q=p;
		if(i!=1)
		q->next=p;
		q=p;
	
		
		
	}
	

	
	xp='a';
		while(xp!='\n')
	{
		a=(nodeptr)malloc(sizeof(node));
		scanf("%d%d%c",&a->ratio,&a->index,&xp);
		j++;
		a->next=NULL;
		if(j-1==0)
		top=b=a;
		if(j!=1)
		b->next=a;
		b=a;
	
	
	}
	int num=i*j;
	int ans[num][2];
	i=j=0;
	for(p=list;p!=NULL;p=p->next )
	{
		for(a=top;a!=NULL;a=a->next)
		{
		    ans[i][0]=p->ratio *a->ratio ;
			ans[i][1]=p->index +a->index ;
			i++;
		}	
	}
	
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ans[i][1]>ans[j][1])
			continue;
			else if(ans[i][1]==ans[j][1])
			{
				ans[i][0]=ans[i][0]+ans[j][0];
				for(num1=j;num1<num-1;num1++)
				{
					ans[num1][0]=ans[num1+1][0];
					ans[num1][1]=ans[num1+1][1];
				}
				num--;
				j--;
				num1=0;
			}
			else if(ans[i][1]<ans[j][1])
			{
				num1=ans[j][0];
				num2=ans[j][1];
				for(l=j-1;l>=i;l--)
				{
					ans[l+1][0]=ans[l][0];
					ans[l+1][1]=ans[l][1];
				}
				ans[i][0]=num1;
				ans[i][1]=num2;
				
			}
		}
	}
		for(i=0;i<num;i++)
	{
		printf("%d %d ",ans[i][0],ans[i][1]);
	}

	
	
	
}



