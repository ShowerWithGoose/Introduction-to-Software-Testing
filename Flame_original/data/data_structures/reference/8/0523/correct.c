#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int s[105][105];
int flag[105];
int n,m;
void dfs(int);
void bfs();

int main(){
	int i,a,b,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		s[a][b] = s[b][a] = 1;
	}
	scanf("%d",&t);
	flag[0] = 1;
	dfs(0);
	putchar('\n');
	for(i=0;i<n;i++){
		flag[i] = 0;
	}
	bfs(0);
	putchar('\n');
	for(i=0;i<n;i++){
		flag[i] = 0;
	}
	for(i=0;i<n;i++){
		s[t][i] = s[i][t] = 0;
	}
	flag[0] = 1;
	dfs(0);
	putchar('\n');
	for(i=0;i<n;i++){
		flag[i] = 0;
	}
	bfs(0);
	putchar('\n');
	for(i=0;i<n;i++){
		flag[i] = 0;
	}
	return 0;
}

void bfs(int st){
	int que[200]={0};
	int head,tail,i;
	head = 0;
	tail = 1;
	que[0] = st;
	flag[0] = 1;
	while(head<tail){
		printf("%d ",que[head]);
		for(i=0;i<n;i++){
			if(flag[i]==0&&s[que[head]][i]==1){
				flag[i] = 1;
				que[tail] = i;
				tail++;
			}
		}
		head++;
	}
	return;
}
void dfs(int t){
	int i;
	printf("%d ",t);
	for(i=0;i<n;i++){
		if(flag[i]==0&&s[t][i]==1){
			flag[i] = 1;
			dfs(i);
		}
	}
	return;
}












