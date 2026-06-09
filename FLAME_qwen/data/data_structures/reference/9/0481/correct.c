#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int spot1[101][2], spot2[101][2];
struct node{
	int num;
	int spotpre[2];
	int spotaft[2];
	struct node *next;
};
typedef struct node* Nodeptr;

Nodeptr creatlist(int n)
{
	int i = 0;
	Nodeptr p, q, head = NULL;
 	for(i = 0; i < n; i++)
	{
		p = (Nodeptr)malloc(sizeof(struct node));
		p->num = i+1;
		p->spotpre[0] = spot1[i][0];
		p->spotpre[1] = spot1[i][1];
		p->spotaft[0] = spot2[i][0];
		p->spotaft[1] = spot2[i][1];
		p->next = NULL;
		if(head == NULL)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = q->next;
		}
	}
	//q->link = head;//建立循环链表 
	return head;
}

int countline(Nodeptr head)
{
	Nodeptr p,q,r;
	int cnt, ans1 = 0, ans2 = 0, i = 0;
	p = head;
	r = head;
	q = head;
	//题干  不会有三条或三条以上的线段共一个端点
	while(r != NULL)
	{
		p = r;
		q = head;
		cnt = 1; 
		while(q != NULL)
		{
			
			if(p->spotaft[0] == q->spotpre[0] && p->spotaft[1] == q->spotpre[1])
			{
				cnt++;
				p = q;//p作为头部，q为添加部，配对成功q的值赋给p 
				q = head;
			}
			else
				q = q->next;
		}
		if(ans1 < cnt)
		{
			ans1 = cnt;
			ans2 = i;
		}
		i++;
		r = r->next;
	}
	
	printf("%d ",ans1);
	return ans2;
}
 
int main()
{
	int i,j,n;
	Nodeptr head;
	scanf(" %d", &n);
	for(i = 0; i < n; i++)
	{
		for(j=0;j<2;j++)
		{
			scanf(" %d", &spot1[i][j]); 
		}
		for(j = 0; j < 2; j++)
		{
			scanf(" %d", &spot2[i][j]); 
		}
	}
	head = creatlist(n);
	i = countline(head);
	printf("%d %d",spot1[i][0],spot1[i][1]);
	return 0;
}



