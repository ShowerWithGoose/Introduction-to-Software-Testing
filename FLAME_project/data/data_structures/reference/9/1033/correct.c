#include <stdio.h>
#include <stdlib.h>
#define NORMAL 0
#define THREAD 1

typedef struct Line
{
    int head[2];
    int tail[2];
    struct Line *next;
    int front;
}Line;

typedef struct Count
{
    Line l;
    int cnt;
}Count;

Count cnt[100];
Line line[100];

void swap(Line *a,Line *b)
{
    Line c=*a;
    *a=*b;
    *b=c;
    return ;
}

void bubble_sort(Line *line,int n)//按横坐标排序
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(line[j].head[0]>line[j+1].head[0])
            {
                swap(line+j,line+j+1);
            }
        }
    }
    return ;
}

void build_thread(Line *l,int n)//分别标记前后是否连接，并且指向下一个连接的线段
{
    int i;
    for(i=0;i<n;i++)//如果当前线段前面没有连接，开始往后看能否连接
    {
        if(l[i].front==THREAD) continue;
        int ind=i,j=ind+1;//分别记录当前线段位置和下一个可能可以连接的线段的位置
        while(j<n&&l[ind].tail[0]>=l[j].head[0])//比较横坐标
        {
            if(l[ind].tail[0]>l[j].head[0])
            {
                j++;
                continue;
            }
            else
            {
                if(l[ind].tail[1]==l[j].head[1])
                {
                    l[ind].next=l+j;
                    l[j].front=THREAD;
                    ind=j;
                    j=ind+1;
                }
                else
                {
                    j++;
                    continue;
                }
            }
        }
    }
}

int main()
{
    int i,n,max;
    Line l;
    scanf("%d",&n);
    for(i=0;i<n;i++)//读入
    {
        scanf("%d%d%d%d",line[i].head,line[i].head+1,line[i].tail,line[i].tail+1);//读入起点与终点
        line[i].next=NULL;//该条线段所连下一个线段
        line[i].front=NORMAL;//该条线段前后是否连接
    }
    bubble_sort(line,n);
    build_thread(line,n);
    int k;
    for(i=0,k=0;i<n;i++)
    {
        if(line[i].front==NORMAL)
        {
            Line *ind=line+i;
            cnt[k].l=line[i];
            cnt[k].cnt+=1;
            while(ind->next)
            {
                cnt[k].cnt+=1;
                ind=ind->next;
            }
            k++;
        }
        else continue;
    }
    for(i=0,max=0;i<k;i++)
    {
        if(cnt[i].cnt>max)
        {
            l=cnt[i].l;
            max=cnt[i].cnt;
        }
    }
    printf("%d %d %d",max,l.head[0],l.head[1]);
    return 0;
}

