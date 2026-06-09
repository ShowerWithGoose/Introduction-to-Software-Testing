#include<stdio.h>
#include<string.h>
int main() {
	int n,i,j,k,t;
	int num[6];
	int p[6][130][6];//permutation
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			num[i]=1;
		}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			num[i]=num[i]*j;
		}
	}
	//for(i=1;i<=n;i++) printf("num[%d]=%d\n",i,num[i]);
	
	p[1][1][1]=1;
	p[2][1][1]=1;
	p[2][1][2]=2;
	p[2][2][1]=2;
	p[2][2][2]=1;
	
	for(i=3;i<=n;i++)
	{
		for(j=1;j<=num[i-1];j++)
		{
			p[i][j][1]=1;
			for(k=2;k<=n;k++)
			{
				p[i][j][k]=p[i-1][j][k-1]+1;
			}	
		}
		j=1;
		for(t=1;t<=n-1;t++)
		{
			for(;j<=num[i-1]*t;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(p[i][j][k]==t) 
					{
						p[i][j+num[i-1]][k]=t+1;
						//printf("p[%d][%d][%d]=%d\n",i,j+num[i-1],k,p[i][j+num[i-1]][k]);	
					}
					else{
						if(p[i][j][k]==t+1) p[i][j+num[i-1]][k]=t;
						else p[i][j+num[i-1]][k]=p[i][j][k];
							//printf("%d\n",1);
					}	
				}		
			}
		}
	}
	
	for(j=1;j<=num[n];j++)
	{
		for(k=1;k<=n;k++)
		{	
			printf("%d",p[n][j][k]);
			printf("%c",' ');
		}
		printf("%c",'\n');
	}

	return 0;
} 

