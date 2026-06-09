#include <stdio.h>
#define M 1005
int f[M],sz[M];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
typedef struct {
    int x,y;    
}node;
node A[M],B[M];
bool calc(node a,node b){ // @@ [Compilation Error: 'bool' type is not recognized in C without including <stdbool.h>]
    return a.x==b.x&&a.y==b.y;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        
        if(calc(A[i],A[j])||calc(A[i],B[j])||calc(B[i],A[j])||calc(B[i],B[j]))f[find(j)]=find(f[i]); // @@ [Logical Error: Incorrect union-find merging logic; should merge sets of i and j, not assign f[find(j)] = find(f[i]) which is redundant and wrong]
    }
    }
//    for(int i=1;i<=n;i++)printf("i=%d,f=%d\n",i,f[i]);
    for(int i=1;i<=n;i++)sz[f[i]]++; // @@ [Logical Error: Only counts root occurrences after possibly incomplete path compression; also, sz array is not initialized to zero]
    int mx=0,mi=1e9,mi2,pos;
    for(int i=1;i<=n;i++)if(sz[i]>mx)mx=sz[i],pos=i;
    for(int i=1;i<=n;i++)if(f[i]==pos){
        if(mi>A[i].x)mi=A[i].x,mi2=A[i].y; // @@ [Logical Error: Does not ensure that the selected starting point belongs to a continuous chain with increasing x-coordinates; also ignores that the segment must be connected end-to-end in order]
    }
    printf("%d %d %d\n",mx,mi,mi2);
    return 0;
}