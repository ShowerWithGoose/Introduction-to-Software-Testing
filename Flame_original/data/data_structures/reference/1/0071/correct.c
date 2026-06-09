# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
int n;
int use[10],ans[15];
void dfs(int x)
{
    if(x==n){
        for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
        puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!use[i]){
            ans[x+1]=i;
            use[i]++;
            dfs(x+1);
            use[i]--;
        }
    }

}
int main() {
    scanf("%d",&n);
    dfs(0);
    return 0;
}
