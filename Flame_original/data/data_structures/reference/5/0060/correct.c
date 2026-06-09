#include<stdio.h>
#include<string.h>
int main()
{
	int j=0,k=0;
	struct cheng
	{
		int mult;
		int pow;
	}cheng[100];
	struct beicheng
	{
		int mult;
		int pow;
	}beicheng[100];
	int ans[3][10010];
	
	char s;
	while(1)
	{
		scanf("%d%d",&cheng[j].mult,&cheng[j].pow);
		s=getchar();
		if(s=='\n')
		{
			break;
		}
		j++;
	}
	while(1){
		scanf("%d%d",&beicheng[k].mult,&beicheng[k].pow);
		s=getchar();
		if(s=='\n')
		{
			break;
		}
		k++;
	}
	int x=0;
	for(int i=0;i<=j;i++)
	{
		for(int l=0;l<=k;l++)
		{
			ans[0][x]=0;
			ans[1][x]=cheng[i].mult*beicheng[l].mult;
			ans[2][x]=cheng[i].pow+beicheng[l].pow;
			x++;
		}
	}
	
	for(int i=0;i<x-1;i++)
	{
		for(int t=0;t<x-i-1;t++)
		{
			if(ans[2][t]<ans[2][t+1])
			{
				int hold1,hold2;
				hold1=ans[1][t];
				ans[1][t]=ans[1][t+1];
				ans[1][t+1]=hold1;
				
				hold2=ans[2][t];
				ans[2][t]=ans[2][t+1];
				ans[2][t+1]=hold2;
			}
		}
	}
	
	for(int i=0;i<x-1;i++)
	{
		if(ans[0][i]==0)
		{
			
		for(int l=i+1;l<x;l++)
		{
			if(ans[2][i]==ans[2][l] && ans[0][l]==0)
			{
				ans[1][i]=ans[1][i]+ans[1][l];
				ans[0][l]=1;
			}
		}
		}
	} 
	
	
	for(int i=0;i<x;i++)
	{
		if(ans[0][i]==0){
			printf("%d %d ",ans[1][i],ans[2][i]);
		}
	}




	return 0;
} 

