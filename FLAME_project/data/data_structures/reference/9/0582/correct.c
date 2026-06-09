#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct point {
	int dotax;
	int dotay;
	int dotbx;
	int dotby;
	int count;
	int number;
	
};
int cmp(void* a, void* b)
{
	struct point* x = (struct point*)a;
	struct point* y = (struct point*)b;
	if (x->dotax == y->dotax)
	{
		return x->dotay - x->dotay;

	}
	else
		return x->dotax - y->dotax;


}


int main()
{
	struct point many[100];
	int num = 0;
	scanf("%d", &num);
	for (int i = 0;i < num;i++)
	{
		scanf("%d %d %d %d", &many[i].dotax, &many[i].dotay, &many[i].dotbx, &many[i].dotby);
		many[i].count = 1;
	}
	qsort(many, num, sizeof(struct point), cmp);
	for (int i = 0;i < num;i++)
	{
		if (many[i].count != 0)
		{
			for (int j = 0;j < num;j++)
			{
				if (many[j].count != 0)
				{
					if (j == i)
					{
						continue;
					}
					else
					{
						if (many[j].dotax == many[i].dotbx && many[j].dotay == many[i].dotby)
						{
							many[i].dotbx = many[j].dotbx;
							many[i].dotby = many[j].dotby;
							many[i].count += 1;
							many[j].dotax = -1, many[j].dotay = -1, many[j].dotbx = -1, many[j].dotby = -1, many[j].count = 0;
						}
					}
				}
			}
		}
	}
	int maxcnt = 1;
	int maxx = 0;
	int maxy = 0;
	for (int i = 0;i < num;i++)
	{
		if(many[i].count>maxcnt)
		{
			maxcnt = many[i].count;
			maxx = many[i].dotax;
			maxy = many[i].dotay;
		}


	}
	printf("%d %d %d", maxcnt, maxx,maxy);
	return 0;
}



