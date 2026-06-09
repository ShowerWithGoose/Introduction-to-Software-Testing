#include<stdio.h>
int n, a[12], visit[12];
void dfs(int x) {//x为全排列搜索的位数
	int i;
	if (x == n + 1) {
		for (i = 1; i <= n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
		return ;
	}
	for (i = 1; i <= n; i++) {
		if (visit[i] == 0) {//i这个数排过序吗
			visit[i] = 1;
			a[x] = i;//那第x位就是i了
			dfs(x + 1);//搜索下一层
			visit[i] = 0;//退回时i就没参加过排序了
			a[x] = 0; //清空第x位数据
		}
	}
}
int main() {
	scanf("%d", &n);
	dfs(1);
	return 0;
}



