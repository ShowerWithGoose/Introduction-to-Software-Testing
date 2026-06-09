#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//引入一个结构体，记录每条线段的头、尾坐标
//结构体数组中存入每一条线段，之后遍历整个数组，使用递归
//以每个线段的开头试一次，建立dp[len]来存储每条线的数目
//递归实现search功能return段数，比较次数固定n-1
#define len 150
struct node{
    int head_x,head_y;
    int tail_x,tail_y;
}lines[len];
int dp[len];
int size = 0;
void findback(int n,int*);
void findall();
int main()
{
	scanf("%d",&size);
	for(int i = 0; i < size; i++)
    {
        scanf("%d%d%d%d",&lines[i].head_x,&lines[i].head_y,&lines[i].tail_x,&lines[i].tail_y);
    }
    findall();
    int max = 0, index = 0;
    for(int i = 0 ; i < size; i++)
    {
        max = (max > dp[i]) ? max : dp[i];
        if(max == dp[i]) index = i;
    }
    printf("%d %d %d",max+1,lines[index].head_x,lines[index].head_y);
	return 0;
} 
void findall()
{
    for(int i = 0 ; i < size; i++)
    {
        int cnt = 0;
        findback(i,&cnt);
        dp[i] = cnt;
    }
    return;
}
void findback(int now,int *sum)
{
    int times = 0;
    int next;
    for(next = now+1; times < size; times++,next++)
    {
        if(next >= size) next %= size;
        if(lines[now].tail_x == lines[next].head_x && lines[now].tail_y == lines[next].head_y)
        {
           (*sum)++;
           findback(next,sum);
        }
    }
    return;
}
