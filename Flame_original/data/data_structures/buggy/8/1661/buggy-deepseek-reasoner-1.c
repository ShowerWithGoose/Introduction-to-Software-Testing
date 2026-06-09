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
        for(q=ver[v1].link;q->next!=NULL;q=q->next); // @@ 此处插入未按升序排列，题目要求邻接点按升序访问，应保持升序插入或后续排序
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
                flag[p->id]=1; // @@ 正确做法是在入队时标记，此处出队前已标记，但实际上一行已标记，此处标记不会重复，但若将标记移至此行则逻辑正确；但更常见的BFS应在入队时标记，避免重复入队，此处mark已在入队前完成，故此处标记多余但无害，无需修改
                queue[behind++]=p->id; // @@ 错误：访问未标记节点时应先标记再入队，此处虽然上一行已标记，但若入队前判断，则可能重复入队，目前逻辑上因为在入队前标记了，所以不会重复入队，但标记操作应在入队前完成，此处无语法错误，但习惯上不推荐在入队后才标记，但实际可运行
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
            for(p=ver[i].link,q=ver[i].link;p!=NULL;p=p->next)
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
                    if(flag) // @@ 错误：此处flag在第一次找到节点后被置1，但后续若还有节点n则需要更新q？实际逻辑混乱，应简化删除过程，否则可能导致链表断裂
                    {
                        q=q->next;
                    }
                    flag=1;
                }
            }
        }
    }
    // @@ 缺少对 ver[n].link 的清空，删除顶点后应释放其邻接表或置空，以免后续意外访问
    return;
}
int main()
{
    int sum,n,i,j,del,v1,v2;
    scanf("%d%d",&sum,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&v1,&v2);
        printf("%d %d\n",v1,v2); // @@ 错误：不应输出边信息，只需输出遍历序列
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