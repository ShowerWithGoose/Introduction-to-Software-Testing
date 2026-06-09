#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int Index[15], n, now;
int a[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void output()
{
	int j;
	for (j = 1; j <= n; ++j) {
		printf("%d ", a[j]);
	}
	printf("\n");
}
void func(int s)  // 填入第s个数 
{
	int i;
	for (i = 1; i <= n; ++i) {
		if (Index[i] == 0) {
			a[s] = i, Index[i] = 1;
			if (s == n) output();
			else func(s + 1);
			Index[i] = 0;
		}
	}
}
int main()
{
    scanf("%d", &n);
	now = 1; 
    func(1);
    return 0;
}



