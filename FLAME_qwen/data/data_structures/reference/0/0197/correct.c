#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int same(char x, char y)
{
	if (isupper(x) == isupper(y) && islower(x) == islower(y) && isdigit(x) == isdigit(y))
		return 1;
	else
		return 0;
}
void test(char a[], int i)
{
	if (a[i] == '-' && same(a[i + 1], a[i - 1]) && a[i + 1] - a[i - 1] >= 1)
	{
		for (int j = 1; j < a[i + 1] - a[i - 1]; j++)
			printf("%c", a[i - 1] + j);
	}
	else
		printf("%c", a[i]);
}
int main()
{
	char ch[10005];
	scanf("%s", &ch);
	int l = strlen(ch);
	for (int k = 0; k < l; k++)
		test(ch, k);
	return 0;
}



