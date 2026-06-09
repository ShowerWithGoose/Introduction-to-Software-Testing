#include<stdio.h>


int main()
{
	int top=0;
	int i=0;
	int k=0;
	int s[200]={0};
	int s1[100]={0};
	int s2[100]={0};
	while(scanf("%d",&s[i])!=EOF)
	{
		if(s[i]==1)
		{
			if(top==100)
			{
				s2[k++]=0;
			}
			else
			{
			  scanf("%d",&s1[top]);
			  top++;	
			}
		}
		if(s[i]==0)
		{
			if(top==0)
			{
				s2[k++]=0;
			}
			else
			{
				s2[k++]=s1[top-1];
				top--;
			}
		}
		if(s[i]==-1)
		{
			break;
		}
	}
	for(i=0;i<k;i++)
	{
		if(s2[i]==0)
		{
			printf("error ");
		}
		else
		{
			printf("%d ",s2[i]);
		}
	}
	return 0;
}

