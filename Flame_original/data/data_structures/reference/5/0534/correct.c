#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>


struct x{			 
	int xs;				 
	int zs;				 
};

typedef struct x xint;

xint a[20000],b[20000],c[20000];

int cmp(const void*p1,const void*p2)
{
	struct x *a=(struct x*)p1;
	struct x *b=(struct x*)p2;
	return b->zs-a->zs;
}


int main()
{
	char C;
	int i,j,k=0,n1=0,n2=0; 
	do   
	{
		scanf("%d%d%c",&a[n1].xs,&a[n1].zs,&C);
		n1++;
	}while(C!='\n');
	do
	{
		scanf("%d%d%c",&b[n2].xs,&b[n2].zs,&C);
		n2++;
	}while(C!='\n');
	
	qsort(a,n1,sizeof(xint),cmp); 
	qsort(b,n2,sizeof(xint),cmp);	
	
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			c[k].xs=a[i].xs*b[j].xs; 
			c[k].zs=a[i].zs+b[j].zs;
			k++;
		}
	}
	
	qsort(c,k,sizeof(xint),cmp);
	
	for(i=0;i<k;i++){
		if(c[i].zs == c[i+1].zs && c[i].zs!=0){
			c[i+1].xs+=c[i].xs;
			c[i].xs=0;
		}
	}
	qsort(c,k,sizeof(xint),cmp);
	for(i=0;i<k;i++){
		if(c[i].xs==0)	continue;
		else printf("%d %d ",c[i].xs,c[i].zs); 
	}
	return 0;
}


