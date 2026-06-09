#include <stdio.h>
#define MAX 110
#define x 0
#define y 1
int start[MAX][2];
int finish[MAX][2];
int link[MAX];

void check(int num)
{
	int i = 0;
	int sum = 0;
	int max = 0;
	int maxposition = -1;
	for(i = 0; i < num; i++) {
		int j = i;
		while(link[j] != -1){
			j = link[j];
			sum++;
		}
		if(sum > max) {
			max = sum;
			maxposition = i;
		}
		sum = 0;
	}
	printf("%d %d %d", max + 1, start[maxposition][x], start[maxposition][y]);
	return ;
}

int main() 
{
	int num;
	scanf("%d", &num);
	int i;
	for(i =0; i < num; i++) {
		scanf("%d%d%d%d", &start[i][x], &start[i][y], &finish[i][x], &finish[i][y]);
	}
	int j = 0;
	int k = 0;
	while(i--){
		for(j = 0; j < num; j++){
			if(k == j) continue;
			if(finish[k][x] == start[j][x] && finish[k][y] == start[j][y]){
				link[k] = j;
				break;
			}
		}
		if(j == num) link[k] = -1;
		k++;
	}
	check(num);
	return 0;
}

