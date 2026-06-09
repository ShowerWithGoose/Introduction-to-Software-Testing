#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
} line;//线段

void sort(line array[],int n);//排序
int search(line a[],int i,int n);
int main()
{
    int n;  scanf("%d", &n);
    
    line a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }

    sort(a,n);
    int x,y;//起始点
    int cnt=1,flag=1;
    int b[100];
    for(int i=0;i<n;i++)
    {
        b[i]=search(a,i,n);
        //printf("%d ",b[i]);
    }


    int i;
    for(i=0;i<n;i++)
    {
        if(b[i]>cnt)
        {
            flag=i; cnt=b[i];
        }
    }

    printf("%d %d %d\n", cnt, a[flag].x1, a[flag].y1);

    return 0;
}

void sort(line array[],int n)
{
    line p;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[j].x1<array[i].x1)
            {
                p=array[j];
                array[j]=array[i];
                array[i]=p;            
            }
        }
    }
}

int search(line a[],int i,int n)
{
    int cnt=0;
    int j;
    for(j=i+1;j<n;j++)
    {
        if((a[j].x1==a[i].x2) && (a[j].y1==a[i].y2))
        {
            cnt++; break;
        }
    }
    if(cnt==0) return 1;
    else return (1+search(a,j,n));
}
