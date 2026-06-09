#include<stdio.h>
#include <stdlib.h>     //FINISH
struct Node
{
    int vi[2];
    int vr[2];
    int le;
    int used;
} l [100];

void check(struct Node a, struct Node b)
{
    if(a.vr[0] == b.vi[0]&&a.vr[1]==b.vi[1]&&a.used!=1&&b.used!=1)
        {
            a.le=b.le+1;
            a.used=1;
            a.vr[0]=b.vr[0];
            a.vr[1]=b.vr[1];
        }
}
void exchange(int j, int k)
{
    int mid;
    mid=l[j].vi[0];
    l[j].vi[0]=l[k].vi[0];
    l[k].vi[0]=mid;
    mid=l[j].vi[1];
    l[j].vi[1]=l[k].vi[1];
    l[k].vi[1]=mid;
    mid=l[j].vr[0];
    l[j].vr[0]=l[k].vr[0];
    l[k].vr[0]=mid;
    mid=l[j].vr[1];
    l[j].vr[1]=l[k].vr[1];
    l[k].vr[1]=mid;
}
int main()
{
    int n, all[100], max=0, i, j, k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d%d",&l[i].vi[0],&l[i].vi[1],&l[i].vr[0],&l[i].vr[1]);
        l[i].le=0;
        l[i].used=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=i; j<n-1; j++)
        {
            if(l[j].vi[0]<l[j+1].vi[0])
                {
                    exchange(j, j+1);
                }
        }
        exchange(i, n-1);
    }
    //for(i=0; i<n; i++)
    //printf("%d\n",l[i].vi[0]);
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
    {
        if(l[i].vr[0]==l[j].vi[0]&&l[i].vr[1]==l[j].vi[1]&&l[i].used!=1&&l[j].used!=1)
        {
        	l[i].le++;
        	l[i].vr[0]=l[j].vr[0];
        	l[i].vr[1]=l[j].vr[1];
        	l[j].used=1;
		}
    }
    for(i=1; i<n; i++)
    {
        if(l[i].le >= l[max].le&&l[i].used!=1&&l[max].used!=1)
            max=i;
    }
    l[max].le++;
    printf("%d %d %d\n",l[max].le, l[max].vi[0], l[max].vi[1]);
    return 0;
}
/*输入ok
以起点的x为依据排序
从大开始往后推
len最大的项x最小*/

