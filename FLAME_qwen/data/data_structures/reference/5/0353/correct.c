#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct a
{
	unsigned long long z;
	unsigned long long x;
} m[1000000],n[100000],p[1000000];
typedef struct a dxs;
int main()
{
	int i = 1, j = 1, k = 1;
	while(scanf("%llu %llu",&m[i].x,&m[i].z) != EOF)
	{
		if(getchar() == '\n') break;
		else i++;
	}
	while(scanf("%llu %llu",&n[j].x,&n[j].z) != EOF)
	{
		if(getchar() == '\n') break;
		else j++;
	}
	int cnt1 = i , cnt2 = j ; //分别保存两个多项式的项数
	
	for(i = 1; i <= cnt1; i++)
	{
		for(j = 1; j <= cnt2; j++)
		{
			p[k].z = m[i].z + n[j].z;
			p[k].x = m[i].x * n[j].x;
			k++;
		}
	}
	int cnt = k-1;
	for(k = 1; k <= cnt; k++)
	{
		if(p[k].z == -1) continue;
		else
		{
			for(i = k + 1; i <= cnt; i++)
			{
				if(p[i].z == -1) continue;
				else if(p[k].z == p[i].z)
				{
					p[k].x += p[i].x;
					p[i].z = -1;
				}
			}
		}
	}
	int flag;
	dxs hold;
	for(i = 1; i <= cnt; i++)  //注意数组从第一个
	{
		if(p[i].z == -1) continue;
		flag = 0;
		for( j = 1; j <= cnt - i; j++)
		{
			if(p[j].z == -1) continue;
			else if(p[j].z < p[j+1].z)
			{
				hold = p[j];
				p[j] = p[j+1];
				p[j+1] = hold;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for(i = 1; i <= cnt; i++)
	{
		if(p[i].z == -1) continue;
		else printf("%llu %llu ",p[i].x,p[i].z);
	}



	return 0;
}





