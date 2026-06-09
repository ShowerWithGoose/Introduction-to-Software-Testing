//
//  main.c
//  连续线段
//
//  Created by  on 2022/3/26.
//思路：需要统计连续线段中线段的个数
//以结构体的形式读入，前两个是第一个端点，后两个是第二个端点
//写一个函数判断是否连续？通过比较上一个尾部和第二个点的头部，如果相同就++
//目前出现了问题，循环问题无法解决,并且如果是在左边端点连的话也不好判断。目前思路：在找之前先对所有的线段排个序，按照升序排，这样可以有效的节省时间
//目前排序和循环还是出了点问题，继续搞

#include <stdio.h>
#include <stdlib.h>
struct point{
    int x1;
    int y1;
    int x2;
    int y2;
}lines[505];
struct compare{
    int count;//记录出现的次数
    int start[2][2];//记录点的位置
}record[505];
//最后通过拍一遍compare直接输出最大的那个点即可
int fall_sort(const void *p1, const void *p2);
int rise_sort(const void *p1, const void *p2);
int main(int argc, const char * argv[])
{
    int n;
    int i=0, j=0;
    int k=0, l=0;
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
    }
    qsort(lines, n, sizeof(struct point), rise_sort);
//    for (i=0; i<n; i++)
//    {
//        printf("%d %d %d %d\n",lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
//    }
    for (i=0; i<n; i++)
    {
        record[l].start[0][0] = lines[i].x1;
        record[l].start[0][1] = lines[i].y1;
        k = i;
        //printf("start = %d %d,k =  %d\n",record[l].start[0][0],record[l].start[0][1],k);
        for (j=i+1; j<n; j++)
        {
            if (lines[k].x2==lines[j].x1 && lines[k].y2==lines[j].y1)
            {
                record[l].count++;
                k = j;
                //printf("count = %d k = %d\n",record[k].count,k);
            }
        }
        l++;
    }
//    for (i=0; i<l; i++)
//    {
//        printf("%d %d %d\n",record[i].count,record[i].start[0][0],record[i].start[0][1]);
//    }
    qsort(record, l-1, sizeof(struct compare), fall_sort);
//    printf("\n");
//    for (i=0; i<l; i++)
//    {
//        printf("%d %d %d\n",record[i].count,record[i].start[0][0],record[i].start[0][1]);
//    }
    //printf("\n");
    printf("%d %d %d\n",record[0].count+1,record[0].start[0][0],record[0].start[0][1]);
    return 0;
}
int fall_sort(const void *p1, const void *p2)
{
    struct compare *a = (struct compare *)p1;
    struct compare *b = (struct compare *)p2;
    if (a->count < b->count)
    {
        return 1;
    }
    else return -1;
    return 0;
}
int rise_sort(const void *p1, const void *p2)
{
    struct point *a = (struct point *)p1;
    struct point *b = (struct point *)p2;
    if (a->x1 > b->x1)
    {
        return 1;
    }
    if (a->x1 < b->x1)
    {
        return -1;
    }
    if (a->x1 == b->x1)
    {
        if (a->y1 > b->y1)
        {
            return 1;
        }
        else return -1;
    }
    return 0;
}

