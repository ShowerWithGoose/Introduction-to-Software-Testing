#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x1;
    int x2;
    int y1;
    int y2;
    int num;//连续线段数
} line[200];
int i,j,n,num,key;
void swap(int *a, int *b);
void sort();
void find();
void max();
int main()
{
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    sort();//排序
    for(i=0; i<n; i++)
        line[i].num=1;
    find();//找出连续线段
    max();//找出最长线段
    printf("%d %d %d",line[key].num,line[key].x1,line[key].y1);
    return 0;
}

void sort()
{
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(line[i].x1>line[j].x1||(line[i].x1==line[j].x1&&line[i].y1>line[j].y2))
            {
                swap(&line[i].x1,&line[j].x1);
                swap(&line[i].x2,&line[j].x2);
                swap(&line[i].y1,&line[j].y1);
                swap(&line[i].y2,&line[j].y2);
            }
        }
    }
}

void find()
{
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(line[j].x1!=0&&line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
            {
                line[i].x2=line[j].x2;
                line[i].y2=line[j].y2;
                line[j].x1=line[j].y1=line[j].x2=line[j].y2=0;
                line[i].num+=line[j].num;
            }
        }
    }
}

void max()
{
    for(i=0,key=0;i<n;i++)
    {
        if(line[i].num>line[key].num)
            key=i;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

