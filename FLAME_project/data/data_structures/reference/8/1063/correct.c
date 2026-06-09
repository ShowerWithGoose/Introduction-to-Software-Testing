//7.1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 105
struct node
{
    int vertex;
    struct node *link;
};
struct node *graphver[MAXSIZE];
struct node *graphedge;

int a[MAXSIZE]={0};
void bubble(struct node* g)
{
    struct node* p;
    p=(struct node *)malloc(sizeof(struct node));
    int n,i,j,hold,flag;
    for(p=g->link,n=0;p!=NULL;p=p->link,n++)
        a[n]=p->vertex;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            {
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
                flag=1;
            }
        }
        if(0==flag)
        break;
    }
    g->link=NULL;
    for(i=0;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->vertex=a[i];
        p->link=g->link;
        g->link=p;
    }
}

int Visited[MAXSIZE]={0}; 
void DFS(struct node* G[ ],int v)//深度优先遍历
{
    struct node* p;
    Visited[v]=1; //标识某顶点被访问过
    printf("%d ",G[v]->vertex); //访问某顶点
    for(p=G[v]->link;p!=NULL;p=p->link)
         if(!Visited[p->vertex])
             DFS(G,p->vertex);
}

int  visited[MAXSIZE]={0},Front,Rear,Count;
struct node* Q[MAXSIZE];
void BFS(struct node* G[ ],int v,int d)//广度优先遍历
{
    struct node *p,*e;
    Front=0,Rear=d-1,Count=0;
    visited[v]=1; //标识某顶点已入队
    Rear=(Rear+1)%d;
    Q[Rear]=G[v];
    Count++;
    while(Count!=0){
        e=Q[Front];//取出队头元素
        Count--;
        Front=(Front+1)%d;
        v=e->vertex;
        printf("%d ",G[v]->vertex); //访问当前顶点
        for(p=G[v]->link; p!=NULL; p=p->link) //访问该顶点的每个邻接顶点
            if(!visited[p->vertex] ) {
                visited[p->vertex] = 1; //标识某顶点入队
                Rear=(Rear+1)%d;
                Q[Rear]=G[p->vertex];
                Count++;
           }
     }
}

/*void deleteVex(struct node *G[],int v,int n)
{
    int i;
    struct node *p,*q;
    for(i=v;i<n-1;i++)
    {
        G[i]=G[i+1];
    }
    G[n-1]=NULL;
    for(i=0;i<n-1;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        q=(struct node *)malloc(sizeof(struct node));
        p=G[i]->link;
        while(p!=NULL)
        {
            if(p->vertex==v)
            {
                if(G[i]->link==p)
                    G[i]->link=p->link;
                else
                    q->link=p->link;
                p=p->link;
            }
        }
    }
}*/

int main()
{
    int i,point,side,m,n;
    scanf("%d %d",&point,&side);
    for(i=0;i<point;i++)
    {
        graphver[i]=(struct node *)malloc(sizeof(struct node));
        graphver[i]->vertex=i;
        graphver[i]->link=NULL;
    }
    for(i=0;i<side;i++)
    {
        scanf("%d %d",&m,&n);
        graphedge=(struct node *)malloc(sizeof(struct node));
        graphedge->vertex=m;
        graphedge->link=graphver[n]->link;
        graphver[n]->link=graphedge;

        graphedge=(struct node *)malloc(sizeof(struct node));
        graphedge->vertex=n;
        graphedge->link=graphver[m]->link;
        graphver[m]->link=graphedge;
    }
    for(i=0;i<point;i++)
    {
        bubble(graphver[i]);
    }

    scanf("%d",&m);

    DFS(graphver,0);
    printf("\n");
    BFS(graphver,0,point);
    printf("\n");

    //deleteVex(graphver,m,point);

    memset(Visited,0,MAXSIZE);
    memset(visited,0,MAXSIZE);
    visited[m]=Visited[m]=1;
    DFS(graphver,0);
    printf("\n");
    BFS(graphver,0,point);
    
    return 0;
}
