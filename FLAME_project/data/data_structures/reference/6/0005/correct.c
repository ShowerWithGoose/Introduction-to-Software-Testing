#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int i=0,j=0,k=0;
int main(){
	int a[201],num[201];
	int n1=0,n0=0;
	k=0;
	
	for(i=0;i<201;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
		break;
		else if(a[i]==0)
		{
			k=k-1;
			
			if(k<0)
			{
				printf("error ");
				k=k+1;
			}
		
			else
			{
			printf("%d ",num[k]);
			num[k]=-9;	
			n0=n0+1;			
			}
			
		}
		else if(a[i]==1)
		{
			
			if(n1-n0>100)
			printf("error ");
			else
			{
			scanf("%d",&num[k]);
			k=k+1;
			n1=n1+1;				
			}

		}
	}

	
	return 0;
}

