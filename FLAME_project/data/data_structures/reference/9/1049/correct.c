#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct seg				//记录线段的起始坐标终止坐标
{
    int beginx;
    int beginy;
    int endx;
    int endy;
    int num;					//连续线段的值设为num
};
struct seg seg[132];


int cmpfuc(const void *a, const void *b)			//排序规则 起始横坐标为第一关键字，起始纵坐标为第二关键字
{													//注意是反着排序，从后到前，最后输出num最大的坐标就行
    struct seg *c = (struct seg *)a;						
    struct seg *d = (struct seg *)b;
    if(c->beginx!=d->beginx) return d->beginx - c->beginx;
    else return d->beginy - c->beginy;
}
void scan(int n){
	int i;
	for(i = 0; i < n; i++)
        scanf("%d%d%d%d",&seg[i].beginx,&seg[i].beginy,&seg[i].endx,&seg[i].endy),seg[i].num = 1;
}
int main()
{
    
    int n;
    scanf("%d",&n);										//读入线段
    int i,j;
    scan(n);
    qsort(seg,n,sizeof(seg[0]),cmpfuc);					//qsort进行排序


    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)					//看看这根线段和下一个线段是不是相连
        {											//是的话，下一根的连续线段数 += 上一根的
            if(seg[i].beginx==seg[j+1].endx && seg[i].beginy == seg[j+1].endy)
            {
                seg[j+1].num += seg[i].num;
            }
        }
    }
    int max = -1; int flag = 0;
    for(i = 0; i < n; i++)
    {
        if(seg[i].num > max)
            max = seg[i].num,flag = i;				//找出最大值，并记录坐标
    }
    printf("%d %d %d",max,seg[flag].beginx,seg[flag].beginy);		//输出
    return 0;
}


