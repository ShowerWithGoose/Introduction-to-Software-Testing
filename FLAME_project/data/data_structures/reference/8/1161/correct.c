#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
int n,m,v[101][101],q[101],h,e,book[101],i,j,t1,t2,t;
void dfs(int pos) {
	printf("%d ",pos);
	int j;
	for(j=0; j<n; j++) {
		if(v[pos][j]&&!book[j]&&pos!=j) {
			book[j]=1;
			dfs(j);
		}
	}
}
void bfs() {
	int j,now;
	while(h<=e) {
		now=q[h];
		printf("%d ",now);
		h++;
		for(j=0; j<n; j++) {
			if(v[now][j]&&!book[j]&&now!=j) {
				book[j]=1;
				e++;
				q[e]=j;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&t1,&t2);
		v[t1][t2]=1;
		v[t2][t1]=1;
	}

	book[0]=1;
	dfs(0);
	for(i=1; i<n; i++)
		book[i]=0;
	printf("\n");

	q[1]=0;
	h=1,e=1;
	bfs();
	for(i=1; i<n; i++) {
		book[i]=0;
		q[i]=0;
	}
	printf("\n");

	scanf("%d",&t);
	book[0]=1;
	book[t]=1;
	dfs(0);
	for(i=1; i<n; i++)
		book[i]=0;
	printf("\n");

	q[1]=0;
	h=1,e=1;
	book[t]=1;
	bfs();
	for(i=1; i<n; i++) {
		book[i]=0;
		q[i]=0;
	}
	printf("\n");

	return 0;
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/



