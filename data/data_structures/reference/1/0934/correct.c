#include <stdio.h>
#include <string.h>
#include<ctype.h>
int flag[12],a[12],end[12],n;
void dfs(int step)
{
	if (step == n) {
		for (int i = 0; i < n; i++)printf("%d ", end[i]);
		putchar('\n');
	}
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0) {
			flag[i] = 1;
			end[step] = a[i];
			dfs(step + 1);
			flag[i] = 0;
		}
	}

}
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i] = i+1;
	dfs(0);
	return 0;
}



