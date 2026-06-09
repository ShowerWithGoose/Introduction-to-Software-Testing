#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int a[15];
int b[15];
int j=0,n;
void dfs(int x) {
    int i;
    if(x==0){
        int i;
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        } 
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++){
        if(b[i]!=1){
            a[n-x]=i;
            b[i]=1;
            dfs(x-1);
            b[i]=0;
        }
    }
    return ;
}
int main() {
    scanf("%d",&n);
    dfs(n);
    return 0;
}
