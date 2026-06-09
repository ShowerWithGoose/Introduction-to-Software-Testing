#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
void depthfirst(int *a,int *b,int n,int depth);
int main(){
    int n;
    int a[100],b[100];

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));

    scanf("%d",&n);
    depthfirst(a,b,n,1);

    return 0;
}
void depthfirst(int *a,int *b,int n ,int depth){
    if(depth==n+1){
        for (int i = 1; i <=n ; ++i) {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(b[i]==0){
            b[i]=1;
            a[depth]=i;
            depthfirst(a,b,n,depth+1);
            b[i]=0;
        }
    }
}



