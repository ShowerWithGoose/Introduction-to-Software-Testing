#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*p1,const void*p2);
typedef struct{
	int xi;
	int e;
}define;
int main()
{
	define a1[2000]={0},a2[2000]={0},a3[2000]={0};
	int i=0,n1=0,n2=0;
	char ch=' ';
	while(ch==' ')
	{
		scanf("%d %d%c",&a1[n1].xi,&a1[n1].e,&ch);
		n1++;
	}
	ch=' ';
	
	
	while(ch==' ')
	{  
		scanf("%d %d%c",&a2[n2].xi,&a2[n2].e,&ch);
		n2++;
	}
	qsort(a1,n1,sizeof(define),cmp);
	qsort(a2,n2,sizeof(define),cmp);
	int j,k=0,m=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			a3[k].xi=a1[i].xi*a2[j].xi;
			a3[k].e=a1[i].e+a2[j].e;
			k++; 
		}
	}
	m=k;
	qsort(a3,k,sizeof(define),cmp);
	for(i=0;i<k;i++)
	{
		if((a3[i].e==a3[i+1].e)&&(a3[i].e!=0))
		{
			a3[i+1].xi=a3[i+1].xi+a3[i].xi;
			a3[i].xi=0;
			m--;
		}
	}
	qsort(a3,k,sizeof(define),cmp);
	for(i=0;i<k;i++)
	{
		if(a3[i].xi!=0)
		printf("%d %d ",a3[i].xi,a3[i].e);
	}
	
	return 0;
}
int cmp(const void*p1,const void*p2)
{
     define *a=( define*)p1;
     define *b=( define*)p2;
    return b->e-a->e;
}


