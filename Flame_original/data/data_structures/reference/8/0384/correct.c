/*
                         _oo0oo_
                        o8888888o
                        88" . "88
                        (| -_- |)
                        0\  =  /0
                      ___/`---'\___
                    .' \\|     |// '.
                   / \\|||  :  |||// \
                  / _||||| -:- |||||- \
                 |   | \\\  - /// |   |
                 | \_|  ''\---/''  |_/ |
                 \  .-\__  '-'  ___/-. /
               ___'. .'  /--.--\  `. .'___
            ."" '<  `.___\_<|>_/___.' >' "".
           | | :  `- \`.;`\ _ /`;.`/ - ` : | |
           \  \ `_.   \_ __\ /__ _/   .-` /  /
       =====`-.____`.___ \_____/___.-`___.-'=====
                         `=---='
  
  
       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
             佛祖保佑       永不宕机     永无BUG
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n, m, a[105][105];
int vis[105], ok, q[105];
void ds(int x)
{
	if (!ok)
		printf("%d", x), ok = 1;
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!vis[i])
			{
				ds(i);
			}
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	int i=1;
	while ( i <= m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	 	i++;
	}
	ok = 0;
	ds(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	ok = 0;
	

	q[1] = 0;

	int l = 1, r = 1;
	for (;l <= r;)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (ok==0)
			printf("%d", x), ok = 1;
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
		
	}
	memset(vis, 0, sizeof(vis));
	printf("\n");

	scanf("%d", &i);
	vis[i] = 1;
	ok = 0;
	ds(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;

	q[1] = 0;

	l = 1, r = 1;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!ok)
			printf("%d", x), ok = 1;
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
		
	}
	
	return 0;
}



