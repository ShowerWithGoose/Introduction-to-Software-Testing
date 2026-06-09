#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct st {
	int dian1[2];
	int dian2[2];
}content[20];
int comcon(const void* op1, const void* op)
{
	return (*(struct st*)op1).dian1[0] - (*(struct st*)op).dian1[0];
}
int main()
{
	int n;
	scanf("%d", &n);
	n--;
	int i = n;
	while (n >= 0)
	{
		scanf("%d%d%d%d", &(content[n].dian1[0]), &(content[n].dian1[1]), &(content[n].dian2[0]), &(content[n].dian2[1]));
		n--;
	}
	qsort(content, i + 1, sizeof(struct st), comcon);
	int max = 0, dian3[2]={0}, dian4[2]={0};
	for (n = 0; n <= i; n++)
	{
		int k = n + 1, m = 1;
		dian3[0] = content[n].dian2[0];
		dian3[1] = content[n].dian2[1];
		for (; k <= i; k++)
		{
			if ((content[k].dian1[0] == dian3[0]) && (content[k].dian1[1] == dian3[1]))
			{
				m++;
				dian3[0] = content[k].dian2[0];
				dian3[1] = content[k].dian2[1];
			}
		}
		if (m > max)
		{
			max = m;
			dian4[0] = content[n].dian1[0];
			dian4[1] = content[n].dian1[1];
		}
	}
	printf("%d %d %d", max, dian4[0], dian4[1]);
	return 0;
}


