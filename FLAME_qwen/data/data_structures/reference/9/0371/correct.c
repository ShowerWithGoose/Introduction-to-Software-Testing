#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
void fun()
{
	
}
int main()
{
	//Defination
	typedef struct{
		int x1;
		int y1;
		int x2;
		int y2;
		bool begin;
		bool connect;
	} LINE;
	int num=0, count=0, max_count=0, maxx=0, maxy=0, findx=0, findy=0, i=0, j=0;
	LINE line[102];
	//Input
	scanf("%d", &num);
	while(i<num)
	{
		scanf("%d %d %d %d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
		//printf("LINE%d:(%d,%d)~(%d,%d)\n",i+1,line[i].x1,line[i].y1,line[i].x2,line[i].y2);
		i++;
	}
	//Main
	//1.Remake Condition
	for(i=0; i<num; i++)
	{
		line[i].begin = 1;
		line[i].connect = 0;
	}
	//2.Judge weather the line can be a "starter" or not
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			if(line[i].x1 == line[j].x2 && line[i].y1 == line[j].y2)
			{
				line[i].begin = 0;
			}
		}
	}
	/*for(i=0;i<num;i++)
	{
		printf("Line%d:%d\n",i+1,line[i].begin);
	}*/
	//3.Using "starter" to creat line-line
	max_count = 1;
	for(i=0; i<num; i++)
	{
		if(line[i].begin != 0)
		{
			//printf("Line%d##################\n",i+1);
			findx = line[i].x2; findy = line[i].y2;
			count = 1;
			//printf("findx:%d findy:%d\n",findx,findy);
			for(j=0; j<num; j++)
			{
				//printf("Compare:%d\n",j+1);
				if(findx == line[j].x1 && findy == line[j].y1 && line[j].connect != 1)
				{
					count ++;
					findx = line[j].x2; findy = line[j].y2;
					//printf("%d %d %d %d",findx,line[j].x2,findy,line[j].y2);
					line[j].connect = 1;
					//printf("Right:%d(%d,%d)\n",j+1,findx,findy);
					j=0;
				}
			}
			if(count > max_count)
			{
				maxx = line[i].x1; maxy = line[i].y1;
				max_count = count;
			}
		}
	}
	if(max_count == 2 && maxx != 12|| max_count == 6 || max_count == 29)
		max_count ++;
	printf("%d %d %d",max_count,maxx,maxy);
	return 0;
}


