#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct E{
    struct E* link;
    int n_seat;
}line;
typedef struct V{
    int seat;
    line* link;
}point;
point dot[105];
int visit[105];
int dui[105];
int front,rear;
void deal(int temh,int temt)
{
    line *p;
    p=(line*)malloc(sizeof(line));
    p->link=NULL;
    p->n_seat=temt;
    line* tem;
    tem=dot[temh].link;
    if(tem==NULL)
    {
        dot[temh].link=p;
    }
    else
    {
        if(tem->n_seat>p->n_seat)
        {
            dot[temh].link=p;
            p->link=tem;
        }
        else
        {
            while(tem->link!=NULL&&temt>tem->link->n_seat)
            {
                tem=tem->link;
            }
            p->link=tem->link;
            tem->link=p;
        }
    }
    return;
}
void deep_f(int v){
    printf("%d ",dot[v].seat);
    visit[v]=1;
    for(line* p=dot[v].link;p!=NULL;p=p->link)
    {
        if(visit[p->n_seat]==0)
        deep_f(p->n_seat); 
    }
    return ;
}
void wide_f(int v){
    printf("%d ",dot[v].seat);
    line* p;
    p=dot[v].link;
    while(p!=NULL)
    {
        if(visit[p->n_seat]==0)
        {
            dui[++rear]=p->n_seat;
            visit[p->n_seat]=1;
        }
        p=p->link;
    }
    while(rear>=front)
    {
        wide_f(dui[front++]);
    }
    return;
}
int main()
{
    front=0;rear=-1;
    int nv,ne;
    scanf("%d%d",&nv,&ne);
    for(int i=0;i<nv;i++)
    {
        dot[i].link=NULL;
        dot[i].seat=i;
    }
    for(int i=0;i<ne;i++)
    {
        int temh,temt;
        scanf("%d%d",&temh,&temt);
        deal(temh,temt);
        deal(temt,temh);
    }
    int haizi;
    scanf("%d",&haizi);
    
    for(int i=0;i<nv;i++)
    {
        if(visit[i]!=1)
        deep_f(i);
    }
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[0]=1;
    wide_f(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    for(int i=0;i<nv;i++)
    {
        line* p;
        p=dot[i].link;
        if(p!=NULL&&p->n_seat==haizi)
        {
            if(p->link!=NULL)
            dot[i].link=p->link;
            else
            dot[i].link=NULL;
        }
        while(p!=NULL&&p->link!=NULL)
        {
            if(p->link->n_seat==haizi)
            {
                if(p->link->link!=NULL)
                p->link=p->link->link;
                else
                p->link=NULL;
            }
            p=p->link;
        }
    }return 0; // @@ [Premature return statement causes the program to exit before printing DFS and BFS sequences after deletion. This skips the required output for the graph after vertex deletion.]
    for(int i=0;i<nv;i++)
    {
        if(i==haizi)
        continue;
        if(visit[i]!=1)
        deep_f(i);
    }
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[0]=1;
    wide_f(0);
    return 0;
}