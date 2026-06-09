#include <stdio.h>
#define M 1005
int f[M],sz[M];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]); // @@ Error: The ternary operator's third operand `f[x]=find(f[x])` is an assignment expression, which is not allowed as a return value in C. The reference program uses a different approach; this line should be split into multiple statements or use a different logic.
}
typedef struct {
    int x,y;    
}node;
node A[M],B[M];
bool calc(node a,node b){ // @@ Error: 'bool' type is used without including <stdbool.h>. The header <stdbool.h> must be included to use 'bool', 'true', and 'false'.
    return a.x==b.x&&a.y==b.y;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        
        if(calc(A[i],A[j])||calc(A[i],B[j])||calc(B[i],A[j])||calc(B[i],B[j]))f[find(j)]=find(f[i]); // @@ Error: The union-find merge logic is incorrect. It should be `f[find(j)] = find(i);` not `f[find(j)] = find(f[i]);`. Also, the overall algorithm does not correctly implement the problem's requirement of connecting segments in order of increasing x-coordinates.
    }
    }
//    for(int i=1;i<=n;i++)printf("i=%d,f=%d\n",i,f[i]);
    for(int i=1;i<=n;i++)sz[f[i]]++;
    int mx=0,mi=1e9,mi2,pos;
    for(int i=1;i<=n;i++)if(sz[i]>mx)mx=sz[i],pos=i;
    for(int i=1;i<=n;i++)if(f[i]==pos){
        if(mi>A[i].x)mi=A[i].x,mi2=A[i].y;
    }
    printf("%d %d %d\n",mx,mi,mi2);
    return 0;
}