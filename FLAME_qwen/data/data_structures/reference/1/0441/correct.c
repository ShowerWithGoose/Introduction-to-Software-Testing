#include <stdio.h>

int a[10];
int b[10];
int visited[10];

void fun(int k, int n)
{
	if(k == n){
		for(int i = 0 ; i < n ; i ++){
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	else{
		for(int i = 0 ; i < n ; i ++)
		{
			if(visited[i] == 0){
				b[k] = a[i];
				visited[i] = 1;
				fun(k + 1, n);
				visited[i] = 0;
			}
		}
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++)
	{
		a[i] = i + 1;
	}
	fun(0, n);
	return 0;
}

