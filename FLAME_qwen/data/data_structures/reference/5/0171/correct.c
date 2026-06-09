#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
	int k1;
	int k2;
}a[10000],b[10000],c[10000],e[10000];
void change(int*m,int*n)
{
	int tmp;
	tmp=*m;
	*m=*n;
	*n=tmp;
}
int main() 
{
	char d=' ';
	int i,j,k,q=1,p=1,numa=1,numb=1;
	while(d!='\n') 
	{
		scanf("%d%d%c",&a[numa].k1,&a[numa].k2,&d);
		numa++;
	}
	d=' ';
	while(d!='\n') 
	{
		scanf("%d%d%c",&b[numb].k1,&b[numb].k2,&d);
		numb++;
	}
	numa-=1;
	numb-=1;
  for(i=1;i<=numa;i++)
  for(j=1;j<=numb;j++)
  {
    c[q].k1=a[i].k1*b[j].k1;
    c[q].k2=a[i].k2+b[j].k2;
    q++;
	}
	for(i=1;i<q;i++)
	for(j=i+1;j<=q;j++)
	{
		if(c[i].k2==c[j].k2)
		{
			c[i].k1+=c[j].k1;
			c[j].k1=0;
			c[j].k2=0;
		}
	}
	for(i=1;i<=q;i++)	
	{
		if(c[i].k1!=0)
		{
		  e[p].k1=c[i].k1;	
		  e[p].k2=c[i].k2;
		  p++;
		}
	}
	k=1;
	for(i=1;k;i++)
	{
		k=0; 
		for(j=1;j<p-1;j++)
	  if(e[j].k2<e[j+1].k2)
    {
      change(&e[j].k2,&e[j+1].k2);	
      change(&e[j].k1,&e[j+1].k1);
			k=1;	
		}
  }
	for(i=1;i<=p-1;i++)
	printf("%d %d ",e[i].k1,e[i].k2);
}      


