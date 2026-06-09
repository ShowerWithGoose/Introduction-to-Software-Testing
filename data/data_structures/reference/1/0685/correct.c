#include <stdio.h>
int n;
int vis[20];
int s[20];

void dfs(int x)
{
	int i;
	if(x==n+1) {//考虑完了n位数,再进一次时打印
		for(int i=1; i<=n-1; i++){
			printf("%d ",s[i]);
		}
		printf("%d\n",s[n]);
		return;
	}
	for(i=1; i<=n; i++){
		if(vis[i]==0){
			vis[i]=1;
			s[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);	//第一个参数代表当前正在考虑第几个数
	return 0;
}



