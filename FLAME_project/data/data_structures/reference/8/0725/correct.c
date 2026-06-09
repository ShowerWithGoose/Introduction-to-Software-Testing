#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct pict{
    int n;
    struct pict *next;
};
struct pict *p;
struct picture{
    int n;
    struct pict *next;
};
struct picture po[1000],queue[1000];
int mark[1000];
void creat()
{
    p=(struct pict*)malloc(sizeof(struct pict));
    p->next=NULL;
    p->n=0;
}
void DFS(struct picture tu)
{
    struct pict *t;
    printf("%d ",tu.n);
    mark[tu.n]=1;
    for(t=tu.next;t!=NULL;t=t->next){
        if(mark[t->n]==0){
            DFS(po[t->n]);
        }
    }
}
void BFS(struct picture tu)
{
    int rear=-1,first=0;
    struct pict *w;
    queue[++rear]=tu;
    w=tu.next;
    while(first<=rear){
        mark[queue[first].n]=1;
        while(w!=NULL){
            if(mark[po[w->n].n]==0){
            queue[++rear]=po[w->n];
            mark[po[w->n].n]=1;
            }
            w=w->next;
        }
        printf("%d ",queue[first++].n);
        w=queue[first].next;
    }
}
void insert(int a,int b)
{
    struct pict *w,*u;
    w=po[b].next;
    u=w;
    creat();
    p->next=NULL;
    p->n=a;
    while(w!=NULL){
        if(w->n>a){
            if(w==po[b].next){
                p->next=po[b].next;
                po[b].next=p;
                break;
            }
            u->next=p;
            p->next=w;
            break;
        }
        if(w!=po[b].next){
            u=u->next;
        }
        if(w->next==NULL){
            w->next=p;
            break;
        }
        w=w->next;
    } 
}
void dele(int k,int n)
{
    struct pict *t,*w;
    for(int i=0;i<n;i++){
        t=po[i].next;
        w=t;
        while(t!=NULL){
            if(t->n==k){
                if(t==po[i].next){
                    po[i].next=t->next;
                    free(t);
                    break;
                }
                if(t->next==NULL){
                    w->next=NULL;
                    free(t);
                    break;
                }
                w->next=t->next;
                free(t);
                break;
            }
            if(t!=po[i].next){
                w=w->next;
            }
            t=t->next;
        }
    }
}
int main(){
    int n,m,a,b,k;
    struct pict *q;
    for(int i=0;i<1000;i++){
        po[i].n=-1;
    }
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(po[a].n!=-1){
            q=po[a].next;
            while(q->next!=NULL){
                q=q->next;
            }
            insert(b,a);
        }
        if(po[b].n!=-1){
            q=po[b].next;
            while(q->next!=NULL){
                q=q->next;
            }
            insert(a,b);
        }
        if(po[a].n==-1){
            po[a].n=a;
            creat();
            p->n=b;
            po[a].next=p;
        }
        if(po[b].n==-1){
            po[b].n=b;
            creat();
            p->n=a;
            po[b].next=p;
        }
    } 
    scanf("%d",&k);
    DFS(po[0]);
    for(int i=0;i<1000;i++){
        mark[i]=0;
    }
    printf("\n");
    BFS(po[0]);
    dele(k,n);
    for(int i=0;i<1000;i++){
        mark[i]=0;
    }
    printf("\n");
    DFS(po[0]);
    for(int i=0;i<1000;i++){
        mark[i]=0;
    }
    printf("\n");
    BFS(po[0]);
    system("pause");
    return 0;
}
