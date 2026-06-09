#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*p1,const void*p2);
struct duoxiangshi{
	int a;
	int b;
	int flag;
};
typedef struct duoxiangshi duo;
int main()
{
	duo x1[1000],x2[1000],x3[100000],x4[10000];
	int t,p,q=0;
	int i=1,k=1;
	char m;
	
	while(1)
	{
		scanf("%d %d",&x1[i].a ,&x1[i].b );
		if((m=getchar())=='\n')break;
		
		i++;
	}
	
	while(1)
	{
		scanf("%d %d",&x2[k].a ,&x2[k].b );
		//m=getchar();
		if((m=getchar())=='\n')break;
		
		k++;
	}
	
	for(t=1;t<=i;t++)
	{
		for(p=1;p<=k;p++)
		{
			q++;
			x3[q].a =x1[t].a *x2[p].a ;
			x3[q].b =x1[t].b +x2[p].b ;
			x3[q].flag =0;
		}
	}
	
	for(t=1,i=0;t<=q;t++)
	{
		if(x3[t].flag ==1)
		continue;
		for(p=1;(t+p)<=q;p++)
		{
			if(x3[t+p].flag ==1)
			continue;
			if(x3[t].b ==x3[t+p].b )
			{
				x3[t].a +=x3[t+p].a ;
				x3[t+p].flag =1; 
			}
		}
		
		x4[i].a =x3[t].a ;
		x4[i].b =x3[t].b ;
		i++;
	}
	
	qsort(x4,i,sizeof(duo),cmp);
	
	for(k=0;k<i;k++)
	{
		printf("%d %d ",x4[k].a ,x4[k].b );
	}
	
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	duo *m=(duo*)p1;
	duo *n=(duo*)p2;
	return n->b -m->b ;
}

