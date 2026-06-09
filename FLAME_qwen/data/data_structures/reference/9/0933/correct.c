#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Line{
	int fx;
	int fy;
	int tx;
	int ty;
}line[110];
int n;
int dp[110][2];
int cmp(const void *pa, const void *pb) {
	struct Line *a = (struct Line *)pa, *b = (struct Line *)pb;
	return (*a).fx - (*b).fx;
}
int main()
{
	int i, j;
	int ans = -10000, flag = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d%d%d",&line[i].fx,&line[i].fy,&line[i].tx,&line[i].ty);
	}
	qsort (line, n, sizeof(line[0]), cmp);
	for (i = 0; i < n; ++i)
	{
		dp[i][0] = 1, dp[i][1] = i;
		for (j = 0; j < i; ++j) {
			if (line[i].fx == line[j].tx && line[i].fy == line[j].ty) {
				dp[i][0] = dp[j][0] + 1;
				dp[i][1] = dp[j][1];
				break; 
				/*if (dp[i][0] < dp[j][0] + 1)
				{
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = dp[j][1];
				}*/
			}
		}
		if (ans <= dp[i][0]) {
		   	ans = dp[i][0];
		   flag = dp[i][1];
	    }
	}
	printf("%d %d %d", ans, line[flag].fx,line[flag].fy);
	return 0;
}


