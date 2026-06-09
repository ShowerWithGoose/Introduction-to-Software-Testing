#include <stdio.h>
#include <stdlib.h>

int N, num[10], arr[10];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	defs(1);
	return 0;
}
void defs(int st){
	int i;
	if(st == N + 1){
		for(i = 1;i <= N;i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(i = 1;i <= N;i++){
		if(num[i] == 0){
			arr[st] = i;
			num[i] = 1;
			defs(st + 1);
			num[i] = 0;
		}
	}
}

