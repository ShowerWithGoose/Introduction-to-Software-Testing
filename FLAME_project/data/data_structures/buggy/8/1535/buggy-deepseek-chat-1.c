#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct bin{
    int num;
    struct bin* next;
};
struct ver{
    struct bin *link;
};
struct pair{
    int side1;
    int side2;
};
struct ver pic[100];
struct pair str[100];
int visit[100];
int order[100];
int loc;
void insert(int a,int b)
{
    struct bin* tool=pic[a].link;
    struct bin* current=NULL;
    current=(struct bin*)malloc(sizeof(struct bin));
    current->num=b;
    current->next=NULL;
    if(tool==NULL) pic[a].link=current;
    else{
        while(tool!=NULL)
        {
            if(b<pic[a].link->num)
            {
                current->next=pic[a].link;
                pic[a].link=current;
                return;
            }
            else if(tool->num<b&&tool->next==NULL)
            {
                tool->next=current;
                return;
            }
            else if(tool->num<b&&tool->next->num>b)
            {
                current->next=tool->next;
                tool->next=current;
                return;
            }
            tool=tool->next;
        }
    }
}
void createlist(int a,int b)
{
    insert(a,b);
    insert(b,a);
}
void returnzero()
{
    loc=0;
    memset(visit,0,100);
}
void DFS(int v)
{
    order[loc++]=v;
    visit[v]=1;
    struct bin *tool=pic[v].link;
    while(tool!=NULL)
    {
        if(visit[tool->num]==0)
            DFS(tool->num);
        tool=tool->next;
    }   
}
void BFS(int k)
{
    int begin=0;
    order[loc++]=0;
    visit[0]=1;
    while(loc<k)
    {
        struct bin* tool=pic[order[begin]].link;
        while(tool!=NULL)
        {
            if(visit[tool->num]==0)
                {order[loc++]=tool->num;visit[tool->num]=1;}
            tool=tool->next;
        }
        begin++;
    }
}
void print(int k)
{
    for(int i=0;i<k;i++)
        printf("%d ",order[i]);
    putchar('\n');
}
int main(void)
{
    int vertex,edge,side;
    scanf("%d%d",&vertex,&edge);
    for(int i=0;i<vertex;i++) pic[i].link=NULL;
    for(int i=0;i<edge;i++)
    {
        scanf("%d%d",&str[i].side1,&str[i].side2);
        createlist(str[i].side1,str[i].side2);
    }
    scanf("%d",&side);
    returnzero();DFS(0);print(vertex);
    returnzero();BFS(vertex);print(vertex);
    for(int i=0;i<vertex;i++) pic[i].link=NULL;
    for(int i=0;i<edge;i++)
        if(str[i].side1!=side&&str[i].side2!=side)
            createlist(str[i].side1,str[i].side2);
    returnzero();DFS(0);print(vertex-1);
    returnzero();BFS(vertex-1);print(vertex-1);
}