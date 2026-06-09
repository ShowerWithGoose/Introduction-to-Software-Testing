#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int m,n,cnt=0;
int a[105][105];
int p[105];
int t[105];
void dfs(int x) {
	int flag=0,i,j;
	for(i=0; i<m; i++) {
		if(a[x][i]==1&&p[i]==1) {
			flag=0;
			p[i]=0;
			for(j=0; j<m; j++) {
				if(p[j]==1)flag=1;
			}
			if(flag==1)printf("%d ",i);
			else printf("%d\n",i);
			dfs(i);
		}
	}
	return ;
}
void bfs(int x) {
	int flag=0,i,j,g;
	for(i=0; i<m; i++) {
		if(a[x][i]==1&&p[i]==1) {
			flag=0;
			p[i]=0;
			t[cnt]=i;
			cnt++;
			for(j=0; j<m; j++) {
				if(p[j]==1) {
					flag=1;
					break;
				}
			}
			if(flag==1)printf("%d ",i);
			else {
				printf("%d\n",i);

			}
		}
	}
	g=t[0];
	for(j=0; j<cnt; j++) {
		t[j]=t[j+1];
	}
	cnt--;
	flag=0;
	for(j=0; j<m; j++) {
		if(p[j]==1) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		return 0;
	}
	bfs(g);
}
int main() {
	int l,i,j,k,x,y;
	scanf("%d %d\n",&m,&n);
	for(i=0; i<n; i++) {
		scanf("%d %d\n",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(i=1; i<m; i++) {
		p[i]=1;
	}

	scanf("%d",&k);
	printf("0 ");
	dfs(0);
	for(i=1; i<m; i++) {
		p[i]=1;
	}
	printf("0 ");
	bfs(0);


	for(i=0; i<m; i++) {
		a[i][k]=0;
		a[k][i]=0;
	}
	for(i=1; i<m; i++) {
		p[i]=1;
	}
	p[k]=0;
	printf("0 ");
	dfs(0);
	for(i=1; i<m; i++) {
		p[i]=1;
	}
	p[k]=0;
	printf("0 ");
	for(i=0;i<m;i++){
		t[i]=0;
	}
	cnt=0;
	bfs(0);
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
/*
9 9
0 1
1 2
2 3
3 4
2 6
0 5
5 6
6 7
7 8
1
*/


