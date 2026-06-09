#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[11];
char ans[11];

void Arrangement(int n, int step)
{
	if(step >= n) return;
	int i;
	for(i=1;i<=n;i++){
		if(!a[i]){
			ans[step]=i+'0';
			a[i]=1;
			Arrangement(n,step+1);
			a[i]=0;
		}
	}
	if(step==n-1){
		for(i=0;i<n;i++){
			printf("%c ",ans[i]);
		}
		putchar('\n');
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	Arrangement(n,0);
	return 0;
}



