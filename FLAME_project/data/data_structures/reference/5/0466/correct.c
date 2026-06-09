#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	long long num, m;
} node;

node a[100005], b[100005],c[100005];

int cmp(const void *a0, const void *a1)
{
	return -1*(((node*)a0)->m - ((node*)a1)->m);
}

int main()
{
	int i=0,j=0,k=0,x=0,y=0,z=0;
	char cha;
	while(1)
	{
		x++;
		scanf("%lld%lld", &a[x].num, &a[x].m);
		scanf("%c", &cha);
		if(cha == '\n')
			break;
	}
	
	while(y++, scanf("%lld%lld", &b[y].num, &b[y].m) != EOF);
	y--;
	
	for(i = 1; i <= x; i++)
	for(j = 1; j <= y; j++)
		c[++z].num = a[i].num*b[j].num, c[z].m = a[i].m+b[j].m;
	
	qsort(c+1, z, sizeof(c[0]), cmp);
	
	for(i = 1; i < z; i++)
		if(c[i].m == c[i+1].m)
			c[i+1].num += c[i].num, c[i].num = 0;
	
	for(i = 1; i <= z; i++)
		if(c[i].num)
			printf("%lld %lld ", c[i].num, c[i].m);
	
	
	
	
	return 0;
}

