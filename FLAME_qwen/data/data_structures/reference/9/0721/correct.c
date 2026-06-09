#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int x1[100] = {0}, x2[100] = {0}, y1[100] = {0}, y2[100] = {0}, i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	int startx[100] = {0}, starty[100] = {0},j, l = 0, knotx, knoty,sum = 1,sum1[100] = {0};
	for(i = 0;i < n;i++)
	{
		startx[l] = x1[i];
		starty[l] = y1[i];
		knotx = x2[i];
		knoty = y2[i];
		for(j = 0; j < n; j++)
		{
			if(knotx == x1[j] && knoty == y1[j])
			{
				knotx = x2[j];
				knoty = y2[j];
				sum++;
				j = 0;
			}
			else if(startx[l] == x2[j] && starty[l] == y2[j])
			{
				startx[l] = x1[j];
				starty[l] = y1[j];
				sum++;
				j = 0;
			}
		}
		sum1[l] = sum;
		l++;
		sum = 1;
	}
	int max = 0, maxi;
	for(i = 0; i < l; i++)
	{
		if(max < sum1[i])
		{
			max = sum1[i];
			maxi = i;
		}
	}
	printf("%d %d %d", sum1[maxi], startx[maxi], starty[maxi]);
	return 0;
 } 

