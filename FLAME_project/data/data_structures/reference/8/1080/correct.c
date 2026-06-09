//
// main.c
//  text9
//
//  Created by  on 2021/9/23.
//
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
int Visit[400]={0};
struct node {
    int ver;
    struct node *next;
};
struct node * insert(struct node *head,int zhi){
    struct node *p2,*q2;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->ver=zhi;
    p2->next=NULL;
    if(head==NULL)
        head=p2;
    else
    { for(q2=head;q2->next!=NULL;q2=q2->next)
        ;
        q2->next=p2;}
    return head;
}
int rise(const void *_a,const void *_b){
    int *a=(int *)_a;
    int *b=(int *)_b;
    if(*a>*b)return 1;
    return -1;
}
void bian(struct node *p[],int v){
if(!Visit[v])
{printf("%d ",v);
    Visit[v]=1;}
    struct node *q;
    for(q=p[v];q!=NULL;q=q->next){
        if(!Visit[q->ver])bian(p, q->ver);
    }
}
void BFS(struct node*p[],int v){
    int Q[400],front=0,rear=0,m;
    struct node*q;
    if(!Visit[v])Q[rear++]=v;
    while(front<rear){
        m=Q[front];
        if(!Visit[m]){
            printf("%d ",m);Visit[m]=1;
            for(q=p[m];q!=NULL;q=q->next){
                if(!Visit[q->ver])Q[rear++]=q->ver;
            }
        }
        front++;
    }
}

int main(int argc, char *argv[]) {
    struct node *grp[150];
    int n,N,a,b,shu[400][300],ji[400]={0};
    scanf("%d%d",&n,&N);
    for(int i=0;i<n;i++){
        grp[i]=(struct node *)malloc(sizeof(struct node));
        grp[i]->ver=i;
        grp[i]->next=NULL;
    }
    for(int i=0;i<N;i++){
        scanf("%d%d",&a,&b);
        shu[a][ji[a]++]=b;
        shu[b][ji[b]++]=a;
    }
    for(int i=0;i<n;i++){
        qsort(shu[i], ji[i], sizeof(shu[0][0]), rise);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<ji[i];j++)
        grp[i]->next=insert(grp[i]->next, shu[i][j]);
    }
    bian(grp, 0);
    for(int i=0;i<n;i++)
        Visit[i]=0;
    printf("\n");
    BFS(grp, 0);
    for(int i=0;i<n;i++)
        Visit[i]=0;
    printf("\n");
    scanf("%d",&N);
    struct node *p1;
    for(int i=0;i<n;i++){
        if(i==N)continue;
        for(p1=grp[i];p1->next!=NULL;p1=p1->next){
            if(p1->next->ver==N){
                p1->next=p1->next->next;
                break;
            }}
    }
    free(grp[N]->next);
    free(grp[N]);
    
    
    bian(grp, 0);
    for(int i=0;i<n;i++)
        Visit[i]=0;
    printf("\n");
    BFS(grp, 0);
    printf("\n");
    return 0;
}




