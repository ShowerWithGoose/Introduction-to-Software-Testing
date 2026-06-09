#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void violet(int *num,int *flag,int m,int n)
{
	if(m==n) {
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag[i]=1;
				num[m]=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
		return ;
	}
	else {
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag[i]=1;
				num[m]=i;
				violet(num,flag,m+1,n);
				for(int i=m;i<=n;i++)
				flag[num[i]]=0;
				
			}
		}
	}
}


int main()
{
	int n,flag[15],layer=1,num[15];
	scanf("%d",&n);
	memset(flag,0,sizeof(flag));
	violet(num,flag,1,n);
	
	
	
	return 0;
}



