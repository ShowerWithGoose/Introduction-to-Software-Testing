#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
int n;
int m[11];
int k[11];
void dfs(int x){
	int i;
	if(x>n){
		for(i=1;i<=n;i++){
			printf("%d",m[i]);
			if(i<n) putchar(' ');
			else putchar('\n');
		}
	}else{
		for(i=1;i<=n;i++){
			if(!k[i]){
				k[i]=1;
				m[x]=i;
				dfs(x+1);
				k[i]=0;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}


