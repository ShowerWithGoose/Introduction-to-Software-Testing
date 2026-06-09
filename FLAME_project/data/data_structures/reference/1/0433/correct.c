#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int book[11],a[11];
int x;
void pai(int step)
{
	int i;
	if(step==x+1)
	{
		for(i=1;i<=x;i++)
			printf("%d ",a[i]);
		printf("\n");
	return;
	}
	else
	{
		for(i=1;i<=x;i++)
		{
			if(book[i]==0)
			{
				a[step]=i;
				book[i]=1;
				pai(step+1);
				book[i]=0;
			}
		}
	}
	
}
int main()
{
	scanf("%d",&x);
	pai(1); 
	return 0;
}

