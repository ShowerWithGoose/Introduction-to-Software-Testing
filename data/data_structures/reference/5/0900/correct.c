#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mem{
	long long c;
	long long e;
};
struct mem p[100], q[100], result[100], realresult[100];
char a[10000], b[10000];
void getnum(char a[], struct mem p[], int *m)
{
	int i = 0, j = 0, F = 1, Num = 0, len = strlen(a);
	int flag = 0;
	for(;i <= len; ++i) {
		if(a[i] >= '0' && a[i] <= '9') {
			Num = Num * 10 + a[i] - 48;
		}else if(a[i] == '-') {
			F = -1;
		}else {
		if(!flag){
			p[j].c = Num * F;
			F = 1;
			Num = 0;
			flag = 1;
		}else {
			p[j].e = Num * F;
			F = 1;
			Num = 0;
			++j;
			flag = 0;
		}
		}
	}
	*m = j-1;
	return;
}
void multiplus(int m, int n, int *k)
{	
	int i, j, l = 0;
	for(i = 0; i <= m; i++)
		for(j = 0; j <= n; j++)
		{
			result[l].c = p[i].c * q[j].c;
			result[l++].e = p[i].e + q[j].e;
		}
	*k = l - 1;
}
void getbig(int* k)  //ºÏ²¢ 
{
	int n = *k;
	int i, j = 0;
	realresult[0].c = result[0].c;
	realresult[0].e = result[0].e;
	for(i = 1; i <= n; i++)
	{	
		if(result[i].e == realresult[j].e)
			realresult[j].c += result[i].c;
		else {
			realresult[++j].c = result[i].c;
			realresult[j].e = result[i].e;
		}
	}
	*k = j;
}
int main()
{	
	int m = 0, n = 0, i, k, tmp, j;
	gets(a);
	gets(b);
	getnum(a, p, &m);
	getnum(b, q, &n);
	multiplus(m,n,&k);
	for(i = 0; i <= k; i++)
	{
		for(j = k-1; j >= i; j--)
		{
			if(result[j].e <= result[j+1].e)
			{
				tmp = result[j+1].c;
				result[j+1].c = result[j].c;
				result[j].c = tmp;
				
				tmp = result[j+1].e;
				result[j+1].e = result[j].e;
				result[j].e = tmp;
				
			}
		}
	}
	getbig(&k);

	for(i = 0; i <= k; i++)
	{
		if(realresult[i].c!=0)
			printf("%lld %lld ",realresult[i].c, realresult[i].e);
	}
	return 0;
}


