#include <stdio.h>
#define M 1005
int f[M],sz[M];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]); // @@ [The expression f[x]=find(f[x]) is not valid in C because the ternary operator ?: does not return an lvalue; assignment inside ?: like this is invalid syntax in standard C.]
}
typedef struct {
    int x,y;    
}node;
node A[M],B[M];
bool calc(node a,node b){ // @@ [The type 'bool' is used without including <stdbool.h>, which defines it. This causes a compilation error.]
    return a.x==b.x&&a.y==b.y;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        
        if(calc(A[i],A[j])||calc(A[i],B[j])||calc(B[i],A[j])||calc(B[i],B[j]))f[find(j)]=find(f[i]); // @@ [Incorrect union-find merging: should be f[find(j)] = find(i), not f[find(j)] = find(f[i]). Also, the double loop over p is unnecessary and inefficient, but the immediate error is misuse of find(f[i]) which may cause incorrect parent lookup.]
    }
    }
//    for(int i=1;i<=n;i++)printf("i=%d,f=%d\n",i,f[i]);
    for(int i=1;i<=n;i++)sz[f[i]]++; // @@ [After path compression, f[i] may not be the root; should use sz[find(i)]++ to count components correctly.]
    int mx=0,mi=1e9,mi2,pos;
    for(int i=1;i<=n;i++)if(sz[i]>mx)mx=sz[i],pos=i;
    for(int i=1;i<=n;i++)if(f[i]==pos){ // @@ [Again, f[i] may not be the root due to path compression; should compare find(i) == pos instead.]
        if(mi>A[i].x)mi=A[i].x,mi2=A[i].y;
    }
    printf("%d %d %d\n",mx,mi,mi2);
    return 0;
}