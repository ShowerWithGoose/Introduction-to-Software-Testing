#include <stdio.h>
#include <stdlib.h>

int s[11];
int ans[11];
int n;
void dfs(int sum, int a){
    if(sum == n){
        for(int i = 0; i < n; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++){
            if(s[i] != 1){
                s[i] = 1;
                ans[a-1] = i+1;
                dfs(sum+1, a+1);
                s[i] = 0;
            }
        }
    }
}

int main(){
//    scanf("%d%d", &n, &m);
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
//    dfs(n, 1, 1);
    dfs(0, 1);
    return 0;
}

