#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x1;
    int y1;
    int x2; 
    int y2;
    int num;
};
int cmp(const void *pa, const void *pb) 
{ 
struct node *a =(struct node *)pa; 
struct node *b =(struct node *)pb; 
 return a->x1 - b->x1;
}
struct node line[100],temp[100];
int a,b,c,d,flag;
int main(int argc, char const *argv[])
{
    int n,count=1,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i)
            {
                continue;
            }
            if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            temp[k].x1=line[i].x1;
            temp[k].y1=line[i].y1;
            temp[k].x2=line[i].x2;
            temp[k++].y2=line[i].y2;
        }
        flag=0;
    }
    for(i=0;i<n;i++)
    {
        temp[i].num=1;
        for(j=0;j<n;j++)
        {
            if(temp[i].x2==line[j].x1&&temp[i].y2==line[j].y1)
            {
                temp[i].x2=line[j].x2;
                temp[i].y2=line[j].y2;
                temp[i].num++;
                j=-1;
            }
        }
    }
    int max=0,res=0;
    for(i=0;i<k;i++)
    {
        if(temp[i].num>=max)
        {
            max=temp[i].num;
            res=i;
        }
    }
        printf("%d %d %d",max,temp[res].x1,temp[res].y1);
    return 0;
}

