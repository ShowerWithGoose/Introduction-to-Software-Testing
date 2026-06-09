#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int G[120][120];
int v[120];
int a[120];
int ai=0;
void print(int nv){
	int i=0;
	for(i=0; i<nv; i++)
		printf("%d ", a[i]);
	printf("\n");
	ai=0;
	for(i=0; i<nv; i++)
		v[i]=0;
	return ;
}

void dfs(int n, int nv){
	a[ai++]=n;
	v[n]=1;
	int i;
	for(i=0; i<nv; i++){
		if(G[i][n]!=0&&v[i]!=1)
			dfs(i, nv);
	}
	return ;
}
void bfs(int nv){
	int head=0, rear=1;
	int i;
	a[0]=0;
	v[0]=1;
	while(head<rear){
		for(i=0; i<nv; i++){
			if(G[a[head]][i]!=0&&v[i]!=1){
				a[rear++]=i;
				v[i]=1;
			}
		}
		head++;
	}
	return ;
}

int main()
{
	int nv, ne;
	scanf("%d%d", &nv, &ne);
	int i, k, a, b;
	for(i=0; i<ne; i++){
		scanf("%d%d", &a , &b);
		G[a][b]=G[b][a]=1;
	} 
	scanf("%d", &k);
	dfs(0, nv);
	print(nv);
	bfs(nv);
	print(nv);
	for(i=0; i<nv; i++)
		G[i][k]=G[k][i]=0;
	dfs(0, nv);
	print(nv-1);
	v[nv-1]=0;
	bfs(nv);
	print(nv-1);
	return 0;
}
/*
9 9
0 1
0 5
1 2
2 6
5 6
2 3
3 4
6 7
7 8
1
*/


