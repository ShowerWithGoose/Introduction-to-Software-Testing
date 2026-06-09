#include<stdio.h>
int isempty(int top)
{
	return top==-1;	
}
int isfull(int top)
{
	return top==99;
}
int num[100];
int top=-1;
int main()
{
	int i=0,j=0,k=0;
	int hold[1000];
	int x;
	
	do
	{
		scanf("%d",&x);
		hold[i++]=x;
	}while(x!=-1);
	for(j=0;j<i;j++)
	{
		if(hold[j]==1)
		{
			if(isfull(top))
			printf("error ");
			k=j+1;
			while(hold[k]==0||hold[k]==1||hold[k]==-1)
			{
				k++;
			}
			num[++top]=hold[k];
			j=k;
		}//ÈëÕ» 
		if(hold[j]==0)
		{
			if(isempty(top))
			printf("error ");
			else
			printf("%d ",num[top--]);
		}//³öÕ» 
	}
	return 0;
}

