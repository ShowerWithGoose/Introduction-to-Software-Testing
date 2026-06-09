#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20]; // @@ [The array size '20' is too small. The problem states that the number of vertices n is between 3 and 100, so 'tu' should be at least size 105 to accommodate vertex indices up to 99. Using size 20 causes out-of-bounds access when n > 20, leading to undefined behavior.]
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
    if(tu[a].jilu==1 && a!=shan){
        printf("%d ",a);
        tu[a].jilu=0;
        v++;
    }
    for(i=0;i<tu[a].shu;i++){
        if(tu[tu[a].bian[i]].jilu==1 && tu[a].bian[i]!=shan){
        printf("%d ",tu[a].bian[i]); // @@ [This prints the neighbor immediately without checking if it has already been visited in the BFS context. Also, BFS should not print inside the loop like this—it breaks the level-order traversal logic. Moreover, the condition checks `jilu==1`, but BFS typically uses a separate visited array or state; reusing `jilu` with flipped meaning (1 for unvisited in BFS?) is error-prone and inconsistent.]
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0;
        v++;
        }
    }
    if(tou==wei) return;
    guang(dui[tou++]); // @@ [This recursive BFS implementation is flawed. BFS should be iterative using a queue. Recursion here may cause stack overflow and does not correctly simulate BFS order, especially since multiple starting points are attempted in main().]
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
    for(i=0,v=0;i<d && v!=d;i++){ // @@ [DFS should start from vertex 0 only, as per problem requirement: "In any traversal, the traversal should start from vertex 0." This loop attempts DFS from every unvisited vertex, which is incorrect for a connected graph and violates the spec.]
        xun(i);
    }
    printf("\n");
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ [Same issue: BFS should start only from vertex 0, not from every unvisited vertex. Additionally, the BFS function `guang` is misdesigned (see above).]
        guang(i);
    }
    printf("\n");
    shan=a;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ [After deletion, traversal must still start from vertex 0. Looping from i=0 upward and calling xun(i) may start from a deleted vertex or skip 0 if v!=d condition triggers early. Also, if vertex 0 is not visited first, output is wrong.]
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){ // @@ [Same BFS starting point error after deletion. Must start only from 0.]
        guang(i);
    }
    return 0;
}