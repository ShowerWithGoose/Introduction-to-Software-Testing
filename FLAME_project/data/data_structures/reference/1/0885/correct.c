#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 20
int tag[MAXSIZE],con[MAXSIZE],n;
void dfs(int k)
{
	int i;
	if(k==n+1)
	{
		for(i=1;i<=n;i++)
		printf("%d ",con[i]);
		printf("\n");
	}
	else {
		for(i=1;i<=n;i++)
		{
			if(tag[i]==0)
			{
				con[k]=i;
				tag[i]=1;
				dfs(k+1);
				con[k]=0;
				tag[i]=0;
			}
		}		
	}

}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	dfs(1);
	return 0;
}


