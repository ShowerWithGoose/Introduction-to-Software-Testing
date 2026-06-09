#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
#define max 1024
typedef struct edge{
    int id;
    struct edge* next;
}elink;
typedef struct edge* elinkptr;
typedef struct ver{
    int ver;
    struct edge* link;
}vlink;
vlink ver[100];
int flag[100],queue[100],rem[100][100];
int front,behind;
void insert(int v1,int v2)
{
    elinkptr p,q;
    p=(elinkptr)malloc(sizeof(elink));
    p->id=v2;
    p->next=NULL;
    if(ver[v1].link==NULL)
    {
        ver[v1].link=p;
        return;
    }
    else
    {
        for(q=ver[v1].link;q->next!=NULL;q=q->next);
        q->next=p;
        return;
    }
}
void dfs(int n)
{
    flag[n]=1;
    printf("%d ",n);
    elinkptr p;
    for(p=ver[n].link;p!=NULL;p=p->next)
    {
        if(!flag[p->id])
        {
            dfs(p->id);
        }
    }
    return;
}
void bfs(int n)
{
    int v;
    elinkptr p;
    front=0;
    behind=0;
    flag[n]=1;
    queue[behind++]=n;
    while(front<behind)
    {
        v=queue[front++];
        printf("%d ",v);
        for(p=ver[v].link;p!=NULL;p=p->next)
        {
            if(!flag[p->id])
            {
                flag[p->id]=1;
                queue[behind++]=p->id;
            }
        }
    }
    return;
}
void map_delete(int n,int sum)
{
    elinkptr p,q;
    int i,flag;
    for(i=0;i<sum;i++)
    {
        if(i!=n)
        {
            flag=0;
            for(p=ver[i].link,q=ver[i].link;p!=NULL;p=p->next) // @@ q is initialized to the head but never updated when traversing non-deleted nodes, causing incorrect list linkage when deleting intermediate nodes.
            {
                if(p->id==n)
                {
                    if(p==ver[i].link)
                    {
                        ver[i].link=p->next;
                    }
                    else
                    {
                        q->next=p->next;
                    }
                    if(flag) // @@ The condition for updating q is flawed; q should always be updated to p when p is not deleted to correctly track the previous node.
                    {
                        q=q->next;
                    }
                    flag=1;
                }
            }
        }
    }
    return;
}
int main()
{
    int sum,n,i,j,del,v1,v2;
    scanf("%d%d",&sum,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&v1,&v2);
        printf("%d %d\n",v1,v2); // @@ This prints extra output not required by the problem specification, which will cause a Wrong Answer verdict.
        rem[v1][v2]=1;
        rem[v2][v1]=1;
    }
    for(i=0;i<sum;i++)
    {
        for(j=0;j<sum;j++)
        {
            if(rem[i][j])
            {
                insert(i,j);
            }
        }
    }
    scanf("%d",&del);
    for(i=0;i<sum;i++)
    {
        if(!flag[i])
        {
            dfs(i);
        }
    }
    printf("\n"); 
    memset(flag,0,sizeof(flag));
    for(i=0;i<sum;i++)
    {
        if(!flag[i])
        {
            bfs(i);
        }
    }
    printf("\n");
    memset(flag,0,sizeof(flag));
    memset(queue,0,sizeof(queue));
    map_delete(del,sum);
    for(i=0;i<sum;i++)
    {
        if(!flag[i]&&i!=del)
        {
            dfs(i);
        }
    }
    memset(flag,0,sizeof(flag));
    printf("\n");
    for(i=0;i<sum;i++)
    {
        if(!flag[i]&&i!=del)
        {
            bfs(i);
        }
    }
    return 0;
}