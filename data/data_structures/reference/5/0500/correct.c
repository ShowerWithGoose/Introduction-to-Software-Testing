#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	int cnt;//系数 
	int poe;//指数 
};
int cmp(const void*p1,const void*p2)
{
	struct node *x1=(struct node*)p1;
	struct node *x2=(struct node*)p2;
	return x2->poe-x1->poe; 
}
struct node a[1500],b[1500],p[1500];
int main(){
	int i=0;
	int j=0;
	int z=0;
	int na=0,nb=0,nc=0;
	char x=0;
	while(x!='\n'){
		scanf("%d%d%c",&a[na].cnt,&a[na].poe,&x);
		na++; 
	};
	x=0;
	while(x!='\n'){
		scanf("%d%d%c",&b[nb].cnt,&b[nb].poe,&x);
		nb++;
	};	
	
	for(i=0;i<na;i++)
	{
		for(j=0;j<nb;j++)
		{
			p[z].cnt=a[i].cnt*b[j].cnt;
			p[z].poe=a[i].poe+b[j].poe;
			z++;
		}
	}
	qsort(p,z,sizeof(p[0]),cmp);
	i=0;
	j=0;
	for(i=0;i<z;i++)
	{
		for(j=i+1;j<z;j++)
		{
		if(p[i].poe==p[j].poe&&p[i].poe!=0)
	{
		p[j].cnt=p[j].cnt+p[i].cnt;
		p[i].cnt=0;
	}
}
}
	qsort(p,z,sizeof(p[0]),cmp);
	for(j=0;j<z;j++)
	{
		if(p[j].cnt!=0) 
			printf("%d %d ",p[j].cnt,p[j].poe);
		else
			continue; 
	}
	return 0;
	
} 

