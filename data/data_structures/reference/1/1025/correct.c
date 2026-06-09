#include<stdio.h>
int mark[11]={0},str[11],k;
void fuc(int ,int );
int main()
{
scanf("%d",&k);
fuc(0,k);
return 0;
}
void fuc(int m,int n)
{int i;
if(n==0)
	{for(i=0;i<m-1;i++)
		printf("%d ",str[i]);
	printf("%d\n",str[i]);
	return ;
	}
for(i=0;i<k;i++)
	{if(mark[i]==0)
		{str[m]=i+1;
		mark[i]=1;
		fuc(m+1,n-1);
		mark[i]=0;
		}
	}
}



