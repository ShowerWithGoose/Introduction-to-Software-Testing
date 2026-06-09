#include<stdio.h>
void p(int *a,int *b,int n,int c);
int main()
   {int n,i;
	int a[100]={0};
	int b[100]={0};
	scanf("%d",&n);
	p(a,b,n,1);
	return 0;
   }

void p(int *a,int *b,int n,int c)
   {int i;
	if(c==n+1)
	   {for(i=1;i<=n;i++)
		    printf("%d ",a[i]);
		printf("\n");
		return;
	   }
	for(i=1;i<=n;i++)
	   {if(b[i]==0)
		   {b[i]=1;
			a[c]=i;
			p(a,b,n,c+1);
			b[i]=0;
		   }
	   }
   }

