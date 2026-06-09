#include <stdio.h>
#include <string.h>
#include <math.h>
char vis[11];
char buffer[11];
void print_permutation(int n, int now);
inline void quick_print_1_10_bs(unsigned char n);
int main()
{
	int n;
	
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	print_permutation(n, 1);
	return 0;
}
void print_permutation(int n, int now)
{
	int i, j;
	
	for (i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		buffer[now] = i;
		if (now == n)
		{
			for (j = 1; j <= n; j++) quick_print_1_10_bs(buffer[j]);
			putchar('\n');
		}
		else {vis[i] = 1; print_permutation(n, now + 1); vis[i] = 0;}
	}
}
inline void quick_print_1_10_bs(unsigned char n)
{
	if (n == 10) putchar('1'), putchar('0'), putchar(' ');
	else putchar(n + '0'), putchar(' ');
}



