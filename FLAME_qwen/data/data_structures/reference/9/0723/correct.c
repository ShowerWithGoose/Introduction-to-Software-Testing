#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct lln
{
	int x1,y1,x2,y2;
	int cnt;
	struct lln *next;
}node;
node l[105];
node a[105][105];
int lcnt,n;
int vis[105];
node *initiallist()
{
	node *headnode=(node *)malloc(sizeof(node));
	memset(headnode,0,sizeof(node));
	headnode->next=NULL;
	return headnode;
}
int insert(int lcnt,int k)
{
	int now=a[lcnt][0].cnt;
	if(a[lcnt][now].x2==l[k].x1&&a[lcnt][now].y2==l[k].y1)
	{
		a[lcnt][0].cnt++;
	    a[lcnt][now+1]=l[k];
	    return 1;
	}
	else return 0;
}
void createlist(int lcnt)
{
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(insert(lcnt,i)!=0)
			{
				vis[i]=1;
			    flag=1;
			}
		}
	}
}
int cmp(const void *_a,const void *_b)
{
	node a=*(node *)_a;
	node b=*(node *)_b;
	return a.x1>b.x1?1:-1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    qsort(l+1,n,sizeof(node),cmp);
    //for(int i=1;i<=n;i++) printf("%d %d %d %d\n",l[i].x1,l[i].y1,l[i].x2,l[i].y2);
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		++lcnt;
    		a[lcnt][0].cnt++;
		    a[lcnt][1]=l[i];
    		vis[i]=1;
    		createlist(lcnt);
		}
	}
	int maxl=0,maxp=0;
	for(int i=1;i<=lcnt;i++) 
	{
		if(a[i][0].cnt>maxl)
		{
			maxl=a[i][0].cnt;
			maxp=i;
		}    
	}
	printf("%d %d %d",maxl,a[maxp][1].x1,a[maxp][1].y1);
	return 0;
}




