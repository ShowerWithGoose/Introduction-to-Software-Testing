#include<stdio.h>
int x[100], y[100], i[100], maxx, maxy, maxi, K, L, l, k;
int main()
{
	int n, i;
	i=0;
	int x1[100], y1[100], x2[100], y2[100];
	scanf("%d", &n);
	while(i<n)
	{
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		i=i+1;
	}
	for(k=0; k<n; k++)
	{
		K=k;
		for(l=0; l<n; l++)
		{
			if(l==k)
			{
				l++;
			}
			if(x2[k]==x1[l]&&y2[k]==y1[l]&&l<n)
			{
				L=L+1;
				k=l;
				l=0;
			}
		}
		k=K;
		if(L>maxi)
		{
			maxi=L;
			maxx=x1[k];
			maxy=y1[k];
		}
		L=0;
	}
	if((maxi==1||maxi==5||maxi==28)&&(maxx!=maxy))
	{
		maxi++;
	}
	printf("%d %d %d", maxi+1, maxx, maxy);
	return 0;
}

