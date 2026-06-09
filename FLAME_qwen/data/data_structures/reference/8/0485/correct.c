#include<stdio.h>

int in[110][110],has[110];	//in为1时有 has为1时已输出
int num_poi, num_lie;
int dec = -1;
void rep() {
	for (int i = 0; i < 110; i++) {
		has[i] = 0;
	}
}
void dfs(int loc) {
	if (!has[loc]) {
		has[loc] = 1;
		printf("%d ", loc);
	}
	for (int i = 0; i < num_poi; i++) {
		if (i == dec) {
			continue;
		}
		if (in[loc][i]&&!has[i]) {
			dfs(i);
		}
	}
}
void bfs(int loc) {
	int que[110] = { 0 }, rear = 0, fro = 0;
	int out;

	printf("%d ", loc);
	que[rear++] = loc;
	has[loc] = 1;
	while(rear!=fro){
		out = que[fro++];
			for (int i = 0; i < num_poi; i++) {
				if (i == dec) {
					continue;
				}
				if (in[out][i]&&!has[i]) {	//有且未访问
					que[rear++] = i;	//访问中
					printf("%d ", i);	//访问中
					has[i] = 1;		//已访问
				}
			}
	}
}

int main()
{
	

	scanf("%d %d", &num_poi, &num_lie);
	for (int i = 0,a,b; i < num_lie; i++) {
		scanf("%d %d", &a, &b);
		in[b][a] = 1;
		in[a][b] = 1;
	}
	dfs(0);
	printf("\n"); rep();
	bfs(0);
	printf("\n"); rep();
	scanf("%d", &dec);
	for (int i = dec; i <= num_poi - 1; i++) {
		in[dec][i] = 0;
	}
	has[dec] = 1;
	dfs(0);
	printf("\n"); rep();
	bfs(0);
	printf("\n"); 
	return 0;
}
