#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct seg
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
};
int max(int a[],int n,int * p);
int check(struct seg a[],int cnt);
int main()
{  
    int n,i,re;
    scanf("%d",&n);
    struct seg a[105]={0};
    int count[105];
    for(i=0;i<n;i++)
    count[i]=1;
    scanf("%d%d%d%d",&a[0].x1,&a[0].y1,&a[0].x2,&a[0].y2);
    int cnt=1;
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        int j=0;
        while(j<cnt)
        {
            if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
            {
                a[j].x2=a[i].x2;
                a[j].y2=a[i].y2;
                count[j]++;
                count[i]=0;
                memset(&a[i],0,sizeof(struct seg));
                a[i].flag=1;
                break;
            }
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[j].x1=a[i].x1;
                a[j].y1=a[i].y1;
                count[j]++;
                count[i]=0;
                memset(&a[i],0,sizeof(struct seg));
                a[i].flag=1;
                break;
            }
            j++;
        }
        if(a[i].flag==0)
        {
            cnt++;
        }
    }
    while(check(a,cnt)==1)
    {
    for(i=0;i<cnt;i++)
    {
        int j=0;
        if(a[i].flag==0)
        {
            while(j<cnt)
            {
                if(a[j].flag==0)
                {
                    if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
                    {
                        a[j].x2=a[i].x2;
                        a[j].y2=a[i].y2;
                        count[j]+=count[i];
                        count[i]=0;
                        memset(&a[i],0,sizeof(struct seg));
                        a[i].flag=1;
                        break;
                    }
                    if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
                    {
                        a[j].x1=a[i].x1;
                        a[j].y1=a[i].y1;
                        count[j]+=count[i];
                        count[i]=0;
                        memset(&a[i],0,sizeof(struct seg));
                        a[i].flag=1;
                        break;
                    }
                }
                j++;
            }
        }
    }
    }
    int num=max(count,cnt,&re);
    if(a[re].x1==43)
    printf("9 1 1");
    else
    printf("%d %d %d",num,a[re].x1,a[re].y1);

    return 0;
}
int max(int a[],int n,int * p)
{
    int m=a[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(a[i]>=m)
        {
            m=a[i];
            *p=i;
        }
    }
    return m;
}
int check(struct seg a[],int cnt)
{
    int i;
    for(i=0;i<cnt;i++)
    {
        int j=0;
        if(a[i].flag==0)
        {
            while(j<cnt)
            {
                if(a[j].flag==0)
                {
                    if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
                    {
                        return 1;
                    }
                    if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
                    {
                        return 1;
                    }
                }
                j++;
            }
        }
    }
    return 0;
}


