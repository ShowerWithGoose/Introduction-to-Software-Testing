#include<stdio.h>
typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;
    int lenth;
    struct node *next;
}* Node;
typedef struct node xd;

Node newnode()
{
	Node p;
	p=malloc(sizeof(Node));
	p->lenth=0;
	return p;
}
/*
void freenode(Node p)
{
	if(p->next!=NULL)
	{
		freenode(Node p->next);
	}
	free(p);
}
*/
xd arr[100];

int hbxdkxx(xd a,xd b)
{
	if(a.x1==b.x2&&a.y1==b.y2)
	{
		return 1;
	}
	else if(a.x2==b.x1&&a.y2==b.y1)
	{
		return 2;
	}
	else
	{
		return 0;
	}
 } 
xd hbxd(xd a,xd b)
{
	xd n;
	if(hbxdkxx(a,b)==1)
	{
		n.x1=b.x1;
		n.y1=b.y1;
		n.x2=a.x2;
		n.y2=a.y2;
		n.lenth=a.lenth+b.lenth;
		return n;
	}
	else
	{
		n.x1=a.x1;
		n.y1=a.y1;
		n.x2=b.x2;
		n.y2=b.y2;
		n.lenth=a.lenth+b.lenth;
		return n;
	}
}
int main()
{
	Node p,q;
	int n;
	int lp,lp1;
	int x1,x2,y1,y2;
	p=newnode();
	q=p;
	scanf("%d",&n);
	for(lp=0;lp<n;lp++)
	{
		scanf("%d %d %d %d",&arr[lp].x1,&arr[lp].y1,&arr[lp].x2,&arr[lp].y2);
		arr[lp].lenth=1;
	}
	
	xd t;
	for(lp=0;lp<n;lp++)
	{
		for(lp1=0;lp1<n;lp1++)
		{
			if(hbxdkxx(arr[lp],arr[lp1])>0)
			{
				t=hbxd(arr[lp],arr[lp1]);
				arr[lp]=t;
				arr[lp1].lenth=0;
				arr[lp1].x1=0;
				arr[lp1].y1=0;
				arr[lp1].x2=0;
				arr[lp1].y2=0;
			}
		}
	}
	int k=0;
	int ml=0;
	for(lp=0;lp<n;lp++)
	{
		if(arr[lp].lenth>ml)
		{
			ml=arr[lp].lenth;
			k=lp;
		}
	}
	printf("%d %d %d",ml,arr[k].x1,arr[k].y1);
	return 0;
}




