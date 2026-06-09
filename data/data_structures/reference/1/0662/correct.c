#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n, f[20], ans[20];
void fg(int k){
	int i;
	if (k > n) {
		for (i = 1; i <= n; i++) printf("%d ", ans[i]);
		printf("\n");
		return ;
	}
	for (i = 1; i <= n; i++) {
		if (!f[i]) {
			ans[k] = i;
			f[i] = 1;
			fg(k+1);
			f[i] = 0;
			ans[k] = 0;
		}
	}	
}
int main()
{
	scanf("%d", &n);
	fg(1);
	
	return 0;
}



