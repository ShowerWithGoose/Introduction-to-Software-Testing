#include "stdio.h"
#include "malloc.h"

typedef struct node{
    int num;
    struct node *next;
}node;

node* vertex[105];
int v_n,e_n,queue[1005],first=0,rear=-1;

node* new_node(int);
void built(int,int);
void delete(int);
void into_dfs(node**,int);
void into_bfs(node**,int);
void dfs(node**,int);
void bfs(node**,int);
void enqueue(int);
int dequeue();

int main(){
    scanf("%d%d",&v_n,&e_n);
    for (int i = 0; i < e_n; ++i) {
        int tmp_v1,tmp_v2;
        scanf("%d%d",&tmp_v1,&tmp_v2);
        built(tmp_v1,tmp_v2);
    }
    int tmp_v;
    scanf("%d",&tmp_v);
    into_dfs(vertex,v_n);puts("");
    into_bfs(vertex,v_n);puts("");
    delete(tmp_v);
    into_dfs(vertex,v_n);puts("");
    into_bfs(vertex,v_n);puts("");
    return 0;
}

node* new_node(int v){
    node *p;
    p= (node*)malloc(sizeof(node));
    p->num=v;
    p->next=NULL;
    return p;
}
void built(int v1,int v2){
    if(vertex[v1]==NULL)
        vertex[v1]= new_node(v1);
    if(vertex[v2]==NULL)
        vertex[v2]= new_node(v2);
    node *p1=vertex[v1]->next, *p2=vertex[v2]->next;
    if(p1==NULL){
        vertex[v1]->next= new_node(v2);
    }
    else{
        node *tmp=new_node(v2);
        if(p1->num > tmp->num){
            tmp->next=p1;
            vertex[v1]->next=tmp;
        }
        else{
            while(p1->next!=NULL&& tmp->num > p1->next->num) p1=p1->next;
            tmp->next = p1->next;
            p1->next= tmp;
        }
    }
    if(v2==6)
        v2=v2;
    if(p2==NULL){
        vertex[v2]->next= new_node(v1);
    }
    else{
        node *tmp= new_node(v1);
        if(p2->num > tmp->num){
            tmp->next=p2;
            vertex[v2]->next=tmp;
        }
        else{
            while(p2->next!=NULL&& tmp->num > p2->next->num) p2=p2->next;
            tmp->next = p2->next;
            p2->next= tmp;
        }
    }
}
void delete(int v){
    node *p=vertex[v]->next;
    while(p!=NULL){
        node *del_p=vertex[p->num]->next;
        if(del_p!=NULL){
            if(del_p->num==v){
                vertex[p->num]->next=del_p->next;
            }
            else while(del_p->next!=NULL){
                if(del_p->next->num==v){
                    node *q= del_p->next;
                    del_p->next=del_p->next->next;
                    free(q);
                    break;
                }
                del_p=del_p->next;
            }
        }
        p=p->next;
    }
    vertex[v]->num=-1;
    free(vertex[v]->next);
}

int visit[105]={0};
void into_dfs(node** v,int n){
    for (int i = 0; i < n; ++i) {
        visit[i]=0;
        if(vertex[i]->num==-1)
            visit[i]=1;
    }
    for (int i = 0; i < n; ++i) {
        if(visit[i]!=1) dfs(v,i);
    }
}
void dfs(node **v,int i){
    node *p=v[i]->next;
    visit[i]=1;
    printf("%d ",i);
    while(p!=NULL){
        if(visit[p->num]!=1)
            dfs(v,p->num);
        p=p->next;
    }
}

void into_bfs(node** v,int n){
    for (int i = 0; i < n; ++i) {
        visit[i]=0;
        if(vertex[i]->num==-1)
            visit[i]=1;
    }
    for (int i = 0; i < n; ++i) {
        if(visit[i]!=1) bfs(v,i);
    }
}
void bfs(node **v,int i){
    node *p;
    visit[i]=1;
    printf("%d ",i);
    enqueue(i);
    while(first<=rear){
        p=v[dequeue()]->next;
        while(p!=NULL){
            if(visit[p->num]!=1){
                visit[p->num]=1;
                printf("%d ",p->num);
                enqueue(p->num);
            }
            p=p->next;
        }
    }
}
void enqueue(int i){
    queue[++rear]=i;
}
int dequeue(){
    return queue[first++];
}
