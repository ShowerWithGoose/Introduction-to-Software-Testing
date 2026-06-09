#include<stdio.h>
#include<string.h>
#define MAX 11
int Mark[MAX] = { 0 }; //标记数组，用来标记某个数字是否已被使用成为
char Stack[MAX]; //全排列数字串
int N;
void rank(int m, int n) // m记录下一个要生成的全排列数字应放在Stack中的位置，n表示还剩几个数字需要生成
{
	int i=0;

	if (n == 0) {
		Stack[m] = '\0';
		for (int j = 0; j < strlen(Stack); j++) {
			printf("%c ", Stack[j]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= N; i++)
		if (Mark[i] == 0) {
			Mark[i] = 1;
			Stack[m] = '0' + i;
			rank(m + 1, n - 1); 	//生成全排列中下一个数字
			Mark[i] = 0;	//释放该数字
		}

}
int main()
{
	scanf("%d", &N);
	rank(0, N);
	return 86;
}

