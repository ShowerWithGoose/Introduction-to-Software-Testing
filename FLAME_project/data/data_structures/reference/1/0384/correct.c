#include <stdio.h>
#include <string.h>
#include <math.h>
int a[11],book[11];
int n;
void cnm(int step)
{
	int i;
	if(step==n+1){
		for(i=1;i<=n;i++){printf("%d ",a[i]); 
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			cnm(step+1);
			book[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	cnm(1);
	return 0;
}



