#include<stdio.h>
#include<string.h>
int main() {
	int an[15] = {0};//这段代码只能解决1-9 
	int N, max_n = 0, min_n = 0, tempt, flag = 0;
	scanf("%d", &N);//输入数字 
	for (int i = 1; i <= N; i++) {
		max_n = N + 1 - i + max_n * 10;//最大值为nn-1n-2......(987654321)
			min_n = i + min_n * 10;//最小为123456789 
		printf("%d ",i); 
	}
	for (int i = min_n+1; i <= max_n; i++) {
		flag = 0;
		tempt = i;
		for (int j = 1; j <= N; j++) {
			an[j] = tempt % 10;
			tempt /= 10;//将每一位数存入数组N中 (逆序) 
			if (an[j] > N || an[j] == an[j - 1]) {//初步判断是否合乎标准，减少后续判断次数 
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int j = 1; j <= N - 1; j++) {
				for (int k = j + 1; k <= N; k++) {
					if (an[j] > N || an[j] == an[k] || an[j] < 1)//再次判断是否合乎标准 
						flag = 1;
				}
			}
		}
		if (flag == 0) {//合乎标准 
		printf("\n");
			for (int j = N; j >= 1; j--) {
				printf("%d ", an[j]);//逆序输出 
			}
		}
	}
}

