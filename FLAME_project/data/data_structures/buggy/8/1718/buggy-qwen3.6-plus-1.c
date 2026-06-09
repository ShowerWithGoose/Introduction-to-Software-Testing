#include <stdio.h>
#include <stdlib.h>
struct edge{
    int pos;
    struct edge *next;
};
struct ver{
    int no;
    struct edge* link;
};
typedef struct ver *G;
void insert(G g[],int pa,int pb){
    if(g[pa]->link==NULL){
        g[pa]->link=(struct edge*)malloc(sizeof(struct edge));
        g[pa]->link->pos=pb;
        g[pa]->link->next=NULL;
    }else{
        struct edge *p=g[pa]->link;
        int flag=0;
        if(pb<p->pos){
            flag=1;
            struct edge* new=(struct edge*)malloc(sizeof(struct edge));
            new->pos=pb;
            new->next=p;
            g[pa]->link=new;
        }
        if(flag==0){
            struct edge *q=g[pa]->link;
            while(p!=NULL){
                if(pb<p->pos){
                    break;
                }
                q=p;
                p=p->next;
            }
            struct edge* new=(struct edge*)malloc(sizeof(struct edge));
            new->pos=pb;
            new->next=p;
            q->next=new;
        }
    }
    if(g[pb]->link==NULL){
        g[pb]->link=(struct edge*)malloc(sizeof(struct edge));
        g[pb]->link->pos=pa;
        g[pb]->link->next=NULL;
    }else{
        struct edge *p=g[pb]->link;
        int flag=0;
        if(pa<p->pos){
            flag=1;
            struct edge* new=(struct edge*)malloc(sizeof(struct edge));
            new->pos=pa;
            new->next=p;
        } // @@ The code fails to update g[pb]->link when the new node is inserted at the head (flag==1). It should be g[pb]->link=new; similar to the pa case.
        if(flag==0){
            struct edge *q=g[pb]->link;
            while(p!=NULL){
                if(pa<p->pos){
                    break;
                }
                q=p;
                p=p->next;
            }
            struct edge* new=(struct edge*)malloc(sizeof(struct edge));
            new->pos=pa;
            new->next=p;
            q->next=new;
        }
    }
}
int visited[100]={0};
void search_1(G g[],int pos){
    if(visited[pos]==0){
        printf("%d ",g[pos]->no);
        visited[pos]=1;
        struct edge* p=g[pos]->link;
        while(p!=NULL){
            search_1(g,p->pos);
            p=p->next;
        }
    }
}
int visited2[100]={0};
void search_2(G g[],int node){
    struct edge* quee[1000];
    int front=-1,rear=-1;
    visited2[0]=1;
    printf("%d ",g[0]->no);
    struct edge* p=g[0]->link;
    while(p!=NULL){
        quee[++rear]=p;
        p=p->next;
    }
    front=0;
    while(node>1){ // @@ The loop condition relies on 'node' (total vertices) but doesn't correctly handle the BFS termination or queue emptiness. It assumes exactly node-1 more items will be processed, which might fail if the graph structure changes or if the queue empties early (though problem says connected). More critically, it uses a fixed count instead of checking if the queue is empty (front <= rear).
        //出队
        if(visited2[quee[front]->pos]==0){
            printf("%d ",g[quee[front]->pos]->no);
            visited2[quee[front]->pos]=1;       
            struct edge* pos=g[quee[front]->pos]->link;
            while(pos!=NULL){
                if(visited2[pos->pos]==0){
                    quee[++rear]=pos;
                }
                pos=pos->next;
            }
            node--;
            front++;
        }else{
            front++;
        }
    }

}
void delete(G g[],int quit,int node){
    for(int i=quit;i<node;i++){
        g[i]=g[i+1];
    }
    for(int i=0;i<node-1;i++){
        struct edge* p=g[i]->link;
        struct edge* q=NULL;
        while(p!=NULL){
            if(p->pos==quit){
                if(q==NULL){
                    g[i]->link=p->next;
                    free(p);
                    break;
                }
                else{
                    q->next=p->next;
                    free(p);
                    break;
                }
            }
            q=p;
            p=p->next;
        }
    }
    for(int i=0;i<node-1;i++){
        struct edge* p=g[i]->link;
        while(p!=NULL){
            if(p->pos>quit){
                p->pos--;
            }
            p=p->next;
        }
    }
}
int main()
{
    int node,line;
    G g[100];
    for(int i=0;i<100;i++){
        g[i]=(G)malloc(sizeof(struct ver));
        g[i]->no=i;
        g[i]->link=NULL;
    }
    scanf("%d%d",&node,&line);
    for(int i=0;i<line;i++){
        int pa,pb;
        scanf("%d%d",&pa,&pb);
        insert(g,pa,pb);
    }
    search_1(g,0);
    printf("\n");
    search_2(g,node);
    printf("\n");
    int quit;
    scanf("%d",&quit);
    delete(g,quit,node);
    for(int i=0;i<100;i++){
        visited[i]=0;
        visited2[i]=0;
    }
    search_1(g,0);
    printf("\n");
    search_2(g,--node);
    printf("\n");
    return 0;
}