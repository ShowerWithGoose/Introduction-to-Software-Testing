#include <stdio.h>

int n, a[50]; //a数组表示盒子编号
int flag[50];//判断扑克牌是否在手里，在手里为0
void DFS(int step) {//在第step个盒子处应怎么做
	int i;
	if (step == n + 1) { //判断边界，即站在n+1个盒子处
		for (i = 1; i <= n; i++)
			printf("%d ", a[i]);
		printf("\n");

		return;//返回DFS(n),即回到上一个盒子重新选择
	}
	for (i = 1; i <= n; i++) { //当前步骤：在第step个盒子前放牌，全部遍历
		if (flag[i] == 0) { //i号牌在手上
			a[step] = i;
			flag[i] = 1; //扑克牌不在手上了
			DFS(step + 1); //去下一个盒子放牌，一直递归到n个盒子全部放完
			flag[i] = 0; //收回刚放的牌
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	DFS(1);//先站在第1个盒子处选择
	getchar();
	return 0;
}
