#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void pl(int n,int depth,int a[],int flag[]){
	if(depth==n+1){
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
			printf("\n");
	}
	else
	for(int i=1;i<=n;i++){
		if(flag[i]==0)	{
			flag[i]=1;
			a[depth]=i;
			pl(n,depth+1,a,flag);
			flag[i]=0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[20];
	int flag[20];
	for(int i=0;i<20;i++)
	{
		a[i]=0;flag[i]=0;
	}
	pl(n,1,a,flag);

	return 0;	
}



