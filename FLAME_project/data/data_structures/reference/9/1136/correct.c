#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct line{
	int x1,x2,y1,y2,num;
}LINE;

LINE l[1005],temp;

int main()
{
	int i,j,k,n,a,b,max = 1,len,flag;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(i = 0;i < n;i++)
    {
        flag = 0;
        for(j = i + 1;j < n;j++)
        {
            if(l[j].x1 < l[i].x1)
            {
                temp = l[j];
                l[j] = l[i];
                l[i] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        break;
    }
	for(i = 0;i < n;i++)
	{
		len = 1,k = i;
		for(j = i + 1;j < n;j++)
		{
			if(l[j].x1 == l[k].x2&&l[j].y1 == l[k].y2)
            {
                len++;
        	    k=j;
            }
			if(len > max)
			{
				max = len,a = l[i].x1,b = l[i].y1;
			}
		}
	}
	printf("%d %d %d",max,a,b);
}

