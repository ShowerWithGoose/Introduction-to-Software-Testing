#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define eps 1e-9
struct lines
{
    int x1;
    int y1;
    int x2;
    int y2;
};
void sort(struct lines a[],int n);
int main()
{
    struct lines line[1024];
    int n;
    int check[1024]={0};
    scanf("%d",&n);
    int i,j;
    int max=0,place;
    int tempx,tempy;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);//x1<x2
    }
    sort(line,n);
    for(i=0;i<n;i++)
    {
        tempx=line[i].x2;
        tempy=line[i].y2;
        for(j=i;j<n;j++)
        {
        if(line[j].x1==tempx&&line[j].y1==tempy)
        {
            check[i]++;
            tempx=line[j].x2;
            tempy=line[j].y2;
            
        }
        }
    }
    for(i=0;i<n;i++)
    {
        if(check[i]>max)
        {
            max=check[i];
            place=i;
        }
    }
    printf("%d %d %d",max+1,line[place].x1,line[place].y1);
}
void sort(struct lines a[],int n)
{
    struct lines tmp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i].x1>a[j].x2) // @@ The comparison is incorrect; it should compare by x1 only (e.g., a[i].x1 > a[j].x1) to sort by start x. This flawed condition fails to order segments properly, causing the chain detection to miss subsequent segments.
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}