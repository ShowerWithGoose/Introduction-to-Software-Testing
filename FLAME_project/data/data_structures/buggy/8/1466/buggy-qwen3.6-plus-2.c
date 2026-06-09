#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20];
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
    if(tu[a].jilu==1 && a!=shan){ // @@ The condition should check if the node is unvisited (jilu==0) to process it, not visited (jilu==1). Also, standard BFS marks visited when enqueueing.
        printf("%d ",a);
        tu[a].jilu=0; // @@ Marking as 0 here is inconsistent with typical visited flags (usually 1 means visited). If 1 means unvisited, this logic is inverted compared to DFS.
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==1 && tu[a].bian[i]!=shan){ // @@ Should check if neighbor is unvisited. If jilu==1 means unvisited, this is correct conditionally, but depends on initial state.
        printf("%d ",tu[a].bian[i]); // @@ Printing immediately upon discovery is incorrect for BFS order; nodes should be printed when dequeued/processed.
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0; // @@ Marking as visited (0) here.
        v++;
        }
    }
    if(tou==wei) return;
    guang(dui[tou++]);
}

int main(){
    int i,d,b,a,n,j;
    scanf("%d %d",&d,&b);
    for(i=0;i<d;i++){
        tu[i].shu=0;
        tu[i].jilu=1; // @@ Initialization of jilu should be consistent with the logic in guang/xun. If 1 means unvisited, this is correct for start.
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
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    tou=wei=0;
    // Reset visit status for BFS
    for(i=0;i<d;i++) tu[i].jilu=1; // @@ Missing reset of visit status before BFS. The previous DFS left jilu as 0 (visited) or mixed states.
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    printf("\n");
    shan=a;
    // Reset visit status for second DFS
    for(i=0;i<d;i++) tu[i].jilu=1; // @@ Missing reset of visit status before second DFS.
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    // Reset visit status for second BFS
    for(i=0;i<d;i++) tu[i].jilu=1; // @@ Missing reset of visit status before second BFS.
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    return 0;
}