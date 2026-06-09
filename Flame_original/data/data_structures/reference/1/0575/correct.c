#include<stdio.h>
#include<string.h>

int n,box[1005],card[1005];

void dealing(int i)//i=box
{
	int j;
	if(i>n)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",box[j]);
		}
		printf("\n");
		return;
	}
	
	for(j=1;j<=n;j++)
	{
		if(card[j]==0)
		{
			box[i]=j;
			card[j]=1;
			dealing(i+1);
			card[j]=0;
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	dealing(1);
	return 0;
}

