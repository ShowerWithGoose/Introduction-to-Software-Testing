#include<stdio.h>
int m,judge[500],list[500];
void Perm(int k) 
{
	if(k==m)
	{
		for(int i=1 ;i<=m ;i++)
		printf("%d ",list[i]);
		printf("\n");
		return ;
	}
	 	for(int i=1;i<=m;i++)
	 	{
	 		if(judge[i]==0)
	 		{
	 			judge[i]=1;
	 			list[k+1]=i;
		 		Perm(k+1);
		 		judge[i]=0;
			}
		}
}
int main()
{
	scanf("%d",&m);
	Perm(0);
	return 0;
}




