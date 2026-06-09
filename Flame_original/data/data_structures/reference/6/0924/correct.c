#include <stdio.h>
int main()
{
	int a[100], b[100], i=0, k, j=0;
	while(1)
	{
		scanf("%d", &a[i]);
		if(a[i]==-1)
		break;
		i++;	
	}
		for(k=0;k<=i;k++)
		{
			if(a[k]==1)
			{
			j++;
			b[j]=a[k+1];
		
		}
			if(a[k]==0)
			{
				if(j==0)
				printf("error ");
				else
				{
				printf("%d ", b[j]);
				j--;
			}
			}
		}
		return 0;
	 } 

