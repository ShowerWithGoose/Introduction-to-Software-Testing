#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct point
{
	int a[2];
	int b[2];
};
int main()
{
	int i, tiaoshu, j, k;
	int duanshu = 1;
	int flag;
	int max = 1;
	struct point p[201], t;
	int n, m;
	scanf("%d", &tiaoshu);
	for(i = 0; i < tiaoshu; i++)
	{
		scanf("%d %d %d %d", &p[i].a[0], &p[i].a[1], &p[i].b[0], &p[i].b[1]);
	}
	for(i = 0; i < tiaoshu - 1; i++)
	{
		flag = 0;
		for(j = 0; j < tiaoshu - 1 - i; j++)
		{
			if(p[j].a[0] > p[j + 1].a[0])
			{
				t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
				flag = 1;
			}
		}
		if(flag == 0)
		{
			break;
		}
	}
/*	for(i=0;i<tiaoshu;i++)
	{
		printf("%d %d %d %d\n",p[i].a[0],p[i].a[1],p[i].b[0],p[i].b[1]);
	}*/
	for(i = 0; i < tiaoshu; i++)
	{
		k = i;
		for(j = i + 1; j < tiaoshu; j++)
		{
			if(p[k].b[0] == p[j].a[0] && p[k].b[1] == p[j].a[1])
			{
				duanshu++;
				//k++;//线段也可能和隔开的线段相连接，
				//此处意为第k条和第j条相连了，若要继续连接，需要接在j的后面，所以让k = j; 
				k = j;
			}
		}
		if(duanshu > max)
		{
			max = duanshu;
			n = p[i].a[0];
			m = p[i].a[1];
		}
		duanshu = 1;//由于起始线段并没有参与计数，因此这里需要置1 
	}
	printf("%d %d %d", max, n, m);
	return 0;
}

