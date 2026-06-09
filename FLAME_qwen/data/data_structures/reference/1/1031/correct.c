#include<stdio.h>
long long a[11],re[11],max,v[11];
void dfs(long long step) {
	long long i;
	if(step==max) {
		for(i=0; i<step; i++) {
			printf("%d ",re[i]);
		}
		printf("\n");
	} else {
		for(i=0; i<max; i++) {
			if(v[i]==0) {
				re[step]=a[i];
				v[i]=1;
				dfs(step+1);
				v[i]=0;
			}
		}
	}
	return ;
}
int main() {
	long long i;
	scanf("%lld",&max);
	for(i=0;i<max;i++){
		a[i]=i+1;
		v[i]=0;
	}
	dfs(0);
	return 0;
}

