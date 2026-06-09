#include<stdio.h>
#include <stdbool.h>

typedef struct point
{
	int x;
	int y;
} Point;

typedef struct segment
{
	Point p1;
	Point p2;
	bool isValid; 
} Segment;

typedef struct node
{
	Segment data;
	struct node *next;
} Node, *pNode;

Segment * FindIsValid(Segment segs[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		if (segs[i].isValid)
		{
			segs[i].isValid = false;
			return &segs[i];
		}
	}
	
	return NULL;
}

int Count(pNode node)
{
	int c = 0;
	if (node == NULL) return c;
	pNode tmp = node;
	while(tmp->next != NULL) 
	{
		c++;
		tmp = tmp->next;
	}
	
	return c + 1;
}

void DeleteList(pNode node)
{
	pNode tmp = node;
	if (tmp->next == NULL)
	{
		free(tmp);
		return;
		
	}
	
	while(tmp->next != NULL) 
	{
		pNode t = tmp;
		tmp = tmp->next;
		free(t);
	}
}

Segment* FindPre(pNode head, Segment segs[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if (!segs[i].isValid) continue;
		if (segs[i].p2.x == head->data.p1.x && segs[i].p2.y == head->data.p1.y)
		{
			segs[i].isValid = false;
			return &segs[i];
		}
	}
	
	return NULL;
}

Segment* FindNext(pNode tail, Segment segs[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		if (!segs[i].isValid) continue;
		if(segs[i].p1.x == tail->data.p2.x && segs[i].p1.y == tail->data.p2.y)
		{
			segs[i].isValid = false;
			return &segs[i];
		}
	}
	
	return NULL;
}

int main()
{
	int n,i,x1,x2,y1,y2,a,b;
	scanf("%d",&n);
	//获取全部的线段。 
	Segment segs[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		segs[i].p1.x=x1;
		segs[i].p1.y=y1;
		segs[i].p2.x=x2;
		segs[i].p2.y=y2;
		segs[i].isValid = true;
	}
	
	pNode result = NULL;
	Segment *find = FindIsValid(segs, n);
	while(find != NULL)
	{
		pNode head = NULL, tail = NULL, line;
		head = tail = line = (Node*)malloc(sizeof(Node));
		line->next = NULL;
		line->data.p1 = find->p1;
		line->data.p2 = find->p2;
		
		Segment *pre = FindPre(head, segs, n);
		Segment *next = FindNext(tail, segs, n);
		while(pre != NULL || next != NULL)
		{
			if(pre != NULL)
			{
				pNode temp = (Node*)malloc(sizeof(Node));
				temp->next = NULL;
				temp->data = *pre;
				temp->next = head;
				head = temp;	
			}
			
			if(next != NULL)
			{
				pNode temp = (Node*)malloc(sizeof(Node));
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
				temp->data = *next;
			}
			
			pre = FindPre(head, segs, n);
			next = FindNext(tail, segs, n);
		}
		
		if (result == NULL) result = head;
		else
		{
			int c1 = Count(result);
			int c2 = Count(head);
			if (c1 < c2)
			{
				DeleteList(result);
				result = head;
			}
			else
			{
				DeleteList(head);
			}
		}
		
		find = FindIsValid(segs, n);
	}
	
	if(result != NULL)
	{
		n = Count(result);
		a = result->data.p1.x;
		b = result->data.p1.y;
		DeleteList(result);
	}
	
	printf("%d %d %d",n,a,b);
	return 0;
}
















/*void save(int x[100][4],int r)
{
	int i,j;
	char lj[5];
	for(i=0;i<r;i++)
	{
		for(j=0;j<4;j++)
			scanf("%d",&x[i][j]);
		gets(lj);
	}
}

void sele(int x[100][4])                  //combo记以不同开头的分别连接数 
{                                         //a保留i以前的数方便返回 
	int i,j,combo[100]={1};               //b为线段串的开头数 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
				continue;
			else if(a[i][2]==a[j][0] && a[i][3]==a[j][1])
			{
				b=i; 
				a=i+1;
				i=j;
				combo[b]++;
				break;
			}
			else if()
		}
	}
}

int main()
{
	int i,j,a[100][4],r;
	char lj[5];
	scanf("%d",&r);
	gets(lj);
	save(a,r);
	
	return 0;
}*/



