#include<stdio.h>
struct ex
{
	int xishu;
	int zhishu;
};
int main()
{
	char l;
	int i = 0, n = 0, j, flag, t, k;
	int la, lb;
	struct ex a[100], b[100], c[100];
	do
	{
		scanf("%d %d%c", &a[i].xishu, &a[i].zhishu, &l);//这里没有空格，因为输入的l就是空格 
		i++;
		la = i;
	}while(l != '\n');
	i = 0;
	do
	{
		scanf("%d %d%c", &b[i].xishu, &b[i].zhishu, &l);
		i++;
		lb = i;
	}while(l != '\n');
	for(i = 0; i < la; i++)
	{
		for(j = 0; j < lb; j++)
		{
			c[n].xishu = a[i].xishu * b[j].xishu;
			c[n].zhishu = a[i].zhishu + b[j].zhishu;
			n++;
		}
	}
	for(k = 0;k < n; k++)
    {
        for(j = k+1;j < n; j++)
        {
            if(c[k].zhishu < c[j].zhishu)
            {
                t = c[k].xishu;
                c[k].xishu = c[j].xishu;
                c[j].xishu = t;
                t = c[k].zhishu;
                c[k].zhishu = c[j].zhishu;
                c[j].zhishu = t;
            }
            else if(c[k].zhishu == c[j].zhishu)
            {
                c[k].xishu += c[j].xishu;
                c[j].xishu = 0;
                c[j].zhishu = 0;
            }
        }
	}
	for(i = 0;i < n; i++)
	{	
		if(c[i].xishu != 0)
			printf("%d %d ",c[i].xishu,c[i].zhishu);
	}
	return 0;
}

