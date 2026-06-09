#include<stdio.h>
#include<string.h>
char str0[10000],str1[10000];
int n;
void sort(int a)
{
	if(a==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",str1[i]);
		}
		printf("\n");
		return;	
	}
	for(int i=1;i<=n;i++)
	{
		if(!str0[i])
		{
			str0[i]=1;
			str1[a]=i;
			sort(a+1);
			str0[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	sort(1);
} 

