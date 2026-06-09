#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int n;
int flag[20];
int str[20];



void work(int x,int y)
{
	if(y==0)
	{
		int j;
		for(j=0;j<n;j++)
		{
			printf("%d ",str[j]);
		}
		printf("\n");
	}
	else
	{
		int i;
		for(i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				str[x]=i;
				work(x+1,y-1);
				flag[i]=0;
			}
		}
	}
}



int main()
{
	memset(flag,0,sizeof(flag));
	memset(str,0,sizeof(str));
	//freopen("damn.txt","r",stdin);//
	
	scanf("%d",&n);
	
	work(0,n);
	
	return 0;
}

