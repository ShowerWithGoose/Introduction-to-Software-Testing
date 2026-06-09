#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int n,a[100],b[100]={0};
void pailie(int step){
	int i;
	if(step==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
			a[step]=i;
			b[i]=1;
			pailie(step+1);
			b[i]=0;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	getchar();
	pailie(1);
 	return 0;
}


