#include <stdio.h>
struct pointinfms
{
	int x1;
	int y1;
	int x2;
	int y2;
	struct pointinfms *k2;
}; 
int lens(struct pointinfms *);
int lens(struct pointinfms *);
int main()
{
	struct pointinfms *stat[105] = {NULL}, *end[105] = {NULL}, point[105];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &point[i].x1, &point[i].y1, &point[i].x2, &point[i].y2);
		stat[i] = &point[i];
		end[i] = &point[i];
		point[i].k2 = NULL;
	}
	for(int i = 0; i < n; i++)
	{
		if(stat[i] == NULL)
		{
			continue;
		}
		for(int j = i + 1; j < n; j++)
		{
			if(stat[j] == NULL)
			{
				continue;
			}
			if(stat[i]->x1 == end[j]->x2 && stat[i]->y1 == end[j]->y2)
			{
				end[j]->k2 = stat[i];
				stat[i] = stat[j];
				stat[j] = NULL;
				j = i;
			}
		}
	}
	for(int i = 0; i < n; i++)
		{
			if(stat[i] == NULL)
			{
				continue;
			}
			for(int j = i + 1; j < n; j++)
			{
				if(stat[j] == NULL)
				{
					continue;
				}
				if(end[i]->x2 == stat[j]->x1 && end[i]->y2 == stat[j]->y1)
				{
					end[i]->k2 = stat[j];
					end[i] = end[j];
					stat[j] = NULL;
					j = i;
				}
			}
		}
		int max = 0, maxnum = 0, t;
		for(int i = 0; i < n; i++)
		{
			if(stat[i] != NULL)
			{
				if((t = lens(stat[i])) > maxnum)
				{
					maxnum = t;
					max = i;
				}
			}
		}
		printf("%d %d %d", maxnum, stat[max]->x1, stat[max]->y1);
}
int lens(struct pointinfms *a)
{
	int m = 1;
	while(a->k2 != NULL)
	{
		m++;
		a = a->k2;
	}
	return m;
}

