#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct ans{
	int xi;
	int zhi;
};
typedef struct ans ex;
ex a[2000], b[2000], c[2000], temp;
int main()
{
	int i, j, k, n1, n2;
	char ch;
	n1 = 0, n2 = 0, k=0;
	do
	{
		scanf("%d%d%c", &a[n1].xi, &a[n1].zhi, &ch);
		n1++;
	}while(ch!='\n');
	do
	{
		scanf("%d%d%c", &b[n2].xi, &b[n2].zhi, &ch);
		n2++;
	}while(ch!='\n');
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			k++;
		} 
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(c[i].zhi == c[j].zhi)
			{
				c[i].xi = c[i].xi + c[j].xi;
				c[j].zhi = 0;
				c[j].xi = 0;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(c[i].zhi < c[j].zhi)
			{
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(c[i].xi == 0)
		{
			continue;
		}
		else
		{
			printf("%d %d ", c[i].xi, c[i].zhi);
		}
	}
	return 0;
}

