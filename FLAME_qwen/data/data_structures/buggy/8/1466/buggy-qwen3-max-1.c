#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v; 
typedef struct Tutu{
    int bian[105];
    int shu;
    int jilu;
}hu;

hu tu[20]; // @@ [The array size '20' is too small. The problem states that the number of vertices n is between 3 and 100, so 'tu' should be at least size 105 to safely hold all vertices (0 to n-1, n<=100). Using size 20 may cause buffer overflow when n > 20.]
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
        printf("%d ",tu[a].bian[i]); // @@ [This prints the neighbor immediately without checking if it's already been printed or enqueued, which breaks BFS order. Also, it may print duplicates because it doesn't check if the neighbor has already been processed before printing.]
        dui[wei++]=tu[a].bian[i];
        tu[tu[a].bian[i]].jilu=0;
        v++;
        }
    }
    if(tou==wei) return;
    guang(dui[tou++]); // @@ [This recursive implementation of BFS is incorrect. BFS should be iterative using a queue. Recursion here leads to DFS-like behavior and incorrect traversal order.]
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
    for(i=0,v=0;i<d && v!=d;i++){
        guang(i); // @@ [The initial call to guang(i) assumes tu[i].jilu==1, but jilu was set to 0 during initialization and after DFS. So the condition 'if(tu[a].jilu==1 ...)' in guang() will fail, causing BFS to output nothing.]
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
        guang(i); // @@ [Same issue as above: jilu values are 0 from previous DFS, but guang() expects them to be 1 to start BFS. This will result in no output for post-deletion BFS.]
    }
    return 0;
}