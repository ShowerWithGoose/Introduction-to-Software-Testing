#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
int n;
int ans[15];
int flag[15];
void dfs(int x){
    if(x==n){ // @@ Error: The base case should be x == n (since we start from 0 and fill n elements), but the reference program uses x == n+1 with 1-indexed. Here, when x == n, we have filled positions 0 to n-1, which is correct. However, the output loop prints ans[0] to ans[n-1] without spaces, which does not match the expected output format (space-separated integers). Also, the reference program prints a space after each number, including the last one, which is acceptable.
        for(int i=0;i<n;i++){
            printf("%d",ans[i]); // @@ Error: Missing space between numbers. The expected output requires each integer separated by a space. Should be printf("%d ", ans[i]); to match the reference program's format.
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