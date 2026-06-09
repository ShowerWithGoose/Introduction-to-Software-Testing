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
node f1[100005],f2[100005];
int num_a,num_b;
long long x,y;
node *initiallist()
{
	node *headnode=(node *)malloc(sizeof(node));
	memset(headnode,0,sizeof(node));
	return headnode;
}
void insertlist(node *head,long long xs,long long zs)
{
	node *q=(node *)malloc(sizeof(node));
	q->xs=xs;
	q->zs=zs;
	q->next=head->next;
	head->next=q;
}
void sortinsert(node *headnode,long long xs,long long zs)
{
	node *head=headnode;
	while(head->next!=NULL)
	{
		if(head->next->zs<zs) break;
		if(head->next->zs==zs)
		{ 
		    head->next->xs+=xs;
			return;
		}
		head=head->next;
	} 
	insertlist(head,xs,zs);
}
int visitlist(node *headnode)
{
	int cnt=0;
	node *head=headnode;
	while(head->next!=NULL) 
	{
		head=head->next;
		cnt++;
		if(head->xs!=0)
		    printf("%lld %lld ",head->xs,head->zs);
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
    	num_a++;
    	f1[num_a].xs=x;
    	f1[num_a].zs=y;
	}
    fclose(out);
    
    in=fopen("line2.txt","w");
    gets(s); fputs(s,in); fclose(in);
    out=fopen("line2.txt","r");
    while(fscanf(out,"%lld%lld",&x,&y)!=EOF)
    {
    	num_b++;
    	f2[num_b].xs=x;
    	f2[num_b].zs=y;
	}
    fclose(out);
    
    node *head=initiallist();
    for(int i=1;i<=num_a;i++)
    {
    	for(int j=1;j<=num_b;j++)
    	{
    	    long long xs=f1[i].xs*f2[j].xs;
    	    long long zs=f1[i].zs+f2[j].zs;
    	    sortinsert(head,xs,zs);
		}
	}
	visitlist(head);
	return 0;
}



