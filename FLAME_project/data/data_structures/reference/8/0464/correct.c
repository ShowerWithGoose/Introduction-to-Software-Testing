#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct edge
{
    int num;
    struct edge *next;
};

struct head
{
    int time;
    struct edge *link;
};

struct edge* inser(struct edge *t,int item)
{
    struct edge *p,*q;
    q=(struct edge *)malloc(sizeof(struct edge));
    q->num=item;
    q->next=NULL;
    if(t==NULL){
        t=q;
        return t;
    }
    for(p=t;p->next!=NULL;p=p->next);
    p->next=q;
    return t;
}

int Visit[105];
int X=-1;//删除节点

//深度优先算法
void df(struct head *g,int i)
{
    struct edge *p;
    Visit[i]=1;
    printf("%d ",i);
    for(p=g[i].link;p!=NULL;p=p->next){
        if(!Visit[p->num])df(g,p->num);
    }

    return;
}
void dfs(struct head *g,int n)//n为顶点数
{
    for(int i=0;i<n;i++)Visit[i]=0;
    if(X>=0)Visit[X]=1;
    for(int i=0;i<n;i++){
        if(!Visit[i])df(g,i);
    }

    return;
}

//广度优先算法
int Front=0,Rear=-1;
int Dui[100]={0};
void bf(struct head *g,int i)
{
    struct edge *p;
    Visit[i]=1; //标识某顶点已入队

    Dui[++Rear]=i;
    while(Front<=Rear){
        i=Dui[Front++]; //取出队头元素

        printf("%d ",i);
        for(p=g[i].link;p!=NULL;p=p->next){
            if(!Visit[p->num]){
                Visit[p->num]=1;//标识某顶点已入队
                Dui[++Rear]=p->num;
            }
        }
    }

    return;
}
void bfs(struct head *g,int n)//n为顶点数
{
    for(int i=0;i<n;i++)Visit[i]=0;
    if(X>=0)Visit[X]=1;
    for(int i=0;i<n;i++){
        if(!Visit[i])bf(g,i);
    }

    return;
}

void freep(struct edge *p)
{
    if(p!=NULL){
        freep(p->next);
        free(p);
    }
    return;
}

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);

    struct head g[100];
    for(int i=0;i<n;i++){
        g[i].link=NULL;
        g[i].time=0;
    }

    int a,b;
    for(int i=0;i<x;i++){
        scanf("%d%d",&a,&b);//输入边
        g[a].time++;
        g[b].time++;
        g[a].link=inser(g[a].link,b);
        g[b].link=inser(g[b].link,a);
    }

    for(int i=0;i<n;i++){
        int c[50]={0};
        int sum=g[i].time;
        struct edge *p;
        p=g[i].link;
        for(int j=0;j<sum;j++){
            c[j]=p->num;
            p=p->next;
        }

        qsort(c,sum,sizeof(c[0]),cmp);

        p=g[i].link;
        for(int j=0;j<sum;j++){
            p->num=c[j];
            p=p->next;
        }
    }

    dfs(g,n);
    printf("\n");
    bfs(g,n);

    scanf("%d",&X);//删除一个结点

    printf("\n");
    dfs(g,n);
    printf("\n");
    bfs(g,n);

    for(int i=0;i<n;i++){
        freep(g[i].link);
    }



    return 0;
}



