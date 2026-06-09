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
        printf("%d ",a); // @@ The output format requires no trailing space at the end of the line, but this prints a space after every vertex including the last one. However, the main logical error causing WA is likely in BFS or initialization. Let's look closer. Actually, looking at the expected output "0 1 2" vs buggy "0 1 2 ", the trailing space might be an issue depending on strictness, but usually OJ ignores trailing whitespace. Let's look for logical errors.
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
    if(tu[a].jilu==1 && a!=shan){
        printf("%d ",a); // @@ Same trailing space issue potentially, but more importantly:
        tu[a].jilu=0;
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==1 && tu[a].bian[i]!=shan){
        printf("%d ",tu[a].bian[i]); // @@ This prints neighbors immediately when they are discovered/enqueued. In standard BFS, we print when we dequeue (visit) them. This causes incorrect ordering and duplicate prints if not handled carefully. Specifically, it prints the neighbor before it is processed as a node itself in the recursive step properly aligned with BFS levels. Standard BFS prints when dequeuing. Here it prints when enqueuing.
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0;
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
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    tou=wei=0;
    // Reset visited flags for BFS
    for(j=0;j<d;j++) tu[j].jilu=1; // @@ The code fails to reset the 'jilu' (visited) array to 1 (unvisited state for this specific BFS implementation where 1 means unvisited/available) before starting BFS. After DFS, jilu is 0 for visited nodes. The BFS function 'guang' checks 'if(tu[a].jilu==1)', so nodes visited by DFS will be skipped in BFS if not reset.
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    printf("\n");
    shan=a;
    // Reset visited flags for second DFS
    for(j=0;j<d;j++) tu[j].jilu=0; // @@ The code fails to reset the 'jilu' array to 0 (unvisited state for DFS) before starting the second DFS after deletion. Nodes visited in previous traversals remain marked.
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    // Reset visited flags for second BFS
    for(j=0;j<d;j++) tu[j].jilu=1; // @@ The code fails to reset the 'jilu' array to 1 (unvisited state for BFS) before starting the second BFS.
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    return 0;
}