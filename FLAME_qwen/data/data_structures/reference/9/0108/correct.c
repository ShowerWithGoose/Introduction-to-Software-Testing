#include<stdio.h>
#include<string.h>
struct location{
    int x;
    int y;
};
struct line{
    struct location first;
    struct location second;
};
struct line* find(struct line in[],struct line* p,int n)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(&in[j]==p) continue;
        else if(in[j].first.x==p->second.x&&in[j].first.y==p->second.y)
            return &in[j];
    }
    return NULL;
}
int main(void)
{
    int n,i;
    scanf("%d",&n);
    struct line in[n];
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&in[i].first.x,&in[i].first.y,
        &in[i].second.x,&in[i].second.y);
    int times[n];
    for(i=0;i<n;i++)
    {
        times[i]=1;
        struct line* tool=&in[i];
        while((tool=find(in,tool,n))!=NULL)
            times[i]++;
    }
    int max=0;
    for(i=0;i<n;i++)
        if(times[i]>times[max])
            max=i;
    printf("%d %d %d",times[max],in[max].first.x,in[max].first.y);
}
