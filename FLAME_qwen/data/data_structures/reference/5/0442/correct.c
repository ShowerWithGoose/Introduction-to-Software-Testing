#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#define cre_node (node*)malloc(sizeof(node))
typedef struct node{
	int index;
	int time;
	struct node *next;
}node;
int main ()
{
	node *heada=(node*)malloc(sizeof(node));
	//node *p = (node*)malloc(sizeof(node));
	//heada = p;
	char sa[1001];
	char sb[1001];
	gets(sa);gets(sb);
	int len_a,len_b;
	int inde,ti;
	node *p=heada;
	int i=0;
	int time=0;
	while(sa[i] == ' '||(sa[i]<='9'&&sa[i]>='0'))
	{
		if(sa[i] ==' ')
		{
			i++;
		continue;
		}
		int num = 0;
		while((sa[i]<='9'&&sa[i]>='0'))
		{
			num = num*10 + sa[i]-'0';
			i++;
		}
		if(time==0)
		{
			ti = num;
			time++;
		}
		else if(time == 1)
		{
			inde = num;
			p->index = inde;
			p->time = ti;
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			len_a++;
			time= 0;
		}
	}
	node *headb=(node*)malloc(sizeof(node));
	p = headb;
	i=0;
	while(sb[i] == ' '||(sb[i]<='9'&&sb[i]>='0'))
	{
		if(sb[i] ==' ')	
		{i++;continue;}
		int num = 0;
		while((sb[i]<='9'&&sb[i]>='0'))
		{
			num = num*10 + sb[i]-'0';
			i++;
		}
		if(time==0)
		{
			ti = num;
			time++;
		}
		else if(time == 1)
		{
			inde = num;
			p->index = inde;
			p->time = ti;
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			p->index=-1;
			p->time=0;
			len_b++;
			time= 0;
		}
	}
	//node k;
	node *headc=cre_node;
	for(node *i = heada; i->index >= 0 && i->time >0 ;i=i->next)
	{
		for(node *j = headb; j->index >= 0 && j->time >0 ;j=j->next)
		{
			int newindex = i->index + j->index;
			int newtime = i->time * j->time;
			int flag = 0;
			node *last;
			node *kk = headc;
			if(headc->index > newindex)
			{
				node *newnode=cre_node;
				newnode->next = headc;
				newnode->index= newindex;
				newnode->time= newtime;
				headc = newnode;
			}
			else
			for(;kk->index >=0 && kk->time >0 ;kk = kk->next)
			{
				if(newindex == kk->index)
				{
					kk->time += newtime;
					flag = 1;
					break;
				}
				if(newindex < kk->index )
				{
					node *newnode = (node*)malloc(sizeof(node));
					last->next = newnode;
					newnode->index = newindex;
					newnode->time = newtime;
					newnode->next = kk;
					break;
				}
				last = kk;
			}
			if(kk->index <0 || kk->time <=0) 
			{
			//	node *newnode = (node*)malloc(sizeof(node));
				//kk->next=newnode;
				kk->index=newindex;
				kk->time = newtime;
				kk->next = (node*)malloc(sizeof(node));
				kk->next->index = -1;
				kk->next->time = 0;
			}
		}
	}
	char ans[101][1001];
	int top=0;
	for(node* i = headc;  i->index >= 0 && i->time >0 ;i = i->next)
	{
		sprintf(ans[top++],"%d %d ",i->time,i->index);
	}
	for(int i=top-1; i>=0;i--)
	printf("%s",ans[i]);
	return 0;
}

