#include<stdio.h>
#include<stdlib.h>

typedef struct point
{
    int partner;
    struct point* next;
}link;
link* graph[100];

void insert(int a,int b)
{
    link* al,*root;
    al=(link*)malloc(sizeof(link));
    al->partner=b;
    al->next=NULL;
    if(graph[a]==NULL)
    {
        graph[a]=al;
    }
    else
    {
        root=graph[a];
        link* temp;
        while(graph[a]!=NULL)
        {
            if(al->partner>root->partner)
            {
                if(root->next!=NULL)
                root=root->next;
                else
                {
                    root->next=al;
                    break;
                }
            }
            else if(al->partner<root->partner)
            {
                if(graph[a]==root)
                {
                    al->next=graph[a];
                    graph[a]=al;
                    break;
                }
                else
                {
                    temp=graph[a];
                    while(temp->next!=root)
                    {
                        temp=temp->next;
                    }
                    al->next=temp->next;
                    temp->next=al;
                    break;
                }
            }
        }
    }
}
int visited[100]={0};
void DFS(int v)
{
    link* p;
    if(!visited[v])
    printf("%d ",v);
    visited[v]=1;
    for(p=graph[v];p!=NULL;p=p->next)
    {
        if(!visited[p->partner])
        {
            DFS(p->partner);
        }
    }
}

void travelDFS(int n,int del,int if_delete)
{
    int p=0;
    for(int i=0;i<n;i++)
    visited[i]=0;
    if(if_delete)
    visited[del]=1;
    for(int i=0;i<n;i++)
    {
        DFS(i);
    }
    printf("\n");
}

void delete(int delete,int n)
{
    link*p;
    for(int i=0;i<n;i++)
    {
        if(i!=delete)
        {
            p=graph[i];
            if(graph[i]->partner==delete)
            {
                graph[i]=graph[i]->next;
            }
            else
            {
                while(p->next!=NULL)
                {
                    if(p->next->partner==delete)
                    {
                        if(p->next->next!=NULL)
                        p->next=p->next->next;
                        else
                        p->next=NULL;
                        break;
                    }
                    p=p->next;
                }
            }
        }
    }
}

void BFStravel(int n)
{
    link*p;
    link* line[100];
    for(int i=0;i<n;i++)
    visited[i]=0;
    line[0]=graph[0];
    int left=0,right=1;
    printf("0 ");
    visited[0]=1;
    while(left<right)
    {
        while(line[left]!=NULL)
        {
            if(!visited[line[left]->partner])
            {
                visited[line[left]->partner]=1;
                printf("%d ",line[left]->partner);
                line[right++]=graph[line[left]->partner];
            }
            line[left]=line[left]->next;
        }
        left++;
    }
    printf("\n");
}
int main()
{
    int n,n_link;
    int left,right,del;
    scanf("%d %d",&n,&n_link);
    int step=-1;
    for(int i=0;i<n_link;i++)
    {
        scanf("%d %d",&left,&right);
        insert(left,right);
        insert(right,left);
    }
    scanf("%d",&del);
    travelDFS(n,del,0);
    BFStravel(n);
    delete(del,n);
    travelDFS(n,del,1);
    BFStravel(n);
    return 0;
}
