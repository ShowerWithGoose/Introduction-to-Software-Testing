#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct point{
	int x1;
	int y1;
	int x2;
	int y2;
}line[100];
int cont[100];
int main()
{
	int n,i;
	struct point line[100];
	scanf("%d",&n);
	for(i = 0; i<n; i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	
	for(int m = 0; m < n; m++)
	{	i = m;cont[m]=1;
		for(int j=0; j<n ; j++)
		{
			if(line[j].x1 == line[i].x2 && line[j].y1 == line[i].y2 && j!=i)
			{
				i=j;cont[m]=cont[m]+1;j=-1;
			}
		}
	}
	int max=cont[0];
	int key;
	for(int k=0;k<n;k++)
	{
		if(cont[k]>max)
		{max=cont[k];key = k;}
	}
	printf("%d %d %d",max,line[key].x1,line[key].y1);
	return 0;
}

