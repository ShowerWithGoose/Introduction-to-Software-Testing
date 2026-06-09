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

Segment * FindIsValid(Segment line[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		if (line[i].isValid)
		{
			line[i].isValid = false;
			return &line[i];
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

Segment* FindPre(pNode head, Segment line[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if (!line[i].isValid) continue;
		if (line[i].p2.x == head->data.p1.x && line[i].p2.y == head->data.p1.y)
		{
			line[i].isValid = false;
			return &line[i];
		}
	}
	
	return NULL;
}

Segment* FindNext(pNode tail, Segment line[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		if (!line[i].isValid) continue;
		if(line[i].p1.x == tail->data.p2.x && line[i].p1.y == tail->data.p2.y)
		{
			line[i].isValid = false;
			return &line[i];
		}
	}
	
	return NULL;
}

int main()
{
	int n,i,x1,x2,y1,y2,a,b;
	scanf("%d",&n);
	//获取全部的线段。 
	Segment line[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		line[i].p1.x=x1;
		line[i].p1.y=y1;
		line[i].p2.x=x2;
		line[i].p2.y=y2;
		line[i].isValid = true;
	}
	
	pNode ans = NULL;
	Segment *find = FindIsValid(line, n);
	while(find != NULL)
	{
		pNode head = NULL, tail = NULL, line;
		head = tail = line = (Node*)malloc(sizeof(Node));
		line->next = NULL;
		line->data.p1 = find->p1;
		line->data.p2 = find->p2;
		
		Segment *pre = FindPre(head, line, n);
		Segment *next = FindNext(tail, line, n);
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
			
			pre = FindPre(head, line, n);
			next = FindNext(tail, line, n);
		}
		
		if (ans == NULL) ans = head;
		else
		{
			int c1 = Count(ans);
			int c2 = Count(head);
			if (c1 < c2)
			{
				DeleteList(ans);
				ans = head;
			}
			else
			{
				DeleteList(head);
			}
		}
		
		find = FindIsValid(line, n);
	}
	
	if(ans != NULL)
	{
		n = Count(ans);
		a = ans->data.p1.x;
		b = ans->data.p1.y;
		DeleteList(ans);
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



