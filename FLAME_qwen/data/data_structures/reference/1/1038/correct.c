#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
	int* p,t;
	t=*x;
	*x=*y;
	*y=t;
}
void pline(int* a,int len)
{
	int i;
	for(i=0;i<len;i++){
		if(i==0) printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	putchar('\n');
}
void intcopy(int* a,const int* b,int len)
{
	int i;
	for(i=0;i<len;i++){
		a[i]=b[i];
	}
}
void pailie(int* a,int len,int k)
{
	int i,j,*b;
	if(k==len-1) pline(a,len);
	else{
		b=(int*)malloc(len*sizeof(int));
		intcopy(b,a,len);
		for(i=k;i<len;i++){
			if(i>k) swap(&b[i],&b[k]);
			pailie(b,len,k+1);
		}
		free(b);
	}
}
int main()
{
	int n,*a,i;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=1;i<=n;i++) a[i-1]=i;
	pailie(a,n,0);
	return 0;
}




