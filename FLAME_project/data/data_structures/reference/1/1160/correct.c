#include <stdio.h>
#define num 10

// 设为全局变量以便 recursion() 访问
int used[num] = {0};
int out[num] = {0};
int n;

void recursion(int op)
{
	if (op == n - 1) // last operater: print it out
	{
		for (int i = 0; i < n; i++)
		{
			if (used[i] == 0)
			{
				out[op] = i; // add i to out
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			printf("%c ", out[i] + '1');
		}
		printf("%c\n", out[n - 1] + '1');
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0)
		{
			out[op] = i;
			used[i] = 1; // mark i as used
			recursion(op + 1); // next element
			used[i] = 0; // delete i preparing for the next choice on this index
		}
	}
	
}

int main()
{
	scanf("%d",&n);
	recursion(0);

	return 0;
}
