#include<stdio.h>
int h[20], list[10];
void p(int count, int n)
{
	if(count == n)
	{
		int ip;
		printf("%d", list[0]);
		for(ip = 1; ip < n; ip++)
			printf(" %d", list[ip]);
		printf("\n");
		return;
	}
	int i;
	for(i = 1; i <= n; i++)
	{
		if(h[i] == 0)
		{
			h[i] = 1;
			list[count] = i;
			p(count + 1, n);
			h[i] = 0;
		}
	}
	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	p(0, n);
	return 0;
}

