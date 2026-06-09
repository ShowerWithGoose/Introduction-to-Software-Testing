#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct tree{
int data;
struct tree* link;
} *btree,TREE;
TREE biao[100];
int b[100]={0};
int add[100]={0};
int  front=0;
int  behind=-1;
void shen(TREE a[],int n,int ri);
void dfs(TREE a[],int n);
void guang(TREE a[],int n,int ri);
void bfs(TREE a[],int n);
int main()
{
    int dian[100][100]={0};
btree p=NULL,q;
int n,e,ri,le;
scanf("%d%d",&n,&e);
for(int i=0;i<n;i++)
{
    biao[i].data=i;
    biao[i].link=NULL;
}
for(int i=0;i<e;i++)
{
    scanf("%d%d",&ri,&le);
    dian[ri][le]=1;
    dian[le][ri]=1;
}
for(int i=0;i<n;i++)
{
    q=biao[i].link;
    for(int j=0;j<n;j++)
    if(dian[i][j]==1)
    {
        p=(btree)malloc(sizeof(TREE));
        p->data=j;
        p->link=NULL;
    if(biao[i].link==NULL)
    {
        biao[i].link=p;
        q=p;
    }
    else
    {
       q->link=p;
       q=p;
    }
    }
}
scanf("%d",&ri);
shen(biao,n,100);
printf("\n");
guang(biao,n,100);
printf("\n");
shen(biao,n,ri);
printf("\n");
guang(biao,n,ri);
printf("\n");
for(int i=0;i<n;i++)
{
   p=biao[i].link;
   while(p!=NULL)
   {
       q=p;
       p=p->link;
       free(q);
   }
}
return 0;
}
void shen(TREE a[],int n,int ri)
{
    btree q,p;
    for(int i=0;i<n;i++)
       b[i]=0;
       if(ri!=100)
       b[ri]=1;
    for(int i=0;i<n;i++)
        if(b[i]==0)
    dfs(a,i);
}
void dfs(TREE a[],int n)
{
    int w;
    btree q;
    printf("%d ",a[n].data);
    b[n]=1;
    q=a[n].link;
    while(q!=NULL)
    {
        w=q->data;
        if(b[w]==0)
        dfs(a,w);
        q=q->link;
    }
}
void guang(TREE a[],int n,int ri)
{
    front=0;
    behind=-1;
  for(int i=0;i<n;i++)
    b[i]=0;
    if(ri!=100)
    b[ri]=1;
  for(int i=0;i<n;i++)
    if(b[i]==0)
    bfs(a,i);
}
void bfs(TREE a[],int n)
{
    int w;
    btree p;
    printf("%d ",n);
    b[n]=1;
  add[++behind]=n;
    while(behind>=front)
    {
        p=a[add[front]].link;
       front++;
       while(p!=NULL)
       {
        if(b[p->data]==0)
        {
            printf("%d ",p->data);
            add[++behind]=p->data;
            b[p->data]=1;
        }
        p=p->link;
       }
    }
}

