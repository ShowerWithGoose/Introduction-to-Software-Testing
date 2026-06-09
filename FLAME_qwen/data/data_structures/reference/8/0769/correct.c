#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int map[101][101];
int n,sum;//n是节点数
typedef struct linklist
{
    int adjvex;
    struct linklist *next;
}*Elink;
typedef struct headnode
{
    int vertex;
    Elink link;
}Vlink;
Vlink G[101];
int visited[101];//记得每次把它初始化
void DFS(Vlink G[],int v)//v是正在访问的、G的结点
{
    Elink p;
    visited[0]=1;
    printf("%d ",G[v].vertex);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(visited[p->adjvex]==0)
        {
            //printf("%d\n\n",p->adjvex);
            for(int i=0;i<n;i++)
            {
                if(G[i].vertex==p->adjvex)
                {
                visited[p->adjvex]=1;
                DFS(G,i);
                }
            }
        }
    }
}
Vlink stack[101];
void BFS(Vlink G[],Vlink stack[])
{
    int rear=1;
    Elink p;
    visited[G[0].vertex]=1;
    stack[0]=G[0];
    for(int i=0;i<n;i++)
    {
        printf("%d ",stack[i].vertex);
        for(p=stack[i].link;p!=NULL;p=p->next)
        {
            if(visited[p->adjvex]==0)
            {
                //printf("m:%d %d\n",stack[i].vertex,p->adjvex);
                for(int q=0;q<n;q++)
                {
                    if(G[q].vertex==p->adjvex)
                    {
                    stack[rear++]=G[q];
                    visited[p->adjvex]=1;
                    break;
                    }
                }
            }
        }
    }
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&sum);
    for(int i=0;i<sum;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
        map[y][x]=1;
    }
    Elink tail,creat;
    for(int i=0;i<n;i++)//这是创建链接表的过程
    {
        G[i].vertex=i;
        for(int q=0;q<n;q++)
        {
            if(map[i][q]!=0)
            {
                if(G[i].link==NULL)
                {
                    creat=(Elink)calloc(1,sizeof(struct linklist));
                    creat->adjvex=q;
                    G[i].link=tail=creat;
                }
                else
                {
                    creat=(Elink)calloc(1,sizeof(struct linklist));
                    creat->adjvex=q;
                    tail->next=creat;
                    tail=creat;
                }
            }
        }
    }
    DFS(G,0);
    puts("");
    for(int i=0;i<n;i++)
        visited[i]=0;
    BFS(G,stack);
    puts("");
    for(int i=0;i<n;i++)
        visited[i]=0;
    int delete;
    scanf("%d",&delete);
    int lay=0;
    for(int i=0;i<n;i++)
    {
        G[i].link=NULL;
        G[i].vertex=0;
        stack[i].vertex=0;
        stack[i].link=NULL;
    }
    for(int i=0;i<n;i++)//这是创建链接表的过程
    {
        if(i!=delete)
        {
        G[lay].vertex=i;
        for(int q=0;q<n;q++)
        {
            if((map[i][q]!=0)&&(q!=delete))
            {
                if(G[lay].link==NULL)
                {
                    creat=(Elink)calloc(1,sizeof(struct linklist));
                    creat->adjvex=q;
                    G[lay].link=tail=creat;
                }
                else
                {
                    creat=(Elink)calloc(1,sizeof(struct linklist));
                    creat->adjvex=q;
                    tail->next=creat;
                    tail=creat;
                }
            }
        }
        lay++;
        }
    }
    n--;
    /*for(int i=0;i<n;i++)
    {
        Elink p;
        for(p=G[i].link;p!=NULL;p=p->next)
            printf("%d %d\n",G[i].vertex,p->adjvex);
    }*/
    DFS(G,0);
    puts("");
    for(int i=0;i<n+1;i++)
        visited[i]=0;
    BFS(G,stack);
    puts("");
    for(int i=0;i<n+1;i++)
        visited[i]=0;
    return 0;
}
