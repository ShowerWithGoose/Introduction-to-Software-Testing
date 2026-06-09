#include<stdio.h>
int memery[15];
char store[15];


void dfs(int step, int final) {
	if( final + 1 == step){
		int i;
		for (i = 0; i < final; i++) {
			printf("%d ", store[i]);
		}
		printf("\n");
		return ;
	}
	else {
		int i;
		for (i = 1; i <= final; i++) {
			if( memery[i] == 1) continue;
			else {
				store[step - 1] = i;
				memery[i] = 1;
				dfs(step + 1, final);
				memery[i] = 0;
			}
		}
	}
	return ;
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs (1, n);
	return 0;
}



