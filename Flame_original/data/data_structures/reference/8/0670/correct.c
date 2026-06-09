#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <ctype.h>

inline int read() { //快速读入，可以放在自己的缺省源里面 
	int x = 0; //数字位 
	int f = 1; //符号位 
	char ch = getchar(); //读入第一个字符 
	while (!isdigit(ch)) { //不是数字 
		if (ch == '-') { //特判负号 
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) { //读入连续数字 
		x = (x << 3) + (x << 1) + ch - '0'; // x * 10 == (x << 3) + (x << 1) 
		ch = getchar();
	}
	return x * f;
}

#define BIG 1000005
int q[BIG]; //为 BFS 提供队列操作的各种函数 
int head, tail;

void clear() { //清空队列 
	head = 1;
	tail = 0;
}

int front() { //取出队首 
	return q[head];
} 

void pop() { //弹出队首 
	++head;
}

void push(int x) { //放值进入队尾 
	q[++tail] = x;
}

int size() { //获得队列大小 
	return tail - head + 1;
}

#define maxn 105
int n, m;
int map[maxn][maxn]; //邻接矩阵记录路径 
int del[maxn]; //删除标记 
int vst[maxn]; //记录已经访问的结点 

void dfs(int x) {
	printf("%d ", x);
	vst[x] = 1;
	int i;
	for (i = 0; i < n; ++i) {
		if (!map[x][i] || del[i] || vst[i]) { //没有边，删除，或者访问过 
			continue;
		}
		dfs(i); //继续深搜 
	}
}

void bfs(int x) {
	clear();
	push(x);
	vst[x] = 1;
	printf("%d ", x);
	int i;
	while (size()) {
		int x = front(); //每次取出队首 
		pop();
		for (i = 0; i < n; ++i) {
			if (!map[x][i] || del[i] || vst[i]) { //没有边，删除，或者访问过 
				continue;
			}
			vst[i] = 1;
			printf("%d ", i);
			push(i); //将新的结点放入队列 
		}
	}
}

int main() {
	n = read();
	m = read();
	int i;
	for (i = 1; i <= m; ++i) {
		int x = read();
		int y = read();
		map[x][y] = map[y][x] = 1;
	} 
	memset(vst,0,sizeof vst);
	dfs(0);
	puts("");
	memset(vst,0,sizeof vst);
	bfs(0);
	puts("");
	del[read()] = 1; //读入被删除的点 
	memset(vst,0,sizeof vst);
	dfs(0);
	puts("");
	memset(vst,0,sizeof vst);
	bfs(0);
	puts("");
	return 0;
} 


