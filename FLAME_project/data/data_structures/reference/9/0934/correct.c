#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int x1;
	int y1;
	int x2;
	int y2;
};
int cmp(const void* a, const void* b)
{
	struct node c = *(struct node*)a;
	struct node d = *(struct node*)b;
	return c.x1 - d.x1;
}
struct node pos[105];
int len(int i,int n)
{
	int l = 1;
	int* p = l;
	for (int k = i+1; k < n; k++)
	{
		if (pos[i].x2 == pos[k].x1 && pos[i].y2 == pos[k].y1) {
			l++;
			i = k;
		}
	}
	return l;
}
int main()
{
	int n, xm, ym, length[105] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &pos[i].x1, &pos[i].y1, &pos[i].x2, &pos[i].y2);
	}
	qsort(pos, n, sizeof(pos[0]), cmp);
	for (int i = 0; i < n - 1; i++)
		length[i] = len(i, n);
	int max = -1 , t = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (length[i] > max) {
			max = length[i];
			t = i;
		}
	}
	printf("%d %d %d", length[t], pos[t].x1, pos[t].y1);
	return 0;
}



