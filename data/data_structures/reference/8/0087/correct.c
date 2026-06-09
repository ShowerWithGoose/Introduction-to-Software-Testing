#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100][100];
int visited[100];
int n, en;

void create();
void del(int x);
void dfs(int x);
void bfs(int x);
int main()
{
	create();
	int d;
	scanf("%d", &d);
	dfs(0);
	putchar('\n');
	memset(visited, 0, 100);//memset是对字符串的操作
	bfs(0);
	putchar('\n');
	memset(visited, 0, 100);
	del(d);
	dfs(0);
	putchar('\n');
	memset(visited, 0, 100);
	bfs(0);
	putchar('\n');
	memset(visited, 0, 100);
}

void create()
{
	scanf("%d%d", &n, &en);
	for(int i=0; i<en; i++){
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		a[v1][v2] = a[v2][v1] = 1;
	}
}

void del(int x)
{
	for(int i=0; i<n; i++){
		if(a[x][i]){
			a[x][i] = a[i][x] = 0;
		}
	}
}

void dfs(int x)
{
	if(visited[x]==0){
		visited[x] = 1;
		printf("%d ", x);
		for(int i=0; i<n; i++){
			if(a[x][i]){
				dfs(i);
			}
		}
	}
}

int queue[100];
int f = 0;
int r = -1;
int cnt=0;
void push(int x)
{
	queue[++r] = x;
	cnt++;
}

int pop()
{
	cnt--;
	int t = queue[f];
	queue[f++] = 0;
	return t;
}

void bfs(int x)
{
	push(x);
	visited[0] = 1;
	while(cnt){
		int tmp = queue[f];
		for(int i=0; i<n; i++){
			if(a[tmp][i]&&visited[i]==0){
				push(i);
				visited[i] = 1;//入队时就标记 不是在print时标记
			}
		}
		
		printf("%d ", pop());
	}
	
	
	
}
