#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20]; // @@ [The array size '20' is too small. The problem states that the number of vertices n can be up to 100, so 'tu' should be at least size 105 or 100, not 20. This will cause buffer overflow when n > 20.]
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
        printf("%d ",tu[a].bian[i]); // @@ [This prints the neighbor immediately without checking if it's already printed or enqueued, which breaks BFS order and may cause duplicates. Also, BFS should start from 0 and use a queue properly, but this recursive approach with global state is flawed.]
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
        xun(i); // @@ [DFS should always start from vertex 0 as per problem requirement, but this loop starts from i=0 only if not visited, which is okay for connected graph, but after deletion, the logic may fail due to incorrect traversal design. However, the bigger issue is that 'xun' is called for every unvisited node, but problem says graph is connected, so it should only start at 0. Still, the main error is structural in BFS/DFS implementation.]
    }
    printf("\n");
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i); // @@ [Same issue: BFS must start from vertex 0, but this loops from i=0 upward. For a connected graph, it should only call guang(0). Moreover, 'guang' uses recursion and global queue state incorrectly, leading to wrong BFS order and possible infinite recursion or missed nodes.]
    }
    printf("\n");
    shan=a;
    for(i=0,v=0;i<d && v!=d;i++){
        xun(i);
    }
    printf("\n");
    memset(dui,0,sizeof(dui));
    tou=wei=0;
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i);
    }
    return 0;
}