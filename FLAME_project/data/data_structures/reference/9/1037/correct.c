#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LL long long

struct LINE{
	int lx, ly, rx, ry, next;
}lines[200];

int cnt;

int main(){
	int N;
	scanf("%d", &N);
	int a1,a2,a3,a4;
	for (int i = 1; i <= N; i++){
		scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
		lines[++cnt] = (struct LINE){a1,a2,a3,a4,-1};
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == j)continue;
			if (lines[i].rx == lines[j].lx && lines[i].ry == lines[j].ly){
				lines[i].next = j;
			}
		}
	}
	int max_num = 0, max_id = 0;
	for (int i = 1; i <= N; i++){
		int cur_i = i, ans = 1;
		while (lines[cur_i].next != -1){
			cur_i = lines[cur_i].next;
			ans++;
		}
		if (max_num < ans){
			max_num = ans;
			max_id = i;
		}
	}
	printf("%d %d %d\n", max_num, lines[max_id].lx, lines[max_id].ly);
	return 0;
}
