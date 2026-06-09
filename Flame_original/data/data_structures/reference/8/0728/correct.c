#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <ctype.h>

inline int read() { 
	int x = 0; 
	int f = 1; 
	char ch = getchar();  
	while (!isdigit(ch)) { 
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {  
		x = (x << 3) + (x << 1) + ch - '0'; 
		ch = getchar();
	}
	return x * f;
}

#define BIG 1000005
int q[BIG]; 
int head, tail;

void clear() { 
	head = 1;
	tail = 0;
}

int front() { 
	return q[head];
} 

void pop() {
	++head;
}

void push(int x) { 
	q[++tail] = x;
}

int size() {  
	return tail - head + 1;
}

#define maxn 105
int n, m;
int map[maxn][maxn];  
int del[maxn]; 
int vst[maxn]; 

void dfs(int x) {
	printf("%d ", x);
	vst[x] = 1;
	int i;
	for (i = 0; i < n; ++i) {
		if (!map[x][i] || del[i] || vst[i]) { 
			continue;
		}
		dfs(i); 
	}
}

void bfs(int x) {
	clear();
	push(x);
	vst[x] = 1;
	printf("%d ", x);
	int i;
	while (size()) {
		int x = front(); 
		pop();
		for (i = 0; i < n; ++i) {
			if (!map[x][i] || del[i] || vst[i]) { 
				continue;
			}
			vst[i] = 1;
			printf("%d ", i);
			push(i); 
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
	del[read()] = 1; 
	memset(vst,0,sizeof vst);
	dfs(0);
	puts("");
	memset(vst,0,sizeof vst);
	bfs(0);
	puts("");
	return 0;
} 

