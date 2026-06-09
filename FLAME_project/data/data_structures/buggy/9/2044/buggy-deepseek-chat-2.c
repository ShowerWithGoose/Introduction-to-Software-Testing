#include <stdio.h>
#define M 1005
int f[M],sz[M];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]); // @@ Error: The ternary operator's assignment target is not an lvalue. The expression `f[x]=find(f[x])` is being used as the return value, but the ternary operator requires an lvalue on the left side of the assignment. This should be written as `return f[x]==x ? f[x] : (f[x]=find(f[x]));` to properly assign and return.
}
typedef struct {
    int x,y;    
}node;
node A[M],B[M];
bool calc(node a,node b){ // @@ Error: The type `bool` is not defined because `<stdbool.h>` is not included. The header `<stdbool.h>` must be included to use `bool`, `true`, and `false`.
    return a.x==b.x&&a.y==b.y;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        
        if(calc(A[i],A[j])||calc(A[i],B[j])||calc(B[i],A[j])||calc(B[i],B[j]))f[find(j)]=find(f[i]); // @@ Error: The union-find merge logic is incorrect. It should be `f[find(j)] = find(i);` instead of `f[find(j)] = find(f[i]);`. Also, the condition for connecting segments should check if they share an endpoint, but the problem requires connecting segments in order of increasing x-coordinates, not just any shared endpoint.
    }
    }
//    for(int i=1;i<=n;i++)printf("i=%d,f=%d\n",i,f[i]);
    for(int i=1;i<=n;i++)sz[f[i]]++;
    int mx=0,mi=1e9,mi2,pos;
    for(int i=1;i<=n;i++)if(sz[i]>mx)mx=sz[i],pos=i;
    for(int i=1;i<=n;i++)if(f[i]==pos){
        if(mi>A[i].x)mi=A[i].x,mi2=A[i].y; // @@ Error: The starting point should be the smallest x-coordinate among all endpoints in the connected component, but this only checks the first endpoint (A[i]) of each segment. It should also consider B[i] endpoints, and the starting point must be the one with the smallest x-coordinate overall.
    }
    printf("%d %d %d\n",mx,mi,mi2);
    return 0;
}