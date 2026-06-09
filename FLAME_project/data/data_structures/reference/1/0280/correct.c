#include<stdio.h>
int num[15];//num记录当前的全排列数列 
int flag[15];//flag记录当前各个数字有没有被用过	
int j;
int n;
void f(int j)
{
		int i;
		if(j==n+1)
		{
			for(i=1;i<=n;i++)
			{
			printf("%d ",num[i]);
			
			}printf("\n");
			return;
		}
			for(i=1;i<=n;i++)
			{
				if(flag[i]==0)
				{
					num[j]=i;
					flag[i]=1;
					f(j+1);
					flag[i]=0;	
				}
			}
	return;
}	
int main()
{
	scanf("%d",&n);
	f(1);
	return 0;
}			
		
		



	
		
		
	
		
	
		
			
		

	
	
		
	


