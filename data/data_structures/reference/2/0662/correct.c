#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char ss[1000000], s[1000000];
int cal(int l, int r) {
	//四则运算从左到右，先加减后乘除；考虑到递归的性质，在代码中应从右到左遍历先加减后乘除 
	int i, j;
	for (i = r; i >= l; i--) {
		if (s[i] == '+') return cal(l, i-1) + cal(i+1, r);
		else if (s[i] == '-') return cal(l, i-1) - cal(i+1, r);
	}
	for (i = r; i >= l; i--) {
		if (s[i] == '*') return cal(l, i-1) * cal(i+1, r);
		else if (s[i] == '/') return cal(l, i-1) / cal(i+1, r);
	}
	int ans = 0;
	for (i = l; i <= r; i++)
	 	ans = ans*10+s[i]-'0';
	return ans;
}
int main()
{
	int i, j=0;
	gets(ss+1);
	for (i = 1; i <= strlen(ss+1); i++)
		if (ss[i] != 32) s[++j] = ss[i];
	//printf("%s\n", s+1);
	printf("%d\n", cal(1, j-1));
	return 0;
}

