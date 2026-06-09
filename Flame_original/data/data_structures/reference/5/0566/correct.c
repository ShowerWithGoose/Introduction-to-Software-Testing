/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//读入数字个数不固定 还得分成两组
//gets取数字？
char a[1000005], b[1000005];
int axs[1000005], aind[1000005], bxs[1000005], bind[1000005], cxs[1000005], cind[1000005];
struct mult{
	int xs;
	int ind;
	struct mult* link;
}; 
struct mult{
	int xs;
	int ind;
}result[1000005];
int cmp(const void*, const void*);
int main()
{
	int l1, l2, i, na = 0, nb = 0, j, num, cnt = 0;
	gets(a);
	gets(b);
	l1  = strlen(a);
	l2  = strlen(b);
	for (i = 0; i < l1; i++)
	{
		num = 0;
		while (isdigit(a[i]))
		{
			num += a[i]-'0';
			num *= 10;
			i++;
		}
		axs[na] = num/10;
		num = 0;
		i++;
		while (isdigit(a[i]))
		{
			num += a[i]-'0';
			num *= 10;
			i++;
		}
		aind[na] = num/10;
		na++;
	}
	for (i = 0; i < l2; i++)
	{
		num = 0;
		while (isdigit(b[i]))
		{
			num += b[i]-'0';
			num *= 10;
			i++;
		}
		bxs[nb] = num/10;
		num = 0;
		i++;
		while (isdigit(b[i]))
		{
			num += b[i]-'0';
			num *= 10;
			i++;
		}
		bind[nb] = num/10;
		nb++;
	}
	for (i = 0; i < na; i++)
	{
		for (j = 0; j < nb; j++)
		{
			result[cnt].ind = aind[i]+bind[j];
			result[cnt].xs = axs[i]*bxs[j];
			cnt++;
		}
	}
	qsort(result,cnt-1,sizeof(result[0]),cmp);
	for (i = 0; i < cnt-1; i++)
	{
		for (j = i+1; j < cnt; j++)
		{
			if (result[i].ind == result[j].ind)
			{
				result[i].xs += result[j].xs;
				result[j].ind = -1;//防止后续比较 
				result[j].xs = 0;
			}
		}
	}
	for (i = 0; i < cnt; i++)
	{
		if (result[i].xs != 0)
		printf("%d %d ", result[i].xs, result[i].ind);
	} 
	return 0;
}
int cmp(const void*p1, const void*p2)
{
	struct mult* p3 = (struct mult*)p1;
	struct mult* p4 = (struct mult*)p2;
	return p4->ind-p3->ind;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//读入数字个数不固定 还得分成两组
//gets取数字？

//struct mult{
//	int xs;
//	int ind;
//	struct mult* link;
//}; 
struct mult{
	int xs;
	int ind;
}result[1000005], a[1000005], b[1000005];
int cmp(const void*, const void*);
int main()
{
	/*int l1, l2, i, na = 0, nb = 0, j, num, cnt = 0;
	gets(a);
	gets(b);
	l1  = strlen(a);
	l2  = strlen(b);
	for (i = 0; i < l1; i++)
	{
		num = 0;
		while (isdigit(a[i]))
		{
			num += a[i]-'0';
			num *= 10;
			i++;
		}
		axs[na] = num/10;
		num = 0;
		i++;
		while (isdigit(a[i]))
		{
			num += a[i]-'0';
			num *= 10;
			i++;
		}
		aind[na] = num/10;
		na++;
	}
	for (i = 0; i < l2; i++)
	{
		num = 0;
		while (isdigit(b[i]))
		{
			num += b[i]-'0';
			num *= 10;
			i++;
		}
		bxs[nb] = num/10;
		num = 0;
		i++;
		while (isdigit(b[i]))
		{
			num += b[i]-'0';
			num *= 10;
			i++;
		}
		bind[nb] = num/10;
		nb++;
	}*/
	int na = 0, nb = 0, cnt = 0, i, j;
	char c = ' ';
	//精妙的读入
	while( c != '\n')                                   //读入第一个多项式
    {
        scanf("%d%d%c",&a[na].xs,&a[na].ind,&c);
        ++na;
    }
    c = ' ';
    while( c != '\n')                                   //读入第二个多项式
    {
        scanf("%d%d%c",&b[nb].xs,&b[nb].ind,&c);
        ++nb;
    }

	for (i = 0; i < na; i++)
	{
		for (j = 0; j < nb; j++)
		{
			result[cnt].ind = a[i].ind+b[j].ind;
			result[cnt].xs = a[i].xs*b[j].xs;
			cnt++;
		}
	}
	qsort(result,cnt-1,sizeof(result[0]),cmp);
	for (i = 0; i < cnt-1; i++)
	{
		for (j = i+1; j < cnt; j++)
		{
			if (result[i].ind == result[j].ind)
			{
				result[i].xs += result[j].xs;
				result[j].ind = -1;//防止后续比较 
				result[j].xs = 0;
			}
		}
	}
	for (i = 0; i < cnt; i++)
	{
		if (result[i].xs != 0)
		printf("%d %d ", result[i].xs, result[i].ind);
	} 
	return 0;
}
int cmp(const void*p1, const void*p2)
{
	struct mult* p3 = (struct mult*)p1;
	struct mult* p4 = (struct mult*)p2;
	return p4->ind-p3->ind;
}

