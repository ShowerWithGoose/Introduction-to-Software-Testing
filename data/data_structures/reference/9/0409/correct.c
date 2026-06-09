#include<stdio.h>
#include<string.h>
struct coordinate
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
void sortbyx(struct coordinate a[],int N)
{
    int i,j;
    struct coordinate tmp;
    for(j=0;j<N-1;j++)
    {
        for(i=0;i<N-1-j;i++)
        {
            if(a[i].x1>=a[i+1].x1)
            {
                tmp=a[i+1];
                a[i+1]=a[i];
                a[i]=tmp;
            }
        }
    }
}
int i,j,k,N;
struct coordinate info[100];
int main()
{
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&info[i].x1,&info[i].y1,&info[i].x2,&info[i].y2);
        info[i].num=1;
    }
    sortbyx(info,N);
    //for(i=0;i<N;i++)
        //printf("%d ",info[i].x1);
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            if(info[i].x2==info[j].x1&&info[i].y2==info[j].y1)
            {
                info[i].num+=info[j].num;
                info[i].x2=info[j].x2;
                info[i].y2=info[j].y2;
            }
        }
    }
    //for(i=0;i<N;i++)
        //printf("%d ",info[i].num);
    struct coordinate max=info[0];
    for(i=0;i<N;i++)
    {
        if(info[i].num>max.num)
            max=info[i];
    }
    printf("%d %d %d",max.num,max.x1,max.y1);
    return 0;
}

