#include<stdio.h>
#include<math.h>
#include<string.h>

void bubble(int n);
struct node{
	struct node *lc,*rc;
	int num,hight;
} tree[100],*p; 
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d",&tree[0].num);
	tree[0].hight=1;
	tree[0].lc=NULL;
	tree[0].rc=NULL;
	int count=1;

	for(int i=1;i<n;i++)
	{
		scanf("%d",&tree[i].num);
		tree[i].hight=1;

		p=&tree[0];
		while(1)
		{
			if(tree[i].num<p->num)//left
		{	
			count++;
			if(p->lc==NULL)
			{
				p->lc =&tree[i];
				tree[i].hight=count;
				tree[i].lc=NULL;
				tree[i].rc=NULL;
				break;
			}
			p=p->lc;
	
		}
			else//right
		{
			count++;
			if(p->rc==NULL)
			{
				p->rc=&tree[i];
				tree[i].hight=count;
				tree[i].lc=NULL;
				tree[i].rc=NULL;
				break;
			}
			p=p->rc;	
		}	
		}

count=1;

	}
	
	bubble(n);
	for(int i=0;i<n;i++)
	{
		if(tree[i].lc==NULL&&tree[i].rc==NULL)
		{
			printf("%d %d\n",tree[i].num,tree[i].hight);
		}
	}

 	return 0;
}

void bubble(int n)
{
int i, j, swapflag;
struct node hold;
for (i = 0; i < n-1; i++)
{
swapflag = 0;
for (j = 0; j < n-1-i; j++)
{
if (tree[j].num > tree[j + 1].num)
{
hold = tree[j];
tree[j] = tree[j + 1];
tree[j + 1] = hold;
swapflag = 1;
}
}
if (0 == swapflag)
break;
}
}

