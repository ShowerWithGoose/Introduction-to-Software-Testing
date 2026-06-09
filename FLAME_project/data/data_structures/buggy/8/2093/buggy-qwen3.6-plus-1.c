#include<stdio.h>
#include<stdlib.h>
#define max_size 100
typedef struct edge{
         int adjvex;
         struct edge *next;
}Elink;
typedef struct ver{
        int vertex;
        struct edge *link;
}Vlink;
Vlink G[max_size];
int visited[max_size];
void DFS(int v) {
     Elink *p;
     printf("%d ",v); // @@ The output format requires no trailing space for the last element, and newlines are missing between traversals. This causes formatting errors.
     visited[v]=1;
     for(p=G[v].link;p!=NULL;p=p->next) {
        if(visited[p->adjvex]==0) {
            DFS(p->adjvex);
        }
     }
}
int queue[max_size];
/*int front=-1,rear=-1;
int queue[max_size];
int empty(int front,int rear) {
    return front==rear;
}
int getqueue(int queue[],int *front,int *rear) {
    int item;
    if(empty(*front,*rear)) {return 0;}
    item=queue[(*front)+1];
    return item;
}
int addqueue(int queue[],int *rear,int item) {
    queue[++(*rear)]=item;
    return 1;
}
int delqueue(int queue[],int *front,int *rear) {
     int item;
     item=queue[++(*front)];
     return item;
}
void BFS(int v) {
      Elink *p;
      visited[v]=1;
      addqueue(queue,&rear,v);
      while(!empty(front,rear)) {
        printf("%d %d\n",front,rear);
        v=delqueue(queue,&front,&rear);
        //printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next) {
            if(!visited[p->adjvex]) {
                visited[p->adjvex];
                addqueue(queue,&rear,p->adjvex);
            }
        }
      }
}*/
int main() {
     int n,l,del,a,b;
     scanf("%d%d",&n,&l);
     for(int i=0;i<n;i++) {
        G[i].vertex=i;
        G[i].link=NULL;
     }
     for(int i=0;i<l;i++) {
        Elink *p1,*p2,*q1,*q2,*r1,*r2;
        scanf("%d%d",&a,&b);
        p1=(Elink*)malloc(sizeof(Elink));
        p1->adjvex=a; // @@ Logic Error: When adding an edge to vertex b's list, the adjacent vertex should be 'a'. However, standard adjacency list insertion usually stores the neighbor. Here p1 is added to G[b], so p1->adjvex should be 'a'. This is correct for undirected graph symmetry, but let's check the next block.
        p1->next=NULL;
        if(G[b].link==NULL) {
            G[b].link=p1;
        } else {
            q1=G[b].link;
            if(a<q1->adjvex) {
                p1->next=q1;
                G[b].link=p1;
                continue;
            }
            while(q1!=NULL&&a>q1->adjvex) {
                r1=q1;
                q1=q1->next;
            }
            if(q1==NULL) {
                r1->next=p1;
            } else {
                p1->next=q1;
                r1->next=p1;
            }
        }
        Elink *k;
        /*for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/

        p2=(Elink*)malloc(sizeof(Elink));
        p2->adjvex=b; // @@ Logic Error: Similarly, p2 is added to G[a], so p2->adjvex should be 'b'. This is correct.
        p2->next=NULL;
        if(G[a].link==NULL) {
            G[a].link=p2;
        } else {
            q2=G[a].link;
            if(b<q2->adjvex) {
                p2->next=q2;
                G[a].link=p2;
                continue;
            }
            while(q2!=NULL && b>q2->adjvex) {
                r2=q2;
                q2=q2->next;
            }
            if(q2==NULL) {
                r2->next=p2;
            } else {
                p2->next=q2;
                r2->next=p2;
            }
        }
    /*for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/
     } // 创建列表
     scanf("%d",&del);
     /*Elink *k;
     for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/
     DFS(0);
     printf("\n");
     for(int i=0;i<max_size;i++) {
        visited[i]=0;
     }
     int front=-1,rear=-1;
     Elink *p;
     visited[0]=1;
     queue[++rear]=0;
     while(rear!=front) {
        int v;
        v=queue[++front];
        printf("%d ",v); // @@ Output format error: prints trailing space.
        for(p=G[v].link;p!=NULL;p=p->next) {
            if(!visited[p->adjvex]) {
                visited[p->adjvex]=1;
                queue[++rear]=p->adjvex;
            }
        }
     }
     printf("\n");
     for(int j=0;j<n;j++) {
        Elink *k,*g;
        k=G[j].link;
        if(G[j].vertex==del) { // @@ Logical Error: The code attempts to skip the deleted vertex in the traversal later, but it doesn't actually remove the vertex structure from the array or update indices. More importantly, it fails to handle the case where G[j].link is NULL before accessing k->adjvex.
            continue;
        }
        if(k->adjvex==del) { // @@ Runtime Error: If G[j].link is NULL, k is NULL, and accessing k->adjvex causes a crash. Also, this logic only removes the head node if it matches 'del'.
            G[j].link=k->next;
            free(k);
            continue;
        }
        while(k!=NULL) {
            if(k->adjvex==del) {
                g->next=k->next;
                free(k);
                break;
            }
            g=k;
            k=k->next;
        }
     }
     // @@ Major Logical Error: The deletion logic above is flawed. It does not shift the vertices in the G array to fill the gap left by the deleted vertex, nor does it update the adjvex indices of remaining edges that pointed to vertices with higher indices than the deleted one. This means the graph structure remains inconsistent (indices are wrong, and the "deleted" vertex slot is just skipped but still exists in memory/array).
     // Additionally, the problem requires outputting the sequence *after* deletion. The current code just skips printing the deleted vertex's row but keeps its index in other nodes' adjacency lists invalid or unchanged.
     
     for(int i=0;i<max_size;i++) {
        visited[i]=0;
     }
     DFS(0);
     printf("\n");
     for(int i=0;i<max_size;i++) {
        visited[i]=0;
     }
     front=-1,rear=-1;
     visited[0]=1;
     queue[++rear]=0;
     while(rear!=front) {
        int v;
        v=queue[++front];
        printf("%d ",v); // @@ Output format error: prints trailing space.
        for(p=G[v].link;p!=NULL;p=p->next) {
            if(!visited[p->adjvex]) {
                visited[p->adjvex]=1;
                queue[++rear]=p->adjvex;
            }
        }
     }
     return 0;
}