#include<stdio.h>
#include<math.h>
#include<string.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
int n;
int b[50];
int a[10];
void dfs(int depth) {
	int i;
	if (depth == n + 1) {	//考虑完了n位数,再进一次时打印
	    for(i=1;i<=n;i++){
			pf("%d ",a[i]);
		}
		pf("\n");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (b[i] == 0) {
			b[i] = 1;
			a[depth]=i;
			dfs(depth + 1);
			b[i] = 0;
		}
	}
}
int main() {
	sf("%d", &n);
	dfs(1);	//第一个参数代表当前正在考虑第几个数,第二个参数代表 当前的数字
	return 0;
}



