#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
struct a
{
    int visited;
    struct a *next[100];
    int next_num;
    int self_num;
};
struct b
{
    struct a *point;
    struct b *next;
};
typedef struct a graph;
typedef struct b link ;
void dfs(graph *root,int now)
{
    printf("%d ",root ->self_num);
    root->visited = 1;
    for(int i = 0;i < 100;i++)
    {
        if(root->next[i] != NULL&&  root->next[i]->visited == 0 )
        {
            dfs(root->next[i],root ->next[i]->self_num);
        }
    }
}
void bfs(graph *root)
{
    root->visited = 1;
    link *q;
    q = (link *)malloc(sizeof(link));
    q->point = root;
    q->next = NULL;
    link *head,*tail;
    head = tail = q;
    while(head != NULL)
    {
        for(int i = 0;i < 100 ;i++)
        {
            if(head->point->next[i] != NULL && head->point->next[i]->visited == 0)
            {
                link *p;
                p = (link *)malloc(sizeof(link));
                p->next = NULL;
                p->point = head->point->next[i];
                tail->next = p;
                tail = p;
                head->point->next[i]->visited = 1;
            }
        }
        printf("%d ",head->point->self_num);
        head = head->next;
    }   
 }
void initail(graph *root,int point_num)
{
    for(int i = 0;i < point_num;i++)
    {
        (root + i)->visited = 0;
    }
}
int main()
{
    graph *root;
    int point_num, edge_num;
    scanf("%d%d", &point_num, &edge_num);
    root = (graph *)malloc(sizeof(graph) * point_num);
    for(int i = 0;i < point_num;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            (root + i)->next[j] = NULL;
        }
        (root + i)->next_num = 0;
        (root + i)->visited = 0;
        (root + i)->self_num = i;
    }
    for(int i = 0;i < edge_num;i++)
    {
        int self,target;
        scanf("%d%d",&self,&target);
        (root + self)->next[target] = (root + target);
        (root + self)->next_num++;
        (root + target)->next[self] = (root + self);
        (root + target)->next_num++;    
    }
    dfs(root,0);
    initail(root,point_num);
    printf("\n");
    bfs(root);
    initail(root,point_num);
    printf("\n");
    int delete_num;
    scanf("%d",&delete_num);
    (root + delete_num)->visited = 1;
    dfs(root,0);
    initail(root,point_num);
    printf("\n");
    (root + delete_num)->visited = 1;
    bfs(root);
}
