#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct lln
{
	long long xs,zs;
	struct lln *next;
}node;
char s[100005];
node a[100005],b[100005];
int cnta,cntb;
long long x,y;
node *initiallist()
{
	node *headnode=(node *)malloc(sizeof(node));
	memset(headnode,0,sizeof(node));
	return headnode;
}
void insertlist(node *p,long long xs,long long zs)
{
	node *q=(node *)malloc(sizeof(node));
	q->xs=xs;
	q->zs=zs;
	q->next=p->next;
	p->next=q;
}
void sortinsert(node *headnode,long long xs,long long zs)
{
	node *p=headnode;
	while(p->next!=NULL)
	{
		if(p->next->zs<zs) break;
		if(p->next->zs==zs)
		{ 
		    p->next->xs+=xs;
			return;
		}
		p=p->next;
	} 
	insertlist(p,xs,zs);
}
int visitlist(node *headnode)
{
	int cnt=0;
	node *p=headnode;
	while(p->next!=NULL) 
	{
		p=p->next;
		cnt++;
		if(p->xs!=0)
		    printf("%lld %lld ",p->xs,p->zs);
	}
	//printf("\n");
	return cnt;
}
int main()
{
	FILE *in,*out;
	in=fopen("line1.txt","w");
    gets(s); fputs(s,in); fclose(in);
    out=fopen("line1.txt","r");
    while(fscanf(out,"%lld%lld",&x,&y)!=EOF)
    {
    	cnta++;
    	a[cnta].xs=x;
    	a[cnta].zs=y;
	}
    fclose(out);
    
    in=fopen("line2.txt","w");
    gets(s); fputs(s,in); fclose(in);
    out=fopen("line2.txt","r");
    while(fscanf(out,"%lld%lld",&x,&y)!=EOF)
    {
    	cntb++;
    	b[cntb].xs=x;
    	b[cntb].zs=y;
	}
    fclose(out);
    
    node *p=initiallist();
    for(int i=1;i<=cnta;i++)
    {
    	for(int j=1;j<=cntb;j++)
    	{
    	    long long xs=a[i].xs*b[j].xs;
    	    long long zs=a[i].zs+b[j].zs;
    	    sortinsert(p,xs,zs);
		}
	}
	visitlist(p);
	return 0;
}



