#include<stdio.h>
#include<string.h>
int s[200][200],a[200]={0},b[200];
int n,m;
void c(int d)
{
	int k;
	printf("%d ",d);
	a[d]=1;
	for(k=0;k<n;k++)
		if (s[d][k] && !a[k]){
			c(k);
		}
}
int main()
{	
    int i,j,k,op1,op2;
    int head=0,last=1;
	scanf("%d %d",&n,&m);
	for(k=0;k<m;k++)
	{
		scanf("%d %d",&i,&j);
		s[i][j]=1;
		s[j][i]=1;
	}
	c(0);
	puts("");
	
	memset(a,0,sizeof(a));
	b[head]=0;
	while(head<=last) 
	{
		op2=b[head];
		head++;
		if(a[op2])	
		continue;
		else
		{
			printf("%d ",op2); 
			a[op2]=1;
			for(k=0;k<n;k++)
				if (s[op2][k]&&!a[k])
					b[last++]=k;
		}
	}
	puts("");
	
	scanf("%d",&op1);
	memset(a,0,sizeof(a));
	a[op1]=1;
	c(0);
	puts("");
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[op1]=1;
	head=0,last=1;
	b[head]=0;
	while(head<=last) 
	{
		op2=b[head];
		head++;
		if(a[op2])	
		continue;
		else
		{
			printf("%d ",op2); 
			a[op2]=1;
			for(k=0;k<n;k++)
				if (s[op2][k]&&!a[k])
					b[last++]=k;
		}
	}
	puts("");
	return 0;
}

