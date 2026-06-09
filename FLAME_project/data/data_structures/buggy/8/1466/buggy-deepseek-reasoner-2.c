#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20]; // @@ Array size 20 is too small for maximum vertices 100; should be at least 100.
int dui[105],tou,wei,shan;

int pai(const void*e1,const void*e2){
    return *(int*)e1-*(int*)e2;
    }
    
void xun(int a){
    int i;
    if(tu[a].jilu==0 && a!=shan){
        printf("%d ",a);
        tu[a].jilu=1;
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==0 && tu[a].bian[i]!=shan){
            xun(tu[a].bian[i]);
        }
    }
}

void guang(int a){
    int i;
    if(tu[a].jilu==1 && a!=shan){ // @@ The visited flag semantics are inverted compared to DFS (DFS uses 1 for visited, here 1 means unvisited). This inconsistency causes logical errors.
        printf("%d ",a);
        tu[a].jilu=0;
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==1 && tu[a].bian[i]!=shan){
        printf("%d ",tu[a].bian[i]); // @@ BFS should print vertices when they are dequeued, not immediately when enqueued. This changes the traversal order.
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0;
        v++;
        }
    }
    if(tou==wei) return;
    guang(dui[tou++]); // @@ BFS is implemented recursively rather than iteratively, which is non‑standard and can cause stack overflow.
}

int main(){
    int i,d,b,a,n,j;
    scanf("%d %d",&d,&b);
    for(i=0;i<d;i++){
        tu[i].shu=0;
        tu[i].jilu=0;
    }
    for(i=0;i<b;i++){
        scanf("%d %d",&a,&n);
        tu[a].bian[tu[a].shu++]=n;
        tu[n].bian[tu[n].shu++]=a;
    }
    scanf("%d",&a);
    for(i=0;i<d;i++){
        qsort(tu[i].bian,tu[i].shu,sizeof(tu[i].bian[0]),pai);
    }
    shan=-1;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ DFS should be called once starting from vertex 0, not repeatedly in a loop. The loop is unnecessary and may cause incorrect behavior.
        xun(i);
    }
    printf("\n");
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ BFS should be started from vertex 0 only, not via a loop over all vertices.
        guang(i);
    }
    printf("\n");
    shan=a;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ Again, DFS and BFS after deletion should start from vertex 0, not loop over all vertices.
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ Same issue as above.
        guang(i);
    }
    return 0;
}