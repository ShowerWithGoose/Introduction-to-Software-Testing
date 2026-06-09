#include <stdio.h>
#include <math.h>
#include <string.h>


int n;
//void pailie(int k){
//	if k == n : printall; return 
//	a[0] ~ a[k-1]
//	for i=1 i<=n i++
//		if i in a[0] a[k-1] continue
//		a[k] = i
//		pailie(k+1)
		
//}
void pailie(int k,int a[])
{
	if(k>=n)
	{
		for(int i=1;i<=k;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	else{
		for(int i=1;i<=n;i++)
		{
//			int j;
//			for(j=0;j<=k;j++)
//			{
//				if(i==a[j])
//					break;
//			}
////			printf("%d, %d, %d\n", i, j,k);
//			if(j==k+1)
//			{
//				a[k+1]=i;
//				pailie(k+1,a);
//			}
			int flag = 0;
			for (int j = 0; j<=k ; j++){
				if (a[j]==i) flag = 1; 
			}
			if (flag) continue;
			a[k+1] = i;
			pailie(k+1,a);
		}
	}
}
int main()
{
	int str[10]={};
	scanf("%d",&n);
	pailie(0,str);
	
	return 0;
}

