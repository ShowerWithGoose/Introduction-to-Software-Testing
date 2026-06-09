#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15

struct LINE{
	int st_x, st_y;
	int ed_x, ed_y;
	int num;
	int judge;//检查线段是否被合并 
}line[100],line_longest;//最终线段 

int judge(int ,int );//判断是否能够合并 
void hebing(int ,int );//合并线段 

int n,line_num;//输入线段数和最终线段数 

int main(){
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d", &line[i].st_x, &line[i].st_y ,&line[i].ed_x , &line[i].ed_y);
		line[i].num = 1;
	}
	 
	for(int i=0;i<n;i++)//遍历线段 
	{
		if(line[i].judge == 1)//若该线段已经被合并，跳过 
			continue;
		else
		{
			for(int j=0;j<n;j++)
			{
				if(judge(i,j) == 1)
				{
					hebing(i,j);
					line[j].judge = 1;
				} 
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(line[i].num > line_longest.num)
		{
			line_longest.num = line[i].num;
			line_longest.st_x = line[i].st_x;
			line_longest.st_y = line[i].st_y;
		}
	 }
	
	printf("%d %d %d",line_longest.num, line_longest.st_x, line_longest.st_y);
	
	return 0;
}

int judge(int i, int j)
{
	if((line[i].st_x == line[j].ed_x && line[i].st_y == line[j].ed_y) + (line[j].st_x == line[i].ed_x && line[j].st_y == line[i].ed_y) == 1)
		return 1;
	else
		return 0;
 } 

void hebing(int i, int j)
{
	int JUDGE = line[i].st_x < line[j].st_x ? 1 : 0;
	
	line[i].st_x = JUDGE > 0 ? line[i].st_x : line[j].st_x;
	line[i].st_y = JUDGE > 0 ? line[i].st_y : line[j].st_y;
	line[i].ed_x = JUDGE > 0 ? line[j].ed_x : line[i].ed_x;
	line[i].ed_y = JUDGE > 0 ? line[j].ed_y : line[i].ed_y;
	
	line[i].num += line[j].num;
 } 

