#include<stdio.h>
struct A
{
	int num;
	int m;
}a[500],b[500],ans[250000];
int cmp(const void *a,const void *b)
	{
	struct A *a1 = (struct A*)a;
	struct A *b1 = (struct A*)b;
	if((a1->m)<=(b1->m)) 
		return 1;
	return -1;
	}
int main()
{
	int i,j,n,la,lb;
	char c;
	i=0;
	while(~scanf("%d %d%c",&a[i].num,&a[i].m,&c))
	{
		i++;
		la = i;
		if(c=='\n')
			break;
	}
	i=0;
	while(~scanf("%d %d%c",&b[i].num,&b[i].m,&c))
	{
		i++;
		lb = i;
		if(c=='\n')
			break;
	}
	n=0;
	for(i=0;i<la;i++)
	{
		for(j=0;j<lb;j++)
		{
			ans[n].num=a[i].num*b[j].num;
			ans[n].m =a[i].m+b[j].m;
			n++;
		}
	}
	qsort(ans,n,sizeof(struct A),cmp);
	for(i=0;i<n;i++)
	{
		if(ans[i].m==ans[i+1].m)
		{
			ans[i+1].num=ans[i].num+ans[i+1].num;
			ans[i].num=0;
		}
	}
	for(i=0;i<=n;i++)
	{	
		if(ans[i].num!=0)
			printf("%d %d ",ans[i].num,ans[i].m);
	}
		
	return 0;
}
/*
head = (struct A *)malloc(sizeof(struct A));
head->next = NULL;
p = head;
while(~(scnaf("%d %d",&a,&b)))
{
	q = (struct A *)malloc(sizeof(struct A));
	q->num = a;
	q->m = b;
	p->next = q;
	p = q;
}*/



