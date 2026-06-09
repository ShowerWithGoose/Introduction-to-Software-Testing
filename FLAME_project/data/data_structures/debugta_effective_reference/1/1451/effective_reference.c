#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
	int* p,t;
	t=*x;
	*x=*y;
	*y=t;
}
void pline(int* a,int n)
{
	int i;
	for(i=0;i<n;i++){
		if(i==0) printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	putchar('\n');
}
void intcopy(int* a,const int* b,int n)
{
	int i;
	for(i=0;i<n;i++){
		a[i]=b[i];
	}
}
void pailie(int* a,int n,int len)
{
	int i,j,*b;
	if(len==n-1) pline(a,n);
	else{
		b=(int*)malloc(n*sizeof(int));
		intcopy(b,a,n);
		for(i=len;i<n;i++){
			if(i>len) swap(&b[i],&b[len]);
			pailie(b,n,len+1);
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




