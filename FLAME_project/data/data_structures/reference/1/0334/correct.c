#include <stdio.h>
#include <string.h>
int n;
int tag[11]={0} ;
int number[11] ;
void pr(int t)
{
	int i;
	if(t==0)
	{
		for(i=0;i<n;i++)
		{
			printf("%d",number[i]) ;
			if(i!=n-1)
			printf(" ") ;
			else
			printf("\n") ;
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(tag[i]==0)
		{
			number[n-t]=i;
			tag[i]=1;
			pr(t-1) ;
			tag[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n) ;
	pr(n) ;
	return 0;
}



