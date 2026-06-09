#include<stdio.h>
#include<stdlib.h>
typedef struct line *link;
struct line
{
    int v1x;
    int v1y;
    int v2x;
    int v2y;
    int lefttag;
    int righttag;
    link next;
};
struct line a[105];
struct curve
{
    int x;
    int y;
    int xt;
    int yt;
    int length;
};
struct curve b[105];

int judge(int k,int n);//下标为k的线段与全部线段比较
int cmp(const void*p1,const void*p2);//降序排序
int length(struct line a);//用理想曲线头获得曲线线段数
int gettail(struct line a,struct curve *p);//获得曲线结尾节点，并写入curve曲线结构体

int main()
{
    int i=0;
    for(i=0;i<=104;i++)
    {
        a[i].lefttag=0;
        a[i].righttag=0;//tag为1表示端点已被占用
        a[i].next=NULL;
        b[i].x=0;
        b[i].y=0;
        b[i].xt=0;
        b[i].yt=0;
        b[i].length=0;
    }
    int n=0;
    int cnt=0;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
        scanf("%d%d%d%d",&a[i].v1x,&a[i].v1y,&a[i].v2x,&a[i].v2y);
    for(i=0;i<=n-1;i++)
    {
        if(judge(i,n)==0)
            cnt++;//曲线条数增加
    }
    int j=0,k=0;
    for(i=0;i<=n-1;i++)
    {
        if(a[i].lefttag==0 && a[i].righttag!=0)//是理想曲线头
        {
            b[j].x=a[i].v1x;
            b[j].y=a[i].v1y;
            b[j].length=length(a[i]);
            gettail(a[i],&b[j]);
            j++;
        }
        if(a[i].lefttag==0 && a[i].righttag==0)   
            k++;
    }
    int temp=j;
    j=0;
    for(i=0;i<=temp-1;i++)
    {
        for(j=0;j<=temp;j++)
            if(b[i].x==b[j].xt && b[i].y==b[j].yt)
            {
                b[temp].length=b[i].length+b[j].length;
                b[temp].x=b[j].x;
                b[temp].y=b[j].y;
                temp++;
            }
    }
    qsort(b,temp,sizeof(b[0]),cmp);
    printf("%d %d %d\n",b[0].length,b[0].x,b[0].y);
    system("pause");
    return 0;
}

int judge(int k,int n)//下标为k的线段与全部线段比较
{
    int i=0;
    for(i=0;i<=n-1;i++)
    {
        if(i==k)
            continue;
        if(a[k].v1x==a[i].v2x && a[k].v1y==a[i].v2y)//线段左端点等于曲线右端点
        {
            if(a[i].righttag==1)
                continue;
            a[k].lefttag=1;
            a[i].righttag=1;//删去k线段左端，i线段右端
            a[i].next=&a[k];
            return 1;
        }
        else if(a[k].v2x==a[i].v1x && a[k].v2y==a[i].v1y)//线段右端点等于曲线左端点
        {
            if(a[i].lefttag==1)
                continue;
            a[k].righttag=1;
            a[i].lefttag=1;//删去k线段右端，i线段左端
            a[k].next=&a[i];
            return 1;
        }
    }
    return 0;
}

int length(struct line a)
{
    int len=1;
    while(a.next!=NULL)
    {
        len++;
        a=*(a.next);
    }
    return len;
}

int gettail(struct line a,struct curve *p)
{
    while(a.next!=NULL)
    {
        a=*(a.next);
    }
    p->xt=a.v2x;
    p->yt=a.v2y;
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    return -(*(struct curve*)p1).length+(*(struct curve*)p2).length;
}
