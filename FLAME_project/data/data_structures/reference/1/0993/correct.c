#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int ans[21];
int flag[21];
int n;
void dfs(int x)
{	
	int i;
	if(x == n){
		for(i = 1;i <= n;i ++){
			if(flag[i] == 0){
				ans[x] = i;
			}
		}
		for(i = 1;i <= n;i ++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	else {
		for(i = 1;i <= n;i ++){
			if(flag[i] == 0)
			{	
				flag[i] = 1;
				ans[x] = i;
				dfs(x + 1);
				flag[i] = 0;
			}
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	dfs(1);
	return 0;	
}



