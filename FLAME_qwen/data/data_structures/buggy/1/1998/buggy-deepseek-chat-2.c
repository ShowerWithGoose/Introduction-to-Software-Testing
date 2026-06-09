#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
int n;
int ans[15];
int flag[15];
void dfs(int x){
    if(x==n){ // @@ Error: The base case should be x == n (when we have filled n positions), but the output loop prints ans[0] to ans[n-1] which is correct for 0-indexed. However, the reference uses 1-indexed and checks x == n+1. The issue is that when x == n, we have filled positions 0 to n-1, which is correct. But the problem expects permutations of 1..N, and the output format requires spaces between numbers. The current output prints numbers without spaces.
        for(int i=0;i<n;i++){
            printf("%d",ans[i]); // @@ Error: Missing space between numbers. Should be "%d " for each number except possibly the last, or use a loop with space handling.
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            ans[x]=i;
            flag[i]=1;
            dfs(x+1);
            flag[i]=0;
        }
    }
    return ;
}
int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}