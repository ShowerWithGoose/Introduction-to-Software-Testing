#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define error -1
typedef struct node
{
	int number;
	int power;
	struct node *link;
} Nodeptr;
Nodeptr *p,*q,*r;
int n,m,visit[101],w=0,Q[100],first=error,last=error;
typedef struct Node
{
 	int Nodeing;
 	Nodeptr *link;
} nodeptr;
nodeptr point[101];
void oper1 (nodeptr point[],int n,int m)
{
 	int i,j,vi,vj,Mid;
 	int a[101],b[101];
 	for(i=0;i<m;i++)
 	{
 		scanf("%d %d",&a[i],&b[i]);
 		if (a[i]>b[i])
 		{
 			Mid=a[i];
 			a[i]=b[i];
 			b[i]=Mid;
		 }
	 }
	 for (i=0;i<m-1;i++)
	 {
	 	for (j=0;j<m-i-1;j++)
	 	{
	 		if (a[j]>a[j+1])
	 		{
	 			Mid=a[j];
	 			a[j]=a[j+1];
	 			a[j+1]=Mid;
	 			Mid=b[j];
	 			b[j]=b[j+1];
	 			b[j+1]=Mid;
			 }
		 }
	 }
	 for (i=0;i<m-1;i++)
	 {
	 	for (j=0;j<m-i-1;j++)
	 	{
	 		if (b[j]>b[j+1]&&a[j]==a[j+1])
	 		{
	 			Mid=b[j];
	 			b[j]=b[j+1];
	 			b[j+1]=Mid;
			 }
		 }
	 }
 	for (i=0;i<n;i++)
 	{
 		point[i].Nodeing=i;
 		point[i].link=NULL;
    }
    for (i=0;i<m;i++)
    {
	 	p=(Nodeptr*)malloc(sizeof(Nodeptr));
	 	p->number=b[i];
	 	p->link=NULL;
	 	if (!point[a[i]].link)
        {
            point[a[i]].link=p;
        }
	 	else
	 	{
	 		q=point[a[i]].link;
	 		while(q->link)
	 		q=q->link;
	 		q->link=p;
        }
	 	p=(Nodeptr*)malloc(sizeof(Nodeptr));
	 	p->number=a[i];
	 	p->link=NULL;
	 	if (!point[b[i]].link)
        {
            point[b[i]].link=p;
        }
	 	else
	 	{
	 		q=point[b[i]].link;
	 		while(q->link)
            {
                q=q->link;
            }
	 		q->link=p;
        }
    }
}
void oper2(nodeptr point[],int visit[],int n)
{
 	int i;
 	for (i=0;i<n;i++)
    {
        visit[i]=0;
    }
 	for (i=0;i<1;i++)
    {
        oper4(point,i);
    }
}
void oper4(nodeptr point[],int v)
{
 	Nodeptr *p;
 	printf("%d ",point[v].Nodeing);
 	visit[v]=1;
  	for(p = point[v].link;p!=NULL; p=p->link)
    {
        if(!visit[p->number])
        {
            oper4(point,p->number);
        }
    }
}
void oper5(nodeptr  point[], int v)
{
    Nodeptr *p;
    printf("%d ",point[v].Nodeing);
    visit[v] = 1;
    Q[++last]=v;
    while(first!=last)
    {
         v =Q[++first];
         p = point[v].link;
         for(; p != NULL ; p = p->link )
         {
             if( !visit[p->number] )
            {
                    printf("%d ",p->number);
                    visit[p->number] = 1;
                    Q[++last]=p->number;
            }
         }

     }
}
void oper3(nodeptr point[],int visit[],int n)
{
 	int i;
 	for (i=0;i<n;i++)
    {
        visit[i]=0;
    }
 	oper5(point,0);
}
void delete(nodeptr point[],int n,int IT)
{
 	int i,k=error;
 	for (i=0;i<n;i++)
 	if (point[i].Nodeing==IT)
 	{
 		k=i;
 		break;
	 }
	 if (k!=error)
	 {
	 	p=point[k].link;
		 while(p!=NULL)
		 {
		 	r=p;
		 	p=p->link;
		 	free(r);
		 }
		 point[k].link=NULL;
		 for (i=0;i<n;i++)
		 {
			if (i==k)
			continue;
			p=point[i].link;
            while (p!=NULL)
		 	{
		 		if (p->number==k)
		 		{
		 			if (point[i].link==p)
		 			point[i].link=p->link;
		 			else
		 			q->link=p->link;
		 			r=p;
		 			p=p->link;
		 			free(r);
				 }
				 else
				 {
				 	q=p;
				 	p=p->link;
				 }
			 }
		 }
	 }
 }
 int main()
 {
    int i,k;
 	scanf("%d %d",&n,&m);
 	oper1(point,n,m);
 	scanf("%d",&k);
    oper2(point,visit,n);
    printf("\n");
    oper3(point,visit,n);
    printf("\n");
    delete(point,n,k);
    oper2(point,visit,n);
    printf("\n");
    oper3(point,visit,n);
    printf("\n");
 }















