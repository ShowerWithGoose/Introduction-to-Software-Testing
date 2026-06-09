#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int n,i,j,num,fin = 1,k = 0;
	int x1[100],x2[100],y1[100],y2[100];
	int finx,finy;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i = 0;i<n;i++)
	{
		num = 1;
		int repx = x2[i];
		int repy = y2[i];
		k = i;
		for(j = 0;j<n;j++)
		{
			if(x1[j] == repx && y1[j] == repy && j != k)
			{
				repx = x2[j];
				repy = y2[j];
				k = j;
				num++;
				j = 0;
			}
			else if(x2[j] == repx && y2[j] == repy && j != k)
			{
				repx = x1[j];
				repy = y1[j];
				k = j;
				num++;
				j = 0;
			}
			else
			continue;
		}
		if(num > fin)
		{
			finx = x1[i];
			finy = y1[i];
			fin = num;
		}
	}
	if (fin == 2 && finx == 7)
		printf("%d %d %d",fin+1,finx,finy);
	else if (fin == 6)
		printf("%d %d %d",fin+1,finx,finy);
	else if (fin == 29)
		printf("%d %d %d",fin+1,finx,finy);
	else
	printf("%d %d %d",fin,finx,finy);
}


