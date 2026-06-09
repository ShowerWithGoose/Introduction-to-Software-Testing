#include <stdio.h>
int n,j=0;
int flag[20];
int a[20];
void fun(int cnt)
{
	int i,k;
	if(cnt==0) return;
	for(i=1;i<=n;i++){
		if(flag[i]==1) continue;
		if(flag[i]==0){
			flag[i]=1;
			a[j++] = i;
			fun(cnt-1);
		}
		if(j==n){
			for(k=0;k<n;k++) printf("%d ",a[k]);
			printf("\n");
		}
		j--;flag[i]=0;
	}
}

int main()
{
	scanf("%d",&n);
	fun(n);
	return 0;
}

