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
int n,e,time[101],w=0,Q[100],first=error,last=error;
typedef struct Node
{
 	int Nodeing;
 	Nodeptr *link;
} nodeptr;
nodeptr para[101];
void oper1 (nodeptr para[],int n,int e)
{
 	int i,j,vi,vj,Mid;
 	int a[101],b[101];
 	for(i=0;i<e;i++)
 	{
 		scanf("%d %d",&a[i],&b[i]);
 		if (a[i]>b[i])
 		{
 			Mid=a[i];
 			a[i]=b[i];
 			b[i]=Mid;
		 }
	 }
	 for (i=0;i<e-1;i++)
	 {
	 	for (j=0;j<e-i-1;j++)
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
	 for (i=0;i<e-1;i++)
	 {
	 	for (j=0;j<e-i-1;j++)
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
 		para[i].Nodeing=i;
 		para[i].link=NULL;
    }
    for (i=0;i<e;i++)
    {
	 	p=(Nodeptr*)malloc(sizeof(Nodeptr));
	 	p->number=b[i];
	 	p->link=NULL;
	 	if (!para[a[i]].link)
        {
            para[a[i]].link=p;
        }
	 	else
	 	{
	 		q=para[a[i]].link;
	 		while(q->link)
	 		q=q->link;
	 		q->link=p;
        }
	 	p=(Nodeptr*)malloc(sizeof(Nodeptr));
	 	p->number=a[i];
	 	p->link=NULL;
	 	if (!para[b[i]].link)
        {
            para[b[i]].link=p;
        }
	 	else
	 	{
	 		q=para[b[i]].link;
	 		while(q->link)
            {
                q=q->link;
            }
	 		q->link=p;
        }
    }
}
void oper2(nodeptr para[],int time[],int n)
{
 	int i;
 	for (i=0;i<n;i++)
    {
        time[i]=0;
    }
 	for (i=0;i<1;i++)
    {
        oper4(para,i);
    }
}
void oper4(nodeptr para[],int v)
{
 	Nodeptr *p;
 	printf("%d ",para[v].Nodeing);
 	time[v]=1;
  	for(p = para[v].link;p!=NULL; p=p->link)
    {
        if(!time[p->number])
        {
            oper4(para,p->number);
        }
    }
}
void oper5(nodeptr  para[], int v)
{
    Nodeptr *p;
    printf("%d ",para[v].Nodeing);
    time[v] = 1;
    Q[++last]=v;
    while(first!=last)
    {
         v =Q[++first];
         p = para[v].link;
         for(; p != NULL ; p = p->link )
         {
             if( !time[p->number] )
            {
                    printf("%d ",p->number);
                    time[p->number] = 1;
                    Q[++last]=p->number;
            }
         }

     }
}
void oper3(nodeptr para[],int time[],int n)
{
 	int i;
 	for (i=0;i<n;i++)
    {
        time[i]=0;
    }
 	oper5(para,0);
}
void delete(nodeptr para[],int n,int IT)
{
 	int i,k=error;
 	for (i=0;i<n;i++)
 	if (para[i].Nodeing==IT)
 	{
 		k=i;
 		break;
	 }
	 if (k!=error)
	 {
	 	p=para[k].link;
		 while(p!=NULL)
		 {
		 	r=p;
		 	p=p->link;
		 	free(r);
		 }
		 para[k].link=NULL;
		 for (i=0;i<n;i++)
		 {
			if (i==k)
			continue;
			p=para[i].link;
            while (p!=NULL)
		 	{
		 		if (p->number==k)
		 		{
		 			if (para[i].link==p)
		 			para[i].link=p->link;
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
    int i,x;
 	scanf("%d %d",&n,&e);
 	oper1(para,n,e);
 	scanf("%d",&x);
    oper2(para,time,n);
    printf("\n");
    oper3(para,time,n);
    printf("\n");
    delete(para,n,x);
    oper2(para,time,n);
    printf("\n");
    oper3(para,time,n);
    printf("\n");
 }















