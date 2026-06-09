#include <stdio.h>
int main()
{
	int stack[114];
	int input[514];
	int i=0,j=0,k=0,judge=0,flag1=0,flag0=0;
	while(scanf("%d",&input[i])&&input[i]!=-1)
		i++;
	for(j=0;j<i;j++)
		if(input[j]==1)
		{
			flag1++;
			stack[k++]=input[j+1];
		}
		else if(input[j]==0)
		{
			if(flag1>0)
			{
				printf("%d ",stack[--k]);
				flag1--;
			}
			else
				printf("error ");
		}
		else if(input[j]==-1)
			break;
}

