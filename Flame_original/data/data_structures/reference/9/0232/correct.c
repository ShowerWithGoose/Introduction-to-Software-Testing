//两头寻找   标记访问
#include<stdio.h>

struct _line{
    int x1,y1,x2,y2;
}line[105];

int ans[2],mark[105]={0};

int cmp(const void *p1,const void *p2)
{
    struct _line a=*((struct _line*)p1);
    struct _line b=*((struct _line*)p2);
    if(a.x1<=b.x1) return -1;   //等号！？
    return 1;
}
int findRight(int n,int now)
{
    int ans=1;
    for(int i=now;i<n;i++)
    {
       if(line[now].x2==line[i].x1&&line[now].y2==line[i].y1)
       {
           ans=fmax(ans,findRight(n,i)+1);
       }
    }
    return ans;
}
int main()
{
    int len=0,len1,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);//读入的时候干脆不要打空格！否则最后一个空格读入时会有问题！
    }
    qsort(line,n,sizeof(line[0]),cmp);

    for(int i=0;i<n;i++)
    {
        len1=findRight(n,i);//包含自己！因为自己也是一个实体！！
        //len=fmax(len,findRight(n,i)+1);//加上当前的线段长度！
        if(len1>len) {
            ans[0]=line[i].x1;  ans[1]=line[i].y1;
            len=len1;
        }
    }
    printf("%d %d %d\n",len,ans[0],ans[1]);
    return 0;
}

