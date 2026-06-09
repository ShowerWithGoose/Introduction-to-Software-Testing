#include<stdio.h>
int n,temp[500],list[500];
void Perm(int k) 
{
	if(k==n)
	{
		for(int i=1 ;i<=n ;i++)
		printf("%d ",list[i]);
		printf("\n");
		return ;
	}
	 	for(int i=1;i<=n;i++)
	 	{
	 		if(temp[i]==0)
	 		{
	 			temp[i]=1;
	 			list[k+1]=i;
		 		Perm(k+1);
		 		temp[i]=0;
			}
		}
}
int main()
{
	scanf("%d",&n);
	Perm(0);
	return 0;
}




