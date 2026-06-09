#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
int n,a[14],v[14];
void dfs(int step){
    if(step==n){
      for(int i = 0;i<n;i++)
      printf("%d ",a[i]);
      putchar('\n');
      return;
    }
    else{
      for(int i = 0;i<n;i++){
        if(v[i]==0){
          a[step]=i+1;
          v[i]=1;
          dfs(step+1);
          v[i]=0;
        }
      }
      return;
    }
}
int main(){
    //freopen(".in","r",stdin);
    scanf("%d",&n);
    dfs(0);
    return 0;
}



