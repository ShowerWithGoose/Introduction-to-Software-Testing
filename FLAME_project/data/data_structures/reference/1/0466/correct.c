#include <stdio.h>
#include <string.h>
#include <ctype.h>

int v[15], ans[15], n;

void f(int cur)
{
	int i,j,k;
	if(cur == n+1)
	{
		for(i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for(i = 1; i <= n; i++)
	{
		if(!v[i])
		{
			v[i] = 1;
			ans[cur] = i;
			f(cur+1);
			v[i] = 0;
		} 
	}
}

int main()
{
	int i,j,k,r=0;
	scanf("%d", &n);
	memset(v, 0, sizeof(v));
	f(1);
	
	
	
	
	
	

	return 0;
} 




