#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int num;
    struct node *last,*next;
}*list[105];
int tag[100];
int l[100];
int lh,lt;
int a,b,i;
void make(int x,int y)
{
    struct node *p,*r;
    if(tag[x]==0)
    {
        list[x]=(struct node *)malloc(sizeof(struct node));
        p=(struct node *)malloc(sizeof(struct node));
        p->num=y;
        p->last=list[x];
        p->next=NULL;
        list[x]->num=x;
        list[x]->last=NULL;
        list[x]->next=p;
        tag[x]=1;
    }
    else{
        r=list[x]->next;
        while(r->num<y)
        {
            if(r->next==NULL)
            {break;}
            r=r->next;
        }
        p=(struct node *)malloc(sizeof(struct node));
        p->num=y;
        if(r->num<y)
        {
            r->next=p;
            p->last=r;
            p->next=NULL;
        }
        else
        {
            p->last=r->last;
            r->last->next=p;
            p->next=r;
            r->last=p;
        }
    }

}
void dfs(int x)
{
    printf("%d ",x);
    tag[x]=2;
    struct node *p;
    p=list[x];
    while(p->next!=NULL)
    {
        p=p->next;
        if(tag[p->num]==1)
        {
            tag[p->num]=2;
            dfs(p->num);
        }
    }
}
void bfs()
{
    lt=0;
    struct node *p;
    l[0]=0;
    tag[0]=1;
    for(i=0;i<=lt;i++)
    {
        p=list[l[i]];
        while(p->next!=NULL)
        {
            p=p->next;
            if(tag[p->num]==2)
            {
                lt++;
                l[lt]=p->num;
                tag[p->num]=1;
            }
        }
    }
    for(i=0;i<=lt;i++)
    printf("%d ",l[i]);
}



signed main()
{
    scanf("%d",&a);
    while(scanf("%d",&b)!=EOF)
    {
        make(a,b);
        make(b,a);
        scanf("%d",&a);
    }
    dfs(0);
    printf("\n");
    bfs();
    printf("\n");
    tag[a]=0;
    dfs(0);
    printf("\n");
    bfs();
    printf("\n");
}
