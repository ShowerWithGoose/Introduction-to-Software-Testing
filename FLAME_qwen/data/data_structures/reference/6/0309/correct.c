#include<stdio.h>
#include<stdlib.h>
int NUM[100000]={0};
int stack[100000]={0};
int main()
{
	int n=0, k=0;
	do{
		scanf("%d",&NUM[n]);
		if(NUM[n]==-1)
			break;
		n++;
	}while(1);
	for(int i=0;i<n;i++)
	{
		if(NUM[i]==1)
		{
			stack[k]=NUM[i+1];
			i++;
			k++;
		}
		else if(NUM[i]==0)
		{
			if(k==0)
				printf("error ");
			else
			{
				printf("%d ",stack[k-1]);
				k--;
			}
		}
	}
	return 0;
}

